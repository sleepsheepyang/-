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
	LinkNode * head=NULL;
	LinkNode * tail=NULL;
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
void deleteX(LinkNode * &L,int x){	//L会被修改，所以是*&L 
	if(L == NULL)
		return;
	if(L->data == x){
		LinkNode * p = L;	//新建p指针记录要删除的节点，用于删除。L指针被前驱节点所指，只需L指针更改为下一个节点，所需删除的节点便从链表中移除 
		L = L->next;
		free(p); 	//释放p所指资源 
	}else{
		deleteX(L->next,x);
	}

} 

int main(){
	int a[] = {12,46,1,89,108,12,45};
	int n = sizeof(a)/sizeof(int);
	LinkNode * L = CreateList(a,n);
	Disp(L);
	printf("\n");
	deleteX(L,12);
	Disp(L);
	return 0;
}
