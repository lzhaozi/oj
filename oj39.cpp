#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int data1,data2;
	while(scanf("%d%d",&data1,&data2)!=EOF){
		stack<int> s1,s2;
		while(data1){
			s1.push(data1%10);
			data1=data1/10;
		}
		while(data2){
			s2.push(data2%10);
			data2=data2/10;
		}
		int sum=0;
		int array1[10]={0};
		int array2[10]={0};
		int idx=0;
		while(s1.empty()==false){
			int tmp1=s1.top();
			array1[idx++]=tmp1;
			s1.pop();
		}
		int n1=idx;
		idx=0;
		while(s2.empty()==false){
			int tmp2=s2.top();
			array2[idx++]=tmp2;
			s2.pop();
		}
		int n2=idx;
		for(int i=0;i<n1;i++)
			for(int j=0;j<n2;j++)
				sum+=(array1[i]*array2[j]);
		printf("%d\n",sum);
	}
	return 0;
}
