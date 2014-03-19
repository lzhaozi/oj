#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main(){
	int m;
	while(scanf("%d",&m)!=EOF && m!=0){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long sum=a+b;
		stack<int> s;
		do{
			s.push(sum%m);
			sum/=m;
		}while(sum);
		while(s.empty()==false){
			printf("%d",s.top());
			s.pop();
		}
		printf("\n");
	}
	return 0;
}
