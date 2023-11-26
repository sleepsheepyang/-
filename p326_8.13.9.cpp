#define MAX 5000
long dp[MAX];
long f(int n){
	if(n == 1){
		dp[n] = 1;
		return dp[n];
	}
	if(n == 2){
		dp[n] = 2;
		return dp[n];
	}
	if(dp[n] > 0){
		return dp[n];
	}
	long sum = 1;
	for(int i = 1;i<=n;i++){
		sum+=f(i);
	}
	dp[n] = sum;
	return dp[n];
} 
int main(){
	return 0;
}
