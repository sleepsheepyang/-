#include <stdio.h>
//在x方向上到每个商店 路程之和最小的横坐标为所有商店横坐标的中位数
//y方向上同理，所以仓库的位置应是所有商店的横坐标的中位数和纵坐标的中位数
//找中位数采用快速排序中划分的方法较快，只要划分的位置刚好在中间，就可以停止划分，否则可以在左区间或右区间继续划分
int selectMid(int a[],int s,int t,int mid){
	int i = s;
	int j = t;
	int temp;
	if(s < t){
		temp = a[s];	//以一个元素作为基准进行划分
		while(i != j){
			while(j>i && a[j] >= temp){	//从右向左遍历，找到一个比temp小的元素 
				j--;		
			}
			a[i] = a[j];	//将找到的比temp小的元素放在a[i]处 
			while(i<j && a[i] <=temp){	//从左向右遍历，找到一个比temp大的元素 
				i++;
			}
			a[j] = a[i];	//将找到的比temp小的元素放在a[j]处 
		} 
		a[i] = temp;	//将基准元素放到划分处
		if(mid - 1 == i){	//划分处刚好为在mid处 
			return a[i];
		} else if(mid - 1 < i){	//mid 在划分处左边，从左区间继续划分 
			return selectMid(a,s,i-1,mid);
		} else{	//mid 在划分处右边，从右区间继续划分 
			return selectMid(a,i+1,t,mid);
		}
	}else if(s == t && s==mid-1){
		//区间内只有一个元素
		return a[mid-1]; 
	}
	
} 

int main(){
	
	int m = 8;
	int n = 3;
	int midx,midy;
	int x[3] = {2,5,6};
	int y[3] = {4,3,6};
	if(n%2 == 0){
		midx = selectMid(x,0,n-1,n/2);
		midy = selectMid(y,0,n-1,n/2);
	}else{
		midx = selectMid(x,0,n-1,n/2 + 1);
		midy = selectMid(y,0,n-1,n/2 + 1);
	}
	printf("仓库位置为（%d,%d）",midx,midy);
	return 0;
} 
