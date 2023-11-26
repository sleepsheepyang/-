#include<stdio.h>
#include<malloc.h>
#define ElemType int
typedef struct node{
	ElemType data;		//����Ԫ�� 
	struct node * lchild;	//ָ�����ӽڵ� 
	struct node * rchild;	//ָ���Һ��ӽڵ� 
}BTNode;

//�����������к��������еݹ鴴�������� 
BTNode * CreateBTree(ElemType a[],ElemType b[],int n){	
	if(n == 0){
		return NULL;
	}
	int rootData = a[0];	//�������еĵ�һ��Ԫ����Ϊ���ڵ� 
	BTNode * root = (BTNode *)malloc(sizeof(BTNode));
	root->data = rootData;
	int k;
	for(k = 0;k<n;k++){		//�ҵ����������и��ڵ���±� 
		if(b[k] == rootData){
			break;
		}
	}
	root->lchild = CreateBTree(a+1,b,k);	//����ڵ�����ӽڵ㣬�������������и��ڵ����߲��ֵݹ�
	root->rchild = CreateBTree(a+k+1,b+k+1,n-k-1);
	return root; 
}

//����������������
void PreOrder(BTNode * b){
	if(b != NULL){
		printf("%d ",b->data);	//������ڵ� 
		PreOrder(b->lchild);	//�ݹ����������
		PreOrder(b->rchild);	//�ݹ���������� 
	}
} 

//����������������
void InOrder(BTNode * b){
	if(b != NULL){
		InOrder(b->lchild);		//�ݹ����������
		printf("%d ",b->data);	//������ڵ�
		InOrder(b->rchild);		//�ݹ���������� 
	}
} 


//int main(){
//	int a[] = {1,2,4,8,3,6,7};
//	int b[] = {4,8,2,1,6,3,7};
//	int n = sizeof(a)/sizeof(int);
//	BTNode * btree = CreateBTree(a,b,n);
//	PreOrder(btree);
//	printf("\n");
//	InOrder(btree);
//	return 0;
//}
