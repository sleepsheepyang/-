#include<stdio.h>
#define MAXN 45
#define MAXS MAXN*MAXN/2
int dp[MAXN][MAXS] = {0};
int split(int n){
	int sum = n*(n+1)/2;
	if(sum % 2!=0){
		return 0;
	} 
	sum/=2;
	int i,j;
	for(i = 0;i<=n;i++){
		dp[i][0] = 1;	//限制子集和为0时，0 可以放入子集，只有一种划分方案。当i = 0时，只有当j = 0时，可以放入0，有一种划分方案，当j>0时，不能划分 
	}
	for(i = 1;i<=n;i++){
		for(j = 1;j<=sum;j++){
			if(i > sum){	//当前数字比子集限定和还要大时，一定不能放入子集，那么划分方案就与i之前，限定和为j时相等，即dp[i][j] = dp[i-1][j] 
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j]  + dp[i-1][j-i];
				//当前数字小于等于子集限定和时，可以放入，也可以不放
				//选择不放，划分方案就与i之前，限定和为j时相等，即dp[i-1][j]
				//选择放入，放入前子集限定和为j-i,所以划分方案数为dp[i-1][j-i] 
			}
		} 
	}
	//dp[n][sum]为将集合划分为和为sum的方案，由于子集A和子集B具有对称性，结果需要除以二
	return dp[n][sum]/2; 
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",split(n));
	return 0;
} 
