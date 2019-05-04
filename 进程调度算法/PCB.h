#ifndef _PCB_H_
#define _PCB_H_
#include <iostream>
#include <list>

using namespace std;

class PCB {
public:
	PCB(int time, int priority);	//���캯����time��������Ҫ��ʱ�䣬priority�����ȼ�
	~PCB();
	bool run_this();	//���е�ǰ�Ľ���
	void disp();	//��ʾ��ǰ���̵���Ϣ

	static int size;	//�����еĽ�������
	static void run();	//���е�ǰ���̶���
	static list<PCB*> pcb_list;	//���̶���
	static void disp_list();	//��ʾ���ж��е���Ϣ
	static bool compare_pcb(const PCB* f, const PCB* s);	//�Ƚ��������̵����ȼ�f>s?



private:
	int name;	//��������
	int priority_number;	//�������ȼ�
	int time_needed;	//������Ҫ���е�ʱ��
	char state;	//���̵�״̬��R��������E������
};

#endif // !_PCB_H_
