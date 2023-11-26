#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int data;
	struct Node * next; 
}LinkNode;

LinkNode *CreateList(int a[],int n){
	if(n<0){
		return NULL;
	}
	LinkNode * head;
	LinkNode * tail;
	for(int i = 0;i<n;i++){
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		newNode->data = a[i];
		newNode->next = NULL;
		if(i == 0){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}
void Disp(LinkNode * L){
	if(L != NULL){
		printf("%d ",L->data);
		Disp(L->next);
	}
}

//找到x节点的地址
LinkNode * findX(LinkNode * L,int x){
	if(L == NULL){
		return NULL;
	}else{
		if(L->data == x){
			return L;
		}else{
			findX(L->next,x);
		}
	}
} 

int main(){
	int a[] = {12,46,1,89,108,12,45};
	int n = sizeof(a)/sizeof(int);
	LinkNode * L = CreateList(a,n);
	Disp(L);
	printf("\n");
	LinkNode * px = findX(L,12);
	printf("%d \n",px->data);
	px = findX(L,0);
	printf("%d",&px);
	return 0;
}
