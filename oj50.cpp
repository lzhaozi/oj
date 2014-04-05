#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		if(n<=1){
			printf("no\n");
			continue;
		}
		int bound=(int)sqrt(n)+1;
		for(i=2;i<bound;i++){
			if(n%i==0){
				printf("no\n");
				break;
			}
		}
		if(i>=bound){
			printf("yes\n");
		}
	}
	return 0;
}
