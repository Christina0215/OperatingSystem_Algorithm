#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init(int num);

int main() {
	//������̸���
	int num;
	cout << "������̸�����" << endl;
	cin >> num;
	init(num);
	PCB::disp_list();


	cout << "========����ҵ���ȵ����㷨========" << endl;
	PCB::SJFrun();
	cout << "=====��̬�����ȼ����ȵ����㷨=====" << endl;
	PCB::PSArun();

	cout << "========�ȵ��ȷ�������㷨========" << endl;
	PCB::FCFSrun();
	


	return 0;
}


void init(int num) {
	//���̸���
	int time, priority;
	PCB *pcb[3];
	while (num--) {
		//������Ҫ��ʱ��
		cin >> time;
		//�������ȼ�
		cin >> priority;
		pcb[num] = new PCB(time, priority);
	}
}