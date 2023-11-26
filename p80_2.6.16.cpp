#include "Btree.cpp"
int sumLeaves(BTNode *b){
	if(b==NULL){
		return 0;
	}
	if(b->lchild==NULL && b->rchild == NULL){
		return b->data;		//是叶子节点时，返回叶子节点的值 
	}
	return sumLeaves(b->lchild) + sumLeaves(b->rchild);	 //返回左子树叶子节点的和加右子树叶子节点的值 
}
int main(){
	int a[] = {1,2,4,7,3,5,6};
	int b[] = {4,7,2,1,5,3,6};
	int n = sizeof(a)/sizeof(int);
	BTNode * btree = CreateBTree(a,b,n);
	int sum = sumLeaves(btree);
	printf("%d ",sum);
	return 0;
}
