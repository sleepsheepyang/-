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

//�ҵ�x�ڵ�ĵ�ַ
void deleteX(LinkNode * &L,int x){	//L�ᱻ�޸ģ�������*&L 
	if(L == NULL)
		return;
	if(L->data == x){
		LinkNode * p = L;	//�½�pָ���¼Ҫɾ���Ľڵ㣬����ɾ����Lָ�뱻ǰ���ڵ���ָ��ֻ��Lָ�����Ϊ��һ���ڵ㣬����ɾ���Ľڵ����������Ƴ� 
		L = L->next;
		free(p); 	//�ͷ�p��ָ��Դ 
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
