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

LinkList* create_LinkList();//建立一个链表 
template<class T>
Lnode* create_node(T data);//建立一个节点 

template<class T>
void append(LinkList *L,T data);//头插法 
template<class T>
void push_back(LinkList *L,T data);//尾插法
template<class T>
bool insert(LinkList *L,int index, T data);//插入指定位置 

Lnode* Get_index(LinkList *L,int index );//获取第几个元素，从1开始下标 
template<class T>
Lnode* Get_element(LinkList *L,T data);//获取元素，如果有，返回保存元素的节点，否则返回空指针 

template<class T>
bool Recursive_delete(LinkList *L,T data);//递归删除,对应王道题1 
template<class T>
void delete_element(LinkList *L,T data);//删除指定节点，对应王道题2 
void delete_min(LinkList *L);//删除最小值的节点 对应王道题4 



bool delete_index(LinkList *L,int index);//删除第i个节点，下标从1开始,若删除节点大于现有节点数，不做任何操作，返回逻辑假 
void show(LinkList *L);//正序输出 
void reverse_show(LinkList *L);//逆序输出 --对应王道题3 
LinkList* reverse_Linklist(LinkList *L);//把链表原地逆置，对应王道题 5  

void sort_LinkList(LinkList *L); //对链表进行升序 

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
void append(LinkList *L,T data)//头插法 
{
	Lnode *node;
	node = create_node(data);
	node->next = L->next;
	L->next = node;
}

template<class T>
void push_back(LinkList *L,T data)//尾插法
{
	static Lnode* tail = L;//指向尾部 
	Lnode *move = L->next;
	while(move != NULL && tail->next != NULL){//如果当前tail指针不是指向尾部 
		tail = move;
		move = move->next;
	}
	Lnode *node;
	node = create_node(data);
	tail->next = node;
	tail = tail->next;
} 


Lnode* Get_index(LinkList *L,int index )//获取第几个元素，从1开始下标 
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
	return move;//返回第i个节点，如果i>节点数，则返回NULL 
}

template<class T>
Lnode* Get_element(LinkList *L,T data)
{
	Lnode *move = L->next;
	while(move != NULL && move->data != data){
		move = move->next;
	}
	return move;//如果为空，则说明不存在所需元素 
	
}

template<class T>
bool insert(LinkList *L,int index,T data)
{
	Lnode *node = create_node(data);
	Lnode *pre = Get_index(L,index-1);
	if(pre != NULL){//如果前驱节点不为空，或者说位置小于表长 
		node->next = pre->next;
		pre->next = node; 
		return true;//插入成功返回真 
	}
	return false;//否则返回逻辑假 
}


bool delete_index(LinkList *L,int index)//删除第i个节点，下标从1开始 
{
	if(index < 0)
		return false;
	Lnode *pre = Get_index(L,index-1);
	Lnode *temp;
	if(pre != NULL && pre->next != NULL)//找到要删除节点的前驱节点，如果前驱节点非空，并且位于i位置上的节点非空，则可以删除
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
	}//找到最小值的前驱节点，存在pre_min之中 
	move = pre_min->next;
	pre_min->next = move->next;
	free(move);
}


template<class T>
bool Recursive_delete(LinkList *L,T data)//递归删除 11 
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

void show(LinkList *L)//正序输出 
{
	Lnode *p = L->next;
	while( p != NULL){
		cout<<" "<<p->data;
		p = p->next;
	}
	cout<<endl;
}

void reverse_show(LinkList *L)//逆序输出 
{
	stack<Lnode*> S;
	Lnode *move;
	move = L->next;
	while(move != NULL){
		S.push(move);//入栈 
		move = move->next;
	}
	while( !S.empty()){ //出栈 
		move = S.top();
		cout<<move->data<<" ";
		S.pop();//出栈 
	}
}

LinkList* reverse_Linklist(LinkList *L)//把链表逆序   
{
	LinkList *head = create_LinkList();
	Lnode *move = L->next,*temp;
	while(move != NULL)
	{
		temp = move;
		move = move->next;//次序不能改变，保留指针防止断开 
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












