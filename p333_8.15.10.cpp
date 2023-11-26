#include<stdio.h>
#define max(x,y) x>y?x:y
#define MAX 6002
int n;
int father[MAX] = {0};
int dp[MAX][2] = {0};		//dp[i][0] = 0��ʾ��ȥ��dp[i][1]=1��ʾȥ��
bool think[MAX] = {0};
void getDp(int i){	//�����к��������dp 
	think[i] = 1;
	for(int j = 1;j<=n;j++){
		if(think[j] == 0 && father[j] == i){
			//Ա��j��Ա��i������������û�б����ǹ�
			getDp(j);
			dp[i][1] += dp[j][0];	//����i��������j����
			dp[i][0] += max(dp[j][1],dp[j][0]); //����i������ѡ�������������Ľϴ�ֵ 
		}
	}
} 
int main(){
	int cur,fa,root;
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;i++){
			scanf("%d",&dp[i][1]);
		}
		while(scanf("%d%d",&cur,&fa) && (cur||fa)){
			father[cur] = fa;
			root = fa;
		}
		while(father[root]){
			//���Ҹ��ڵ�
			root = father[root]; 
		}
		getDp(root);
		int ans = max(dp[root][0],dp[root][1]);
		printf("%d\n",ans);
	} 
	return 0;
} 
