#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 0x7ffffff

typedef struct LNode{
	int data;
	struct LNode* next;
}Lnode,LinkList;

LinkList* create_LinkList();//����һ������ 
template<class T>
Lnode* create_node(T data);//����һ���ڵ� 

template<class T>
void append(LinkList *L,T data);//ͷ�巨 
template<class T>
void push_back(LinkList *L,T data);//β�巨
template<class T>
bool insert(LinkList *L,int index, T data);//����ָ��λ�� 

Lnode* Get_index(LinkList *L,int index );//��ȡ�ڼ���Ԫ�أ���1��ʼ�±� 
template<class T>
Lnode* Get_element(LinkList *L,T data);//��ȡԪ�أ�����У����ر���Ԫ�صĽڵ㣬���򷵻ؿ�ָ�� 

template<class T>
bool Recursive_delete(LinkList *L,T data);//�ݹ�ɾ��,��Ӧ������1 
template<class T>
void delete_element(LinkList *L,T data);//ɾ��ָ���ڵ㣬��Ӧ������2 
void delete_min(LinkList *L);//ɾ����Сֵ�Ľڵ� ��Ӧ������4 



bool delete_index(LinkList *L,int index);//ɾ����i���ڵ㣬�±��1��ʼ,��ɾ���ڵ�������нڵ����������κβ����������߼��� 
void show(LinkList *L);//������� 
void reverse_show(LinkList *L);//������� --��Ӧ������3 
LinkList* reverse_Linklist(LinkList *L);//������ԭ�����ã���Ӧ������ 5  

void sort_LinkList(LinkList *L); //������������� 

int main()
{
	LinkList *L;
	L = create_LinkList();
	Lnode *temp;
	for(int i=0;i<10;i++)
	{
		push_back(L,rand()%20);
	}
	show(L);
	sort_LinkList(L);
	show(L);
	
	return 0;
} 


LinkList* create_LinkList()
{
	LinkList *L;
	L = (LinkList*)(malloc(sizeof(LinkList)));
	L->next = NULL;
	return L;
}

template<class T>
Lnode* create_node(T data)
{
	Lnode *node;
	node = (Lnode*)(malloc(sizeof(Lnode)));
	node->data = data;
	node->next = NULL;
	return node;
}


template<class T>
void append(LinkList *L,T data)//ͷ�巨 
{
	Lnode *node;
	node = create_node(data);
	node->next = L->next;
	L->next = node;
}

template<class T>
void push_back(LinkList *L,T data)//β�巨
{
	static Lnode* tail = L;//ָ��β�� 
	Lnode *move = L->next;
	while(move != NULL && tail->next != NULL){//�����ǰtailָ�벻��ָ��β�� 
		tail = move;
		move = move->next;
	}
	Lnode *node;
	node = create_node(data);
	tail->next = node;
	tail = tail->next;
} 


Lnode* Get_index(LinkList *L,int index )//��ȡ�ڼ���Ԫ�أ���1��ʼ�±� 
{
	if(index < 0){
		return NULL;
	}
	int present_index = 1;
	Lnode *move = L->next;
	while(present_index < index  && move != NULL){
		move = move->next;
		present_index++;
	}
	return move;//���ص�i���ڵ㣬���i>�ڵ������򷵻�NULL 
}

template<class T>
Lnode* Get_element(LinkList *L,T data)
{
	Lnode *move = L->next;
	while(move != NULL && move->data != data){
		move = move->next;
	}
	return move;//���Ϊ�գ���˵������������Ԫ�� 
	
}

template<class T>
bool insert(LinkList *L,int index,T data)
{
	Lnode *node = create_node(data);
	Lnode *pre = Get_index(L,index-1);
	if(pre != NULL){//���ǰ���ڵ㲻Ϊ�գ�����˵λ��С�ڱ� 
		node->next = pre->next;
		pre->next = node; 
		return true;//����ɹ������� 
	}
	return false;//���򷵻��߼��� 
}


bool delete_index(LinkList *L,int index)//ɾ����i���ڵ㣬�±��1��ʼ 
{
	if(index < 0)
		return false;
	Lnode *pre = Get_index(L,index-1);
	Lnode *temp;
	if(pre != NULL && pre->next != NULL)//�ҵ�Ҫɾ���ڵ��ǰ���ڵ㣬���ǰ���ڵ�ǿգ�����λ��iλ���ϵĽڵ�ǿգ������ɾ��
	{
		 temp = pre->next;
		 pre->next = temp->next;
		 free(temp);
		 return true;
	}
	return false;
}

template<class T>
void delete_element(LinkList *L,T data)
{
	Lnode *pre = L;
	Lnode *move = L->next;
	Lnode *temp;
	while(move != NULL){
		if(move->data == data){
			pre->next = move->next;
			temp = move;
			free(temp);
			move = pre->next;
		}
		else{
			pre = move;
			move = move->next;
		}
	}
}

void delete_min(LinkList *L)
{
	int min = MAX;
	Lnode *move = L->next,*pre = L,*pre_min;
	while(move != NULL){
		if(move->data < min){
			min = move->data;
			pre_min = pre;
		}
		else{
			pre = move;
			move = move->next;
		}
	}//�ҵ���Сֵ��ǰ���ڵ㣬����pre_min֮�� 
	move = pre_min->next;
	pre_min->next = move->next;
	free(move);
}


template<class T>
bool Recursive_delete(LinkList *L,T data)//�ݹ�ɾ�� 11 
{
	Lnode *temp;
	if( L == NULL)
		return false;
	temp = L->next;

	if( temp != NULL && temp->data == data){
		L->next = temp->next;
		L = L->next;
		free(temp);
		Recursive_delete(L,data);
	}
	else
		Recursive_delete(L->next,data);
}

void show(LinkList *L)//������� 
{
	Lnode *p = L->next;
	while( p != NULL){
		cout<<" "<<p->data;
		p = p->next;
	}
	cout<<endl;
}

void reverse_show(LinkList *L)//������� 
{
	stack<Lnode*> S;
	Lnode *move;
	move = L->next;
	while(move != NULL){
		S.push(move);//��ջ 
		move = move->next;
	}
	while( !S.empty()){ //��ջ 
		move = S.top();
		cout<<move->data<<" ";
		S.pop();//��ջ 
	}
}

LinkList* reverse_Linklist(LinkList *L)//����������   
{
	LinkList *head = create_LinkList();
	Lnode *move = L->next,*temp;
	while(move != NULL)
	{
		temp = move;
		move = move->next;//�����ܸı䣬����ָ���ֹ�Ͽ� 
		temp->next = head->next;
		head->next = temp;
	}
	return head;
}



void sort_LinkList(LinkList *L) 
{
	vector<int> s;
	int i=0;
	Lnode *move = L->next;
	while(move != NULL){
		s.push_back(move->data);
		move = move->next;
	}
	sort(s.begin(),s.end());
	move = L->next;
	while(move != NULL){
		move->data = s[i++];
		move = move->next;
	}
}












