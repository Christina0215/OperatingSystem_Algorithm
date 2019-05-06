#include "pcb.h"
#include <iostream>
#include <list>

const int MIN = -32767;	//���̽���֮������ȼ���int���Ա�ʾ����С����

using namespace std;

//���캯��
PCB::PCB(int time, int priority) {
	name = ++size;
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
bool PCB::compare_pcb(const PCB* f, const PCB* s) {
	return f->priority_number > s->priority_number;
}


//���е�ǰ�Ľ���
bool PCB::run_this() {
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
	int i = 0;	//��ǰ���еĽ�����
	while (size > 0) {
		pcb_list.sort(compare_pcb);
		PCB* pcb;
		pcb = *pcb_list.begin();
		if (!pcb->run_this()) continue;
		cout << "Process_num:" << size << "\tRun:Process" << pcb->name << "\tStep:" << ++i << endl;
		disp_list();
	}
}


//����Ӧ�������㷨
void PCB::HRRNrun() {

}

//�̽������ȵ����㷨
void PCB::SJFrun(){

}

//�����ȷ�������㷨
void PCB::FCFSrun() {

}
