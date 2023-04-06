#include<iostream>
#include<cassert>
using namespace std;
#define SIZE 50


template<class T>
class Stack{
public:
	Stack(int size = SIZE);
	~Stack();//��������
	void push(const T &item);//��ջ,const�������ݲ����Ķ���&item�����ô��� 
	void pop();//��ջ,����pop������ֵ,һ��ʹ��gettopȡ��ջ����ֵ 
	T GetTop(); //��ȡջ����ֵ 
	void clear();// ��� 
	int Getsize(); 
	bool isEmpty() const;//��const��ʾ��������ʱ��������ݽ��иı� 
	bool isFull() const;

private:
	T* list;
	int top;
}; 


int main(){
	
	Stack<int> test;
	for(int i=0;i<=20;i++)
		test.push(i);
	while(!test.isEmpty())
	{
		int num = test.GetTop();
		test.pop();
		cout<<"num="<<num<<"size= "<<test.Getsize()<<endl;
	} 
	
	
	return 0;
} 




template<class T>
Stack<T>::Stack(int size){
	list = new T[size];
	top = 0;//��ʼʱָ��ͷ�ڵ� 
}

template<class T>
Stack<T>::~Stack(){
	delete [] list;
	top = 0;//��ʼʱָ��ͷ�ڵ� 
}

template<class T>
void Stack<T>::push(const T &item){
	assert(!isFull());
	list[top++] = item;//��ʼʱ��ָ���һ���ڵ㣬�����x++�� 
}

template<class T>
void Stack<T>::clear(){
	top = 0;
}

template<class T>
void Stack<T>::pop(){
	assert(!isEmpty());
	top--;
}

template<class T>
T Stack<T>::GetTop(){
	return list[top-1];
}

template<class T>
int Stack<T>::Getsize()
{
	return top;
}

template<class T>
bool Stack<T>::isEmpty() const{
	return top == 0;
}

template<class T>
bool Stack<T>::isFull() const{
	return top == SIZE-1;
}







