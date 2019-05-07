#include "philosopher.h"
#include <vector>


using namespace std;

//��ѧ�ҾͲͽ��̳�ʼ��
void philosopher_init();





int main() {
	philosopher_init();
}


void philosopher_init() {

	//һ����ѧ���߳�vector
	vector<std::thread> philosophers_thread;
	//һ����ѧ�Ҷ�������
	vector<philosopher> philosophers;

	//��ʼ��������ѧ�ң�����������ѧ�ҷ��뵽��ѧ��������
	for (int i = 0; i < philosopherNum - 1; i++) {
		philosopher philosopher_demo = philosopher(i+1);
		philosophers.push_back(philosopher_demo);
	}

	//��ʼ��������ѧ�ҽ��̣��������е���ѧ�ҽ��̷�����ѧ�ҽ�����������
	for (unsigned int i = 0; i < philosophers.size(); i++) {
		philosophers_thread.push_back(thread(&philosopher::start, &philosophers[i]));
	}

	//������ѧ�ҽ��̿�ʼ����
	for (unsigned int i = 0; i < philosophers.size(); i++) {
		philosophers_thread[i].join();
	}
}