

#include<iostream>
#include<vector>
#include<random>
#include<time.h>
#include<algorithm>
using namespace std;

template<class T>
int binary_search(vector<T> &list,T num);
template<class T>
void insert_sort(vector<T> &list);
template<class T>
void select_sort(vector<T> &list);
template<class T>
void shell_sort(vector<T> &list);
 
template<class T>
void merge(vector<T> &list, vector<T> &temparry, int left , int right, int end);//把链表从left到right视为左半区，right到end视为右半部分 
template<class T>
void merge_sort(vector<T> &array, vector<T> &temparray, int left, int right);
template<class T>
void mergesort(vector<T> &list);

template<class T>
void show(vector<T> list){
	for(int i=0;i<list.size();i++)
		cout<<list[i]<<" ";
}



int main(){
	vector<int> test;
	srand(time(0));
	for(int i=0;i<20;i++){
	//	test.push_back(i);
		test.push_back(rand()%100);
		cout<<test[i]<<" ";
	}
	cout<<endl;
	show(test);
	cout<<"here"<<endl;
	mergesort(test);
	show(test);
	
	
	return 0;
}

template<class T>
int binary_search(vector<T> &list,T num){
	sort(list.begin(),list.end());
	int low=0,high = list.size() -1;
	while(low <= high){
		int mid = (low+high)/2;
		if(list[mid] == num)
			return mid;
		else if(list[mid] > num){
			high = mid-1;
		}
		else
			low = mid+1;
	}
	return -1;
}

template<class T>
void insert_sort(vector<T> &list){//插入排序 
	int len = list.size();
	for(int i = 1 ; i<len ;i++){
		T temp = list[i];
		int j = i-1;
		while( j>=0 && temp < list[j]  ){//后移 
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = temp; 
	}
}

template<class T>
void shell_sort(vector<T> &list){
	int len = list.size();
	int gap = len/2;
	for(gap ;gap > 0;gap /=2){
		for(int i=gap;i<len;i++){
			T temp = list[i];
			int j = i - gap;
			while( j>= 0 && temp <list[j] ){
				list[j+gap] = list[j];
				j -= gap;
			}
			list[j+gap] = temp;
		}
	}
}

template<class T>
void select_sort(vector<T> &list){
	int min_index;
	int len = list.size();
	for(int i=0;i<len;i++){
		min_index = i;
		for(int j=i;j<len;j++){
			if( list[min_index] > list[j])
			{
				min_index = j;
			}
		}
		T temp = list[min_index];
		list[min_index] = list[i];
		list[i] = temp;
	}
}

template<class T>
void merge(vector<T> &list, vector<T> &temparry, int left , int right, int end){//把链表从left到right视为左半区，right到end视为右半部分 
	
	int left_end = right-1;
	int num_element = end - left +1;
	int leftpos = left; 
	int temp_index = left;
	while(left <= left_end && right <= end )
	{
		if(list[left] <= list[right])
		{
			temparry[temp_index++] = list[left++];
		}
		if(list[left] > list[right])
		{
			temparry[temp_index++] = list[right++];
		}  
	} 
	while(left <= left_end){
		temparry[temp_index++] = list[left++];
	}
	while( right <= end){
		temparry[temp_index++] = list[right++];
	}
	for(int i = 0;i < num_element ; i++){
		list[leftpos+i] = temparry[leftpos+i];
	}
}

template<class T>
void merge_sort(vector<T> &array, vector<T> &temparray, int left, int right)
{
	if ( right > left)
	{
		size_t middle = (left + right) / 2;
		merge_sort(array, temparray, left, middle);
		merge_sort(array, temparray, middle + 1, right);
		merge(array, temparray, left, middle + 1, right);
	}
}

template<class T>
void mergesort(vector<T> &list){
	int size = list.size();
	vector<T> temparry(size);
	merge_sort(list,temparry,0,size);
}


























 
