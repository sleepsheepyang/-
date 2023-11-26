#include "Btree.cpp"
int level(BTNode * b,int x,int h){	//h表示当从调用该函数时处于多少层，初值为1 
	int l; 
	if(b==NULL){
		return 0;
	}
	else if(b->data == x){
		return h;
	} else{
		l = level(b->lchild,x,h+1);	//在左子树中查找
		if(l!=0)
			return l;	// 在左子树中找到了，返回l
		else
		 	return level(b->rchild,x,h+1);	//在左子树中未找到，在右子树中找 
	}
	
	
}
int main(){
	int a[] = {1,2,4,7,3,5,6};
	int b[] = {4,7,2,1,5,3,6};
	int n = sizeof(a)/sizeof(int);
	BTNode * btree = CreateBTree(a,b,n);
	int l = level(btree,1,1);
	printf("%d",l);
	return 0;
} 
