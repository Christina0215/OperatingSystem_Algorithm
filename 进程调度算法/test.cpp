#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init();

int main() {
	init();
	/*cout << "========�ȵ��ȷ�������㷨========" << endl;
	PCB::FCFSrun();
	cout << "========����ҵ���ȵ����㷨========" << endl;
	PCB::SJFrun();*/
	cout << "=====��̬�����ȼ����ȵ����㷨=====" << endl;
	PCB::PSArun();
	return 0;
}


void init() {
	//���̸���
	//int time, priority, num;
	//cout << "������̸�����" << endl;
	//cin >> num;
	PCB *pcb[3];
	for (int i = 0; i < 3; i++) {
		//cin >> time;
		//�������ȼ�
		//cin >> priority;
		pcb[i] = new PCB(i+4, i+5);
	}
	
}