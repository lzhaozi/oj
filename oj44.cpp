#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		char n[100]="";
		scanf("%s",n);
		int b;
		scanf("%d",&b);
		long sum=0;
		for(int i=0;n[i]!=0;i++){
			int p=0;
			if(n[i]>='A' && n[i]<='F')
				p=n[i]-'A'+10;
			else if(n[i]>='a' && n[i]<='f')
				p=n[i]-'a'+10;
			else if(n[i]>='0' && n[i]<='9')
				p=n[i]-'0';
			sum*=a;
			sum+=p;
		}
		stack<char> ans;
		do{
			int bit=sum%b;
			sum/=b;
			if(bit<10)
				ans.push(bit+'0');
			else if(bit<16)
				ans.push(bit-10+'A');
		}while(sum);
		while(ans.empty()==false){
			printf("%c",ans.top());
			ans.pop();
		}
		printf("\n");
	}
	return 0;
}
