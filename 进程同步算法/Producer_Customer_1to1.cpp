
/**************************************************
@brief   : ���������������⣨һ�������߶�һ�������ߣ�
@author  : ���̺�
@time    : 2019/05/05 11:23
**************************************************/

#include "Producer_Customer_1to1.h"
#include <iostream>
#include <Windows.h>

Producer_Customer_1to1::Producer_Customer_1to1() {
	int read_position = 0;
	int write_position = 0;
}

void Producer_Customer_1to1::producer_item(int i) {
	int item = i;
	//����
	std::unique_lock < std::mutex> lock(buffermutex);
	//�����ߵȴ�����������������������ķ���
	while ((write_position + 1) % buffer_size == read_position) {
		iomutex.lock();
		cout << "�����ߣ��ڵȴ��ֿ��п���ط�...." << endl;
		iomutex.unlock();
		rope_not_full.wait(lock);
	}
	//������������Ʒ
	buffer[write_position] = item;
	write_position++;	
	if (write_position == buffer_size) write_position = 0;	//����������һ�����ͻص���һ����ʵ��ѭ��
	//֪ͨ�����ߡ����������ա�
	rope_not_empty.notify_all();
	//����
	lock.unlock();
}

int Producer_Customer_1to1::customer_item() {
	int item;
	//����
	std::unique_lock<std::mutex> lock(buffermutex);
	//�����ߵȴ������������ա���������ķ���
	while (write_position==read_position) {
		iomutex.lock();
		cout << "�����ߣ��ڵȴ��ֿ��в�Ʒ...." << endl;
		iomutex.unlock();
		rope_not_empty.wait(lock);	
	}
	//���������Ѳ�Ʒ
	item = buffer[read_position];
	read_position++;
	if (read_position == buffer_size) read_position = 0;
	//֪ͨ�����ߡ�������������
	rope_not_full.notify_all();
	//����
	lock.unlock();

	return item;
}

void Producer_Customer_1to1::producer_task() {
	//�����߸��ݶ����producer_planѭ��������Ʒ
	for (int i = 0; i < pruduce_plan; i++) {
		Sleep(1000);
		producer_item(i);
		iomutex.lock();
		cout << "��" << i << "����Ʒ�Ѿ�������������" << endl;
		iomutex.unlock();
	}
}

void Producer_Customer_1to1::customer_task() {
	//���������Ѳ�Ʒ�������������ﵽproducer_planʱ�˳�
	while (true) {
		Sleep(5000);
		int item = customer_item();
		iomutex.lock();
		cout << "��" << item << "����Ʒ�Ѿ�����������" << endl;
		iomutex.unlock();
	}
}

