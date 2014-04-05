#include <iostream>
#include <stdio.h>

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int c=a*b;
		while(b){
			int t=b;
			b=a%b;
			a=t;
		}
		printf("%d\n",c/a);
	}
	return 0;
}
