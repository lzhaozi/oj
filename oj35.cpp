#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
	Node *lptr;
	Node *rptr;
	int data;
}buf[100];

void preOrder(Node *ptr){
	printf("%d ",ptr->data);
	if(ptr->lptr!=NULL)
		preOrder(ptr->lptr);
	if(ptr->rptr!=NULL)
		preOrder(ptr->rptr);
}

void inOrder(Node *ptr){
	if(ptr->lptr!=NULL)
		inOrder(ptr->lptr);
	printf("%d ",ptr->data);
	if(ptr->rptr!=NULL)
		inOrder(ptr->rptr);
}

void postOrder(Node *ptr){
	if(ptr->lptr!=NULL)
		postOrder(ptr->lptr);
	if(ptr->rptr!=NULL)
		postOrder(ptr->rptr);
	printf("%d ",ptr->data);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int idx=0;
		Node *root=&buf[idx];
		int x;
		scanf("%d",&x);
		root->data=x;
		root->lptr=root->rptr=NULL;
		idx++;
		for(int i=1;i<n;i++){
			scanf("%d",&x);
			Node *ptr=root;
			bool flag=true;
			while(flag&&x!=ptr->data){
				if(x<ptr->data){
					if(ptr->lptr==NULL){
						ptr->lptr=&buf[idx];
						ptr->lptr->data=x;
						ptr->lptr->lptr=ptr->lptr->rptr=NULL;
						idx++;
						flag=false;
					}else
						ptr=ptr->lptr;
				}
				else{
					if(ptr->rptr==NULL){
						ptr->rptr=&buf[idx];
						ptr->rptr->data=x;
						ptr->rptr->lptr=ptr->rptr->rptr=NULL;
						idx++;
						flag=false;
					}else
						ptr=ptr->rptr;
				}
			}
		}
		preOrder(root);
		printf("\n");
		inOrder(root);
		printf("\n");
		postOrder(root);
		printf("\n");
	}
	return 0;
}
