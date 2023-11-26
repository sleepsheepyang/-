#include<stdio.h>
#include<iostream>
#include<malloc.h>
void findMost(int a[],int s,int t,int &most,int &count){
	if(s>t){
		return;
	}
	int mid = (s+t)/2;	//以中间数字为基准，找到中间数字连续的左边界和右边界，求出该数字的个数 
	int left=s,right=t;
	for(left = s;left < mid; left++){	
		//确定连续数字的左边界 
		if(a[left]== a[mid])
			break;
	}
	for(right = t;right>mid;right--){
		//确定连续数字的右边界
		if(a[right]== a[mid])
			break;
	}
	int curCount = right - left + 1;	//当前连续数字个数
	if(curCount > count){
		//当前数字个数，比记录的众数更多，更新众数记录
		most = a[mid];
	 	count = curCount;
	}
	findMost(a,s,left-1,most,count);	//递归查找左边的众数
	findMost(a,right+1,t,most,count);	//递归查找右边的众数  
}



int main(){
	int a[] = {1,2,2,2,3,3,3,3,3,5};
	int t = sizeof(a)/sizeof(int) - 1; 
	int most=0;
	int count=0;
	findMost(a,0,t,most,count);
	printf("众数是:%d\n重数是:%d\n",most,count);
	return 0;
}
