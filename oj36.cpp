#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Node{
	Node *lptr;
	Node *rptr;
	char data;
};

bool TreeBuilder(Node *&T,char *str){
	T=new Node;
	int idx=0;
	T->data=str[idx];
	T->lptr=T->rptr=NULL;
	idx++;
	Node *ptr=T;
	while(str[idx]!=0){
		ptr=T;
		bool flag=true;
		while(flag){
			if(str[idx]<ptr->data){
				if(ptr->lptr==NULL){
					ptr->lptr=new Node;
					ptr->lptr->data=str[idx];
					ptr->lptr->lptr=ptr->lptr->rptr=NULL;
					idx++;
					flag=false;
				}else
					ptr=ptr->lptr;
			}else{
				if(ptr->rptr==NULL){
					ptr->rptr=new Node;
					ptr->rptr->data=str[idx];
					ptr->rptr->lptr=ptr->rptr->rptr=NULL;
					idx++;
					flag=false;
				}else
					ptr=ptr->rptr;
			}
		}
	}
	return true;
}

bool TreeDeleter(Node *T){
	if(T->lptr==NULL&&T->rptr==NULL)
		delete T;
	if(T->lptr!=NULL)
		TreeDeleter(T->lptr);
	if(T->rptr!=NULL)
		TreeDeleter(T->rptr);
	return true;
}

void getPreOrder(Node *T,char *output,int idx){
	if(T!=NULL){
		output[idx]=T->data;
		idx++;
	}
	if(T->lptr!=NULL){
		getPreOrder(T->lptr,output,idx);
	}
	if(T->rptr!=NULL){
		getPreOrder(T->rptr,output,idx);
	}
}

void getInOrder(Node *T,char *output,int idx){
	if(T->lptr!=NULL){
		getInOrder(T->lptr,output,idx);
	}
	if(T!=NULL){
		output[idx]=T->data;
		idx++;
	}
	if(T->rptr!=NULL){
		getInOrder(T->rptr,output,idx);
	}
}

void getPostOrder(Node *T,char *output,int idx){
	if(T->lptr!=NULL){
		getPostOrder(T->lptr,output,idx);
	}
	if(T->rptr!=NULL){
		getPostOrder(T->rptr,output,idx);
	}
	if(T!=NULL){
		output[idx]=T->data;
		idx++;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		char str[15]="";
		scanf("%s",str);
		Node *Tree=NULL;
		TreeBuilder(Tree,str);
		char strPre[15]="";
		char strIn[15]="";
		getPreOrder(Tree,strPre,0);
		getInOrder(Tree,strIn,0);
		for(int i=0;i<n;i++){
			char str2[15]="";
			scanf("%s",str2);
			Node *Tree2=NULL;
			TreeBuilder(Tree2,str2);
			char strPre2[15]="";
			char strIn2[15]="";
			getPreOrder(Tree2,strPre2,0);
			getInOrder(Tree2,strIn2,0);
			if(strcmp(strPre,strPre2)==0&&strcmp(strIn,strIn2)==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
