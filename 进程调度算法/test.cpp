#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init();

int main() {
	init();
	cout << "=====��̬�����ȼ����ȵ����㷨=====" << endl;
	PCB::PSArun();
	return 0;
}


void init() {

	PCB *pcb[3];
	for (int i = 0; i < 3; i++) {
		pcb[i] = new PCB(i+4, i+5);
	}
	
}