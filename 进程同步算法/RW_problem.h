#ifndef RW_PROBLEM_H
#define RW_PROBLEM_H



#include <iostream>



using namespace std;

class RW_problem {

public:
	RW_problem();
	~RW_problem();




private:
	typedef struct {
		int id;
		int delay;	//���̳����೤ʱ���ʼ
		int last;	//���̳����೤ʱ��
	} Role;
};

#endif // !RW_PROBLEM_H





