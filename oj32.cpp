#include <iostream>
#include <stdio.h>
using namespace std;

bool getPostOrder(char *str1,int l1,int h1,
		char *str2,int l2,int h2,
		char *str3,int l3,int h3){
	if(l1>h1||l2>h2||l3>h3)
		return true;
	char root=str1[l1];
	int idx1,idx2,idx3;
	for(idx2=l2;idx2<=h2&&str2[idx2]!=root;idx2++);
	str3[h3]=root;
	if(l1==h1||l2==h2||l3==h3)
		return true;
	getPostOrder(str1,l1+1,l1+idx2-l2,
			str2,l2,idx2-1,
			str3,l3,l3+idx2-l2-1);
	getPostOrder(str1,l1+idx2-l2+1,h1,
			str2,idx2+1,h2,
			str3,l3+idx2-l2,h3-1);
	return true;
}

int main(){
	char str1[30];
	char str2[30];
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		int n;
		for(n=0;str1[n]!=0;n++);
		char str3[30];
		if(getPostOrder(str1,0,n-1,
					str2,0,n-1,
					str3,0,n-1))
			printf("%s\n",str3);
	}
	return 0;
}
