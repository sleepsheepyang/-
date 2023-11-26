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

LinkNode * reverse(LinkNode * L){
	if(L==NULL || L->next == NULL){
		return L;
	} 
	LinkNode * newhead = reverse(L->next);
	L->next->next = L;
	L->next = NULL;
	return newhead;
}
//递归找到链表最后一个元素 
int f(LinkNode * L){
	if(L->next==NULL){
		return L->data;
	}
	int n = f(L->next);
	return n;
}
int main(){
	int a[] = {12,46,1,89,108,12,45};
	int n = sizeof(a)/sizeof(int);
	LinkNode * L = CreateList(a,n);
	Disp(L);
	printf("\n");
	//printf("%d",f(L));
	LinkNode * newL= reverse(L);
	Disp(newL); 
	return 0;
}
