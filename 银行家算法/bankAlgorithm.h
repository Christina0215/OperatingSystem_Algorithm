
/**************************************************
@brief   : ���м��㷨��ͷ�ļ�
@author  : ���̺�
@time    : 2019/05/06 19:15
**************************************************/
#ifndef BANKALGORITHM_H
#define BANKALGORITHM_H

int const processNum = 5;
int const resourceNum = 3;

class bankAlgorithm {
public:
	bankAlgorithm();//���캯��
	void sendRequest();	//��Դ���뺯��
	bool safetyCheck();	//��ȫ��麯��
	void disp();
private:

	int available[resourceNum];	//��������Դ����
	int max[processNum][resourceNum];	//����������
	int allocation[processNum][resourceNum];	//�������
	int need[processNum][resourceNum];	//�������
	int request[resourceNum+1] = {0};	//��������
	int work[resourceNum] = { 0 };	//��������
	bool finish[processNum] = {false};	//�Ƿ���ɲ�������
	int show[resourceNum * 4] = { 0 };	//	�������������

};
#endif // !BANKALGORITHM_H







