#include<stdio.h>
int main(){
	//每走到一个加油站，只要剩余油量能走到下一个加油站，就不加油
	//每一箱油都要尽可能走最远的距离
	int max = 7;	//最大可行使距离 
	int cur = 7; 	//当前可行驶距离为7
	int n = 4;
	int cnt = 0;	//记录加油次数 
	int a[] = {2,7,3,6};
	for(int i = 0;i<n;i++){
		if(a[i] > max){
			//到达下一站的距离超过最大行驶距离
			printf("无法行驶到终点\n"); 
		}
		cur -= a[i];	//每到达一个加油站，可行驶距离减少 
		if(cur <= a[i+1]){	
			//当前可行使距离无法到达下一个加油站
			//需要加油，恢复最大行驶 ，最大加油次数加一
			printf("在第%d个加油站加油\n",i);
			cur = max;
			cnt++; 
		} 
	} 
	printf("一共加油%d次",cnt);
	return 0;
}
