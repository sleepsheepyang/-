#include<stdio.h>
#define min(x,y) x<y? x:y
#define INF 0x3f3f3f3f
#define MAX 10002
int arr[MAX]={0};
int n;
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int dp[MAX];
	dp[1] = 1;	//到第一个桩子上需要一跳 
	for(int i = 2;i<=n;i++){
		dp[i]=INF;
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<i;j++){
			if(j + arr[j] >= i){
				//从第j个桩子能直接跳到第i个桩子
				dp[i] = min(dp[i],dp[j] + 1); 
			}
		}
	}
	if(dp[n]!=INF){
		printf("%d",dp[n]);
	}else{
		printf("-1");
	}
	return 0;
}
