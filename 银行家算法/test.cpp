#include "bankAlgorithm.h"
#include <iostream>

using namespace std;

//��ʼ������
void init(int num);
void disp();


int main() {
	init();
}


void init(){
	bankAlgorithm demo = bankAlgorithm();

}


void disp() {
	cout << "___________________________________________________" << endl;
	cout << "|  ��Դ|   Max   | Allocation |  Need  | Available |" << endl;
	cout << "|����  |   Max   | Allocation |  Need  | Available |" << endl;
	cout << "---------------------------------------------------" << endl;
}