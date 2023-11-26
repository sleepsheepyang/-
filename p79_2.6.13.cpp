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

LinkNode * findMax(LinkNode * L){
	if(L->next == NULL){
		return L;
	}else{
		LinkNode * pmax = findMax(L->next);
		if(L->data>pmax->data){
			return L;
		}else{
			return pmax;
		}
	}
}
int main(){
	int a[] = {1,21,344,12,3,143,90};
	int n = sizeof(a)/sizeof(int);
	LinkNode *L = CreateList(a,n);
	Disp(L);
	printf("\n");
	LinkNode * max = findMax(L);
	printf("%d ",max->data);
	return 0;
} 
