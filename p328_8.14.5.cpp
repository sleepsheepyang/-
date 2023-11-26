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
		dp[i][0] = 1;	//�����Ӽ���Ϊ0ʱ��0 ���Է����Ӽ���ֻ��һ�ֻ��ַ�������i = 0ʱ��ֻ�е�j = 0ʱ�����Է���0����һ�ֻ��ַ�������j>0ʱ�����ܻ��� 
	}
	for(i = 1;i<=n;i++){
		for(j = 1;j<=sum;j++){
			if(i > sum){	//��ǰ���ֱ��Ӽ��޶��ͻ�Ҫ��ʱ��һ�����ܷ����Ӽ�����ô���ַ�������i֮ǰ���޶���Ϊjʱ��ȣ���dp[i][j] = dp[i-1][j] 
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j]  + dp[i-1][j-i];
				//��ǰ����С�ڵ����Ӽ��޶���ʱ�����Է��룬Ҳ���Բ���
				//ѡ�񲻷ţ����ַ�������i֮ǰ���޶���Ϊjʱ��ȣ���dp[i-1][j]
				//ѡ����룬����ǰ�Ӽ��޶���Ϊj-i,���Ի��ַ�����Ϊdp[i-1][j-i] 
			}
		} 
	}
	//dp[n][sum]Ϊ�����ϻ���Ϊ��Ϊsum�ķ����������Ӽ�A���Ӽ�B���жԳ��ԣ������Ҫ���Զ�
	return dp[n][sum]/2; 
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",split(n));
	return 0;
} 
