#include <stdio.h>

int primeNumber[10000];
int primeSize;
bool isPrime[10001];// true stands for not prime, false stands for prime

void init(){
	primeSize=0;
	for(int i=0;i<10001;i++)
		isPrime[i]=false;

	for(int i=2;i<10001;i++){
		if(isPrime[i]==true) continue;

		primeNumber[primeSize++]=i;
		for(int j=i*i;j<10001;j+=i){
			isPrime[j]=true;
		}
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		bool isOutput=false;

		for(int i=0;primeNumber[i]<n;i++){
			if(primeNumber[i]%10==1){
				if(isOutput==false){
					isOutput=true;
					printf("%d",primeNumber[i]);
				}else{
					printf(" %d",primeNumber[i]);
				}
			}
		}
		if(isOutput==false)
			printf("-1\n");
		else
			printf("\n");
	}
	return 0;
}
