#include "pcb.h"
#include <iostream>
#include <list>

const int MIN = -32767;	//���̽���֮������ȼ���int���Ա�ʾ����С����
const int MAX = 32768;

using namespace std;


int PCB::size = 0;
list<PCB*> PCB::pcb_list;

//���캯��
PCB::PCB(int time, int priority) {
	name = ++size;
	number = name;
	time_needed = time;
	priority_number = priority;
	state = 'R';
	pcb_list.push_back(this);
}
//��������
PCB::~PCB() {
	size--;
}

//��ʾ���̵���Ϣ
void PCB::disp() {
	cout << "Process" << name << "\t\t" << time_needed << "\t\t" << priority_number << "\t\t" << state << endl;
}

//�Ƚ��������̵����ȼ�f>s?
bool PCB::compare_pcb_by_priority(const PCB* f, const PCB* s) {
	return f->priority_number > s->priority_number;
}

bool PCB::compare_pcb_by_number(const PCB* f, const PCB* s) {
	return f->number > s->number;
}

bool PCB::compare_pcb_by_time_needed(const PCB* f, const PCB* s) {
	return f->time_needed < s->time_needed;
}


//���е�ǰ�Ľ���(��̬�����ȼ����ȵ����㷨)
bool PCB::run_this_by_priority() {
	bool flag = false;
	if (this->time_needed <= 0 || this->state == 'E') {
		size--;
		this->priority_number = MIN;
		this->state = 'E';
		flag = false;
	} else {
		this->priority_number--;
		this->time_needed--;
		if (this->time_needed <= 0) this->state = 'E';
		flag = true;
	}

	return flag;
}

//��ʾ���ж��е���Ϣ
void PCB::disp_list() {
	cout << "---------------------------------------------------" << endl;
	cout << "|Name\t\t" << "|Time_needed\t\t" << "|Priority_num\t\t" << "|State|" << endl;
	cout << "---------------------------------------------------" << endl;
	list <PCB*>::iterator plist;		//����һ��������
	for (plist = pcb_list.begin(); plist != pcb_list.end(); plist++) {
		PCB* pcb;
		pcb = *plist;
		pcb->disp();
	}
	cout << endl;
}

//������Ȩ���ȵ����㷨���е�ǰ���еĽ���
void PCB::PSArun() {
	disp_list();
	int i = 0;	//��ǰ���еĽ��̲�
	while (size > 0) {
		pcb_list.sort(compare_pcb_by_priority);
		PCB* pcb;
		pcb = *pcb_list.begin();
		if (!pcb->run_this_by_priority()) continue;
		cout << "Runing:Process" << pcb->name << "\tStep:" << ++i << endl;
		disp_list();
	}
}

//�����ȷ�������㷨
void PCB::FCFSrun() {
	disp_list();
	int i = 0;	//��ǰ���еĽ��̲�
	pcb_list.sort(compare_pcb_by_time_needed);
	PCB* pcb;
	for (int i = 0; i < size+1; i++) {
		pcb = *pcb_list.begin();
		pcb_list.push_back(pcb);
		pcb_list.pop_front();
		pcb->time_needed = 0;
		pcb->state = 'E';
		cout << "Runing:Process" << pcb->name << "\tStep:" << ++i << endl;
		disp_list();
	}
}

//����ҵ���ȵ����㷨
void PCB::SJFrun() {
	disp_list();
	int i = 0;	//��ǰ���еĽ��̲�
	pcb_list.sort(compare_pcb_by_time_needed);
	PCB* pcb;
	for (int i = 0; i < size; i++) {
		pcb = *pcb_list.begin();
		pcb_list.push_back(pcb);
		pcb_list.pop_front();
		pcb->time_needed = 0;
		cout << "Runing:Process" << pcb->name << "\tStep:" << ++i << endl;
		disp_list();
	}
}
