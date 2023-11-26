#include<stdio.h>
#include<malloc.h>
#define ElemType int
typedef struct node{
	ElemType data;		//数据元素 
	struct node * lchild;	//指向左孩子节点 
	struct node * rchild;	//指向右孩子节点 
}BTNode;

//根据先序序列和中序序列递归创建二叉树 
BTNode * CreateBTree(ElemType a[],ElemType b[],int n){	
	if(n == 0){
		return NULL;
	}
	int rootData = a[0];	//先序序列的第一个元素设为根节点 
	BTNode * root = (BTNode *)malloc(sizeof(BTNode));
	root->data = rootData;
	int k;
	for(k = 0;k<n;k++){		//找到中序序列中根节点的下标 
		if(b[k] == rootData){
			break;
		}
	}
	root->lchild = CreateBTree(a+1,b,k);	//求根节点的左孩子节点，即对中序序列中根节点的左边部分递归
	root->rchild = CreateBTree(a+k+1,b+k+1,n-k-1);
	return root; 
}

//先序遍历输出二叉树
void PreOrder(BTNode * b){
	if(b != NULL){
		printf("%d ",b->data);	//输出根节点 
		PreOrder(b->lchild);	//递归遍历左子树
		PreOrder(b->rchild);	//递归遍历右子树 
	}
} 

//中序遍历输出二叉树
void InOrder(BTNode * b){
	if(b != NULL){
		InOrder(b->lchild);		//递归遍历左子树
		printf("%d ",b->data);	//输出根节点
		InOrder(b->rchild);		//递归遍历右子树 
	}
} 
int sumTwo(BTNode * b){
	int d = 0;	//用来记录当前节点是否是为2的节点的个数 
	if(b == NULL){
		return 0;	//当前节点为空，直接返回 0
	} 
	if(b->lchild != NULL && b->rchild!=NULL){
		d = 1;	//当前节点度为2，记一个 
	} 
	return sumTwo(b->lchild) + sumTwo(b->rchild) + d;	//左子树上度为2的节点个数 + 右子树上度为2的个数 + 根节点度为2的个数 
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
	printf("度为2的节点有:%d个",sum);
	return 0;
} 

