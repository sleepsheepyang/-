#include "Btree.cpp"
int countK(BTNode * b,int k){
	if(b == NULL){
		return 0;
	}
	if( b->data >= k){
		return countK(b->lchild,k) + countK(b->rchild,k) + 1;	//左子树中符合条件节点个数加右子树中符合条件节点个数 
	}else{
		return countK(b->lchild,k) + countK(b->rchild,k);
	}
		
}
int main(){
	int a[] = {1,2,4,7,3,5,6};
	int b[] = {4,7,2,1,5,3,6};
	int n = sizeof(a)/sizeof(int);
	BTNode * btree = CreateBTree(a,b,n);
	int c = countK(btree,3);
	printf("%d",c);
	return 0;
} 
