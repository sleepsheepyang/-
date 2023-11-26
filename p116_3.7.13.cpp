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
int sumTwo(BTNode * b){
	int d = 0;	//������¼��ǰ�ڵ��Ƿ���Ϊ2�Ľڵ�ĸ��� 
	if(b == NULL){
		return 0;	//��ǰ�ڵ�Ϊ�գ�ֱ�ӷ��� 0
	} 
	if(b->lchild != NULL && b->rchild!=NULL){
		d = 1;	//��ǰ�ڵ��Ϊ2����һ�� 
	} 
	return sumTwo(b->lchild) + sumTwo(b->rchild) + d;	//�������϶�Ϊ2�Ľڵ���� + �������϶�Ϊ2�ĸ��� + ���ڵ��Ϊ2�ĸ��� 
}
int main(){
	int a[] = {1,2,4,7,5,8,9,3,6};
	int b[] = {7,4,2,8,5,9,1,6,3};
	int n = sizeof(a)/sizeof(a[0]);
	BTNode * btree = CreateBTree(a,b,n);
	PreOrder(btree);
	printf("\n");
	InOrder(btree);
	int sum = sumTwo(btree);
	printf("\n");
	printf("��Ϊ2�Ľڵ���:%d��",sum);
	return 0;
} 

