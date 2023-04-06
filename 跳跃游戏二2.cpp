#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> nums ={2,1};
	int maxpos = 0,steps=0,start=0,end=0,jump=0;
	int len = nums.size();
	for(int i=0;i<len-1;i+=jump){
		end = nums[i];
		if(i+end >= len)
		maxpos = 0;
		for( start = 1;start <= end;start++)
		{
			int newpos = nums[i+start] + start;
			if(maxpos <= newpos)
			{
				maxpos = newpos;
				jump = start;
			}
		}
		steps++;
	}
	cout<<"step="<<steps<<endl;

	return 0;
}


    


