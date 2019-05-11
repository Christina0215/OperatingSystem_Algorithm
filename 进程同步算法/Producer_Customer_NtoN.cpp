#include "Producer_Customer_NtoN.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Producer_Customer_NtoN::Producer_Customer_NtoN() {
	int read_position = 0;
	int write_position = 0;
	int produced_counter = 0;
	int consumed_counter = 0;
}

void Producer_Customer_NtoN::producer_item(int i) {
	int item = i;
	//����
	std::unique_lock < std::mutex> lock(buffermutex_NtoN);
	//�����ߵȴ�����������������������ķ���
	while ((write_position_NtoN+1) % buffer_size_NtoN == read_position_NtoN) {
		iomutex_NtoN.lock();
		cout << ".......�����ߣ��ڵȴ��ֿ��п���ط�......." << endl;
		iomutex_NtoN.unlock();
		repo_not_full_NtoN.wait(lock);
	}
	//������������Ʒ
	buffer_NtoN[write_position_NtoN] = item;
	write_position_NtoN++;


	if (write_position_NtoN == buffer_size_NtoN) write_position_NtoN = 0;	//����������һ�����ͻص���һ����ʵ��ѭ��
	//֪ͨ�����ߡ����������ա�
	repo_not_empty_NtoN.notify_all();
	//����
	lock.unlock();
}

int Producer_Customer_NtoN::customer_item() {
	int item;
	//����
	std::unique_lock<std::mutex> lock(buffermutex_NtoN);
	//�����ߵȴ������������ա���������ķ���
	while (write_position_NtoN == read_position_NtoN) {
		iomutex_NtoN.lock();
		cout << ".......�����ߣ��ڵȴ��ֿ��в�Ʒ......." << endl;
		iomutex_NtoN.unlock();
		repo_not_empty_NtoN.wait(lock);
	}
	//���������Ѳ�Ʒ
	item = buffer_NtoN[read_position_NtoN];
	read_position_NtoN++;
	if (read_position_NtoN == buffer_size_NtoN) read_position_NtoN = 0;
	//֪ͨ�����ߡ�������������
	repo_not_full_NtoN.notify_all();
	//����
	lock.unlock();

	return item;
}

void Producer_Customer_NtoN::producer_task() {
	bool exit = false;
	while (true) {
		
		//����
		std::unique_lock<std::mutex> lock(produced_counter_mutex_NtoN);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t�����ߣ����ˣ�" << endl;
		iomutex_NtoN.unlock();
		//�ж�����
		if (produced_counter <pruduce_plan_NtoN) {
			++produced_counter;
			producer_item(produced_counter);
			iomutex_NtoN.lock();
			cout << "No." << std::this_thread::get_id() << "\t�����ߣ������˵�" << produced_counter << "����Ʒ��" << endl;
			iomutex_NtoN.unlock();
		} else {
			exit = true;
		}
		//����
		lock.unlock();
		Sleep(600);
		iomutex_NtoN.lock();
		cout << "No." << std::this_thread::get_id() << "\t�����ߣ��뿪�ˣ�" << endl;
		iomutex_NtoN.unlock();
		//�����������˳�
		if (exit) break;
	}
}

void Producer_Customer_NtoN::customer_task() {
	bool exit = false;
	while (true) {
		Sleep(3000);
		//����
		std::unique_lock<std::mutex> lock(consumed_counter_mutex_NtoN);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t�����ߣ����ˣ�" << endl;
		iomutex_NtoN.unlock();
		//�ж�����
		if (consumed_counter < pruduce_plan_NtoN) {
			int item = customer_item();
			iomutex_NtoN.lock();
			cout << "\tNo." << std::this_thread::get_id() << "\t�����ߣ������˵�" << item << "����Ʒ��" << endl;
			iomutex_NtoN.unlock();
		} else {
			exit = true;
		}
		//����
		lock.unlock();
		//Sleep(3000);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t�����ߣ��뿪�ˣ�" << endl;
		iomutex_NtoN.unlock();
		//�����������˳�
		if (exit) break;
	}
}
