
/**************************************************
@brief   : ���м��㷨��ʵ��
@author  : ���̺�
@time    : 2019/05/06 19:15
**************************************************/

#include "bankAlgorithm.h"
#include <iostream>
using namespace std;

bankAlgorithm::bankAlgorithm() {
	int available[resourceNum] = { 3,3,2 };
	int max[processNum][resourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
	int allocation[processNum][resourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
	int need[processNum][resourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };
}

//��Դ���뺯��
void bankAlgorithm::sendRequest() {
	cout << "��������(*��һ��������̺ţ�֮��Ϊ����ֵ*)��   " ;
	cin >> request[0] >> request[1] >> request[2] >> request[3];
	//���need����
	if (need[request[0]][0] >= request[1] && need[request[0]][1] >= request[2] && need[request[0]][2] >= request[3]) {
		//���availible����
		if (request[0] <= available[0] && request[1] <= available[1] && request[2] <= available[2]) {
			cout << "��ȫ�Լ����..." << endl;
			int oldAvailable[resourceNum];
			int oldAllocation[processNum][resourceNum];
			int oldNeed[processNum][resourceNum];
			for (int i = 0; i < resourceNum; i++) {
				//����allocation������,���ҷ�����Դ
				oldAllocation[request[0]][i] = allocation[request[0]][i];
				allocation[request[0]][i] = allocation[request[0]][i] + request[i + 1];
				//����need������,���ҷ�����Դ
				oldNeed[request[0]][i] = need[request[0]][i];
				need[request[0]][i] = need[request[0]][i] - request[i + 1];
				//����available������,���ҷ�����Դ
				oldAvailable[i] = available[i];
				available[i] = available[i] - request[i + 1];
				}
			if(!safetyCheck()){
				cout << "ϵͳ���ڲ���ȫ״̬��" << endl;
				//��ԭ
				for (int i = 0; i < resourceNum; i++) {
					allocation[request[0]][i] = oldAllocation[request[0]][i];
					need[request[0]][i] = oldNeed[request[0]][i];
					available[i] = oldAvailable[i];
				}
			} else {
				disp();
			}
		} else {
			cout << "ϵͳ�����㹻����Դ�����������" << endl;
		}
	} else {
		cout << "��������Ҫ����Դ��Ŀ�����������������ֵ" << endl;
	}



}
//��ȫ��麯��
bool bankAlgorithm::safetyCheck() {
	//��ʼ���������
	for (int i = 0; i < processNum; i++) {finish[i] = false;}
	//��ʼ����������
	for (int i = 0; i < resourceNum; i++) { work[i] = available[i]; }






}
//��ʾ����



void bankAlgorithm::disp() {
	cout << "___________________________________________________" << endl;
	cout << "|  ��Դ|   Max   | Allocation |  Need  | Available |" << endl;
	cout << "|����  |   Max   | Allocation |  Need  | Available |" << endl;
	cout << "---------------------------------------------------" << endl;
}