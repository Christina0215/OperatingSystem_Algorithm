#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int PCB::size = 0;
list<PCB*> PCB::pcb_list;


int main() {
	//���̸���
	int num = 3;
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

	PCB::run();
	return 0;
}