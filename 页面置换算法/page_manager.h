#ifndef PAGE_MANAGER
#define PAGE_MANAGER

struct page {
	//���
	int id;
	//����
	int visit = 0;
	//�Ƿ��޸Ĺ�
	bool alter = false;
};


struct page_frame {
	//���
	int id;
	//��Ӧҳ��
	page *page = nullptr;
};

enum missing {
	//ҳ������
	no,
	//ȱҳ�ж�
	missing_page,
	//ȱҳ�жϣ�ҳ���û�
	missing_page_and_replace
};

const int page_frame_num = 20;

class page_manager {
public:
	page_manager();
	~page_manager();
	virtual missing require_frame(const int page_id,int &frame_id,const bool alter = false) = 0;

private:
	page_frame frames[page_frame_num];
};

#endif // !PAGE_MANAGER





