#include<stdio.h>
#include<malloc.h> 
//���ú�������Ԫ�غʹδ�Ԫ����ͬ��˼��
int getMax(int a,int b){
	return a>b?a:b;
}
int getMin(int a,int b){
	return a<b?a:b;
}
void solve(int a[],int low,int high,int &max,int &min){
	if(low == high){	//����ֻ��һ��Ԫ�� 
		max = a[low];
		min = a[high];
	} else if(low == high - 1){	//������������Ԫ��
		max = getMax(a[low],a[high]);
		min = getMin(a[low],a[high]);
	} else{
		int mid = (low + high)/2;
		int lmax,lmin;	//��������lmax,lmin
		solve(a,low,mid,lmax,lmin);
		int rmax,rmin;	//��������rmax,rmin
		solve(a,mid+1,high,rmax,rmin);
		max = getMax(lmax,rmax);	//�������ϴ�Ԫ����ȡ���� 
		min = getMin(lmin,rmin);	//��������СԪ����ȡ��С�� 
	}
}
int main(){
	int a[] = {45,2,3,12,78,34};
	int n = sizeof(a)/sizeof(a[0]);
	printf("��������Ϊ��");
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int max,min;
	solve(a,0,n-1,max,min);
	printf("���ֵ�ǣ�%d,��Сֵ�ǣ�%d\n",max,min);
	return 0;
} 
