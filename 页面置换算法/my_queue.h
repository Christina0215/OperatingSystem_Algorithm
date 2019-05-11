#ifndef MY_QUEUE_H
#define MY_QUEUE_H

template <typename T> 
struct queue_node {
	T date;
	queue_node<T> *next_node;
};

template<typename T> 
class my_queue {
public:
	my_queue();
	~my_queue();
	//�ж��Ƿ��ǿյ�
	bool is_empty() const;
	//��ö���ͷ�ڵ�
	T &get_head() const;
	//��ö���β�ڵ�
	T &get_tail() const;
	//���
	my_queue<T> &enqueue(const T &node);
	//����
	my_queue<T> &dequeue();
	my_queue<T> &dequeue(T &node);

private:
	queue_node<T> *head;
	queue_node<T> *tail;

};




#endif // !MY_QUEUE_H







