#include "Btree.cpp"
int level(BTNode * b,int x,int h){	//h��ʾ���ӵ��øú���ʱ���ڶ��ٲ㣬��ֵΪ1 
	int l; 
	if(b==NULL){
		return 0;
	}
	else if(b->data == x){
		return h;
	} else{
		l = level(b->lchild,x,h+1);	//���������в���
		if(l!=0)
			return l;	// �����������ҵ��ˣ�����l
		else
		 	return level(b->rchild,x,h+1);	//����������δ�ҵ��������������� 
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
