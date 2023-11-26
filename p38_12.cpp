#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(int & a,int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int getMinNum(int nums[],int n){
	//用冒泡排序将数组中数据进行排序
	for(int i = 0;i < n-1; i++ ){
		for(int j = n-1;j > i ;j--){
			if(nums[j] < nums[j-1]){
				swap(nums[j],nums[j-1]);
			}
		}
	} 
	//将数组前两个数据的差值作为当前最小差值 
	int min = nums[1] - nums[0];
	int count = 1;
	for(int i = 2;i < n;i++){
		int diff = nums[i] - nums[i-1];
		if(diff < min){
			//当差值比当前最小差值小时，更新当前最小差值，同时对数置1 
			min = diff;
			count = 1;
		} else if(diff == min){
			//差值等于当前最小差值时，对数加1 
			count++;
		}
	} 
	return count;
}
int main(){
	int nums [] = {1,2,3,4};
	int n = sizeof(nums)/sizeof(nums[0]);
	//printf("%d\n",n);
	int count = getMinNum(nums,n);
	cout<<count;
	return 0;
}
