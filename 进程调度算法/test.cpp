#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int PCB::size = 0;
list<PCB*> PCB::pcb_list;




int main() {
	//������̸���
	int num;
	cout << "������̸�����" << endl;
	cin >> num;
	init(num);
	cout << "=====�����ȼ����ȵ����㷨=====" << endl;
	PCB::PSArun();
	cout << "=====�����ȼ����ȵ����㷨=====" << endl;

	return 0;
}


void init(int num) {
	//���̸���
	int time, priority;
	//	cin >> num;
	PCB* pcb[3];
	while (num--) {
		//������Ҫ��ʱ��
		cin >> time;
		//�������ȼ�
		cin >> priority;
		pcb[num] = new PCB(time, priority);
	}
}