
/**************************************************
@brief   : ���м��㷨��ʵ��
@author  : ���̺�
@time    : 2019/05/06 19:15
**************************************************/

#include "bankAlgorithm.h"
#include <iostream>
using namespace std;


bankAlgorithm::bankAlgorithm() {
}
//��Դ���뺯��
void bankAlgorithm::sendRequest() {
	cout << "��������(*��һ��������̺ţ�֮��Ϊ����ֵ*)��   " ;
	cin >> request[0] >> request[1] >> request[2] >> request[3];
	//���need����
	if (need[request[0]][0] >= request[1] && need[request[0]][1] >= request[2] && need[request[0]][2] >= request[3]) {
		//���availible����
		if (request[1] <= available[0] && request[2] <= available[1] && request[3] <= available[2]) {
			cout << "���ڿ�ʼ��ȫ�Լ����..." << endl;
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
				for (int i = 0; i < resourceNum; i++) {
					available[i] = work[i];
				}
				cout << "����ɹ�" << endl;
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
	bool key = true;	//������ת��ʱ����
	bool isFinial = false;	//�Ƿ���ɱ���
	int process = processNum-1;	//����ѭ��������
	int finishedProcess = 0;
	//��ʼ���������
	for (int i = 0; i < processNum; i++) {finish[i] = false;}
	//��ʼ����������
	for (int i = 0; i < resourceNum; i++) { work[i] = available[i]; }
	while (process >= 0) {
		//��һ�����ҵ�һ��δ�����need<work�Ľ���
		if (!finish[process]) {
			for (int i = 0; i < resourceNum; i++) {
				if (work[i] < need[process][i]) {
					key = false;
				}
			}
			//�ڶ���������״̬����Ϊtrue���ҽ����̵���Դ����work
			if (key) {
				for (int i = 0; i < resourceNum; i++) {
					work[i] = work[i] + allocation[process][i];
				}
				finish[process] = true;
				process = processNum;
			}
			key = true;
		}
		process--;
	}

	//������
	for (int i = 0; i < processNum; i++) {
		if (finish[i]) {
			finishedProcess++;
		}
	}

	if (finishedProcess == processNum) {
		isFinial = true;
		for (int i = 0; i < resourceNum; i++) {
			
		}
	}

	
	return isFinial;
}

void bankAlgorithm::disp() {
	cout << "___________________________________________________" << endl;
	cout << "|  ��Դ|   Max   | Allocation |  Need  | Available |" << endl;
	cout << "|����  |   Max   | Allocation |  Need  | Available |" << endl;
	cout << "---------------------------------------------------" << endl;
	for (int i = 0; i < processNum; i++) {
		cout << "|  " << "P" << i << "  |";
		cout << " " << max[i][0] << "  " << max[i][1] << "  " << max[i][2] << " |";
		cout << " " << allocation[i][0] << "   " << allocation[i][1] << "   " << allocation[i][2] << "  |";
		cout << "  " << need[i][0] << " " << need[i][1] << " " << need[i][2] << " |";
		if (i == 0) {
			cout << "  " << available[0] << "  " << available[1] << "  " << available[2] << "  |" << endl;
		} else {
			cout <<"           |"<< endl;
		}
	}
}