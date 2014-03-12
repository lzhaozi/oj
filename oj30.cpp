#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		priority_queue<int,vector<int>,greater<int> > Q;
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			Q.push(x);
		}
		int sum=0;
		int node1,node2;
		while(true){
			node1=Q.top();
			Q.pop();
			node2=Q.top();
			Q.pop();
			x=node1+node2;
			sum+=x;
			if(Q.empty())
				break;
			Q.push(x);
		}
		printf("%d\n",sum);
	}
	return 0;
}
