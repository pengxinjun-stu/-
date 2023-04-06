#include<iostream>
#include<cassert>
using namespace std;
#define SIZE 50


template<class T>
class Stack{
public:
	Stack(int size = SIZE);
	~Stack();//析构函数
	void push(const T &item);//入栈,const保护数据不被改动，&item是引用传递 
	void pop();//出栈,这里pop不返回值,一般使用gettop取得栈顶的值 
	T GetTop(); //获取栈顶的值 
	void clear();// 清空 
	int Getsize(); 
	bool isEmpty() const;//加const表示函数运行时不会对数据进行改变 
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
	top = 0;//初始时指向头节点 
}

template<class T>
Stack<T>::~Stack(){
	delete [] list;
	top = 0;//初始时指向头节点 
}

template<class T>
void Stack<T>::push(const T &item){
	assert(!isFull());
	list[top++] = item;//初始时候指向第一个节点，因此用x++； 
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







