#ifndef _PCB_H_
#define _PCB_H_
#include <iostream>
#include <list>

using namespace std;

class PCB {
public:
	PCB(int time, int priority);	//���캯����time��������Ҫ��ʱ�䣬priority�����ȼ�
	~PCB();
	void disp();	//��ʾ��ǰ���̵���Ϣ



	bool run_this_by_priority();	//���е�ǰ�Ľ���(��̬�����ȼ����ȵ����㷨)
	bool run_this_by_number();	//���е�ǰ�Ľ���(�ȵ��ȷ�������㷨)
	bool run_this_by_time_needed();	//���е�ǰ�Ľ���(����ҵ���ȵ����㷨)
	static int size;	//�����еĽ�������
	static list<PCB*> pcb_list;	//���̶���
	static void disp_list();	//��ʾ���ж��е���Ϣ
	static bool compare_pcb_by_priority(const PCB* f, const PCB* s);	//�Ƚ��������̵����ȼ�f>s?
	static bool compare_pcb_by_number(const PCB* f, const PCB* s);	//�Ƚ��������̵����ȼ�f>s?
	static bool compare_pcb_by_time_needed(const PCB* f, const PCB* s);	//�Ƚ��������̵����ȼ�f>s?
	static void PSArun();	//���е�ǰ���̶���(��̬�����ȼ����ȵ����㷨)
	static void FCFSrun();	//���е�ǰ���̶���(�ȵ��ȷ�������㷨)
	static void SJFrun();	//���е�ǰ���̶���(����ҵ���ȵ����㷨)



private:
	int name;	//��������
	int number;	//����˳��
	int priority_number;	//�������ȼ�
	int time_needed;	//������Ҫ���е�ʱ��
	char state;	//���̵�״̬��R��������E������
	
};

#endif // !_PCB_H_
