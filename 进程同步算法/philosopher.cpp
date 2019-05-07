
/**************************************************
@brief   : ��ѧ�ҾͲ͵�ʵ���ļ���ʹ�����ַ�������������⣺1��ʹ��And���ź������ƣ�2�����ֻ��N-1����ͬʱ�Ͳ�
@author  : ���̺�
@time    : 2019/05/07 8:12
**************************************************/

#include "philosopher.h"
#include <iostream>
#include <Windows.h>
using namespace std;

philosopher::philosopher(int num) {
	this->num = num;
	this->statue = Thinking;
}

philosopher::philosopher() {
	this->statue = Thinking;
}

//�Է��Ĺ���
void philosopher::start_eat() {
	std::lock(chopsticks[num], chopsticks[(num + 1) % philosopherNum]);	//ʹ��and���ź��������������
	io_mutex.lock();
	cout << "��" << num << "����ѧ�������˿��ӣ���ʼ�Է��ˣ�" << endl;
	io_mutex.unlock();
	this->statue = Eating;
}

//���극���¿��ӿ�ʼ˼��
void philosopher::start_think() {

	chopsticks[num].unlock();
	chopsticks[(num + 1) % philosopherNum].unlock();
	io_mutex.lock();
	cout << "\t��" << num << "����ѧ�ҳ����˷��������˿��ӣ���ʼ˼��" << endl;
	io_mutex.unlock();
	this->statue = Thinking;
}


void philosopher::start() {
	int loop_num = 7 ;
	for (int i = 0; i < loop_num; i++) {
		start_eat();
		Sleep(300);
		start_think();
		Sleep(300);
	}

}



