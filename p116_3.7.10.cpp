#include<stdio.h>
#include<malloc.h> 
//采用和求解最大元素和次大元素相同的思想
int getMax(int a,int b){
	return a>b?a:b;
}
int getMin(int a,int b){
	return a<b?a:b;
}
void solve(int a[],int low,int high,int &max,int &min){
	if(low == high){	//区间只有一个元素 
		max = a[low];
		min = a[high];
	} else if(low == high - 1){	//区间中有两个元素
		max = getMax(a[low],a[high]);
		min = getMin(a[low],a[high]);
	} else{
		int mid = (low + high)/2;
		int lmax,lmin;	//左区间求lmax,lmin
		solve(a,low,mid,lmax,lmin);
		int rmax,rmin;	//右区间求rmax,rmin
		solve(a,mid+1,high,rmax,rmin);
		max = getMax(lmax,rmax);	//在两个较大元素中取最大的 
		min = getMin(lmin,rmin);	//在两个较小元素中取最小的 
	}
}
int main(){
	int a[] = {45,2,3,12,78,34};
	int n = sizeof(a)/sizeof(a[0]);
	printf("整数序列为：");
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int max,min;
	solve(a,0,n-1,max,min);
	printf("最大值是：%d,最小值是：%d\n",max,min);
	return 0;
} 
