#include <stdio.h>
#define MAX 20
int w[] = {1,2,6,4,3};	//各集装箱的重量 
int n = 5,W = 10;
int best[MAX];
int cur = 0;	//存放被选中的物品的总重量 
bool flag = false;	//是否有解的标志 
void dfs(int i){
	if(i > n-1){
		//找到叶子节点
		for(int i = 0;i<n;i++){
			printf("%d",best[i]);
		}
		printf("\n");
		if(cur == W){
			flag = true;
		} 
		return;
	}
	if(cur + w[i] <= W){
		best[i] = 1;
		cur+=w[i];
		dfs(i+1);	
		cur-=w[i];
	}
	best[i] = 0;
	dfs(i+1); 
} 
int main(){
	flag = false;
	dfs(0);
	printf("%d",flag);
	return 0;
} 
