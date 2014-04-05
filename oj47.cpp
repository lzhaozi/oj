#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		while(b){
			int tmp=b;
			b=a%b;
			a=tmp;
		}
		printf("%d\n",a);
	}
	return 0;
}
