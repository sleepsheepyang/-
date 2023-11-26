#include "Btree.cpp"
int sumLeaves(BTNode *b){
	if(b==NULL){
		return 0;
	}
	if(b->lchild==NULL && b->rchild == NULL){
		return b->data;		//��Ҷ�ӽڵ�ʱ������Ҷ�ӽڵ��ֵ 
	}
	return sumLeaves(b->lchild) + sumLeaves(b->rchild);	 //����������Ҷ�ӽڵ�ĺͼ�������Ҷ�ӽڵ��ֵ 
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
