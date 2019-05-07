#include "philosopher.h"
#include <iostream>
#include <vector>

using namespace std;

void philosopher_init() {

	//һ����ѧ���߳�vector
	vector<std::thread> philosophers_thread(philosopherNum);
	//һ����ѧ�Ҷ�������
	vector<philosopher> philosophers(philosopherNum);

	//��ʼ��������ѧ�ң�����������ѧ�ҷ��뵽��ѧ��������
	for (int i = 0; i < philosopherNum-1; i++) {
		philosopher philosopher_demo = philosopher(i);
		philosophers.push_back(philosopher_demo);
	}

	//��ʼ��������ѧ�ҽ��̣��������е���ѧ�ҽ��̷�����ѧ�ҽ�����������
	for (int i = 0; i < philosophers.size; i++) {
		//std::thread philosopher_thread(&philosopher::start, &philosophers[i]);
		philosophers_thread.push_back(thread(&philosopher::start, &philosophers[i]));
	}

	for (auto iter = philosophers_thread.begin(); iter != philosophers_thread.end(); ++iter) {
	}
}