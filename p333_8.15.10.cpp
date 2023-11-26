#include<stdio.h>
#define max(x,y) x>y?x:y
#define MAX 6002
int n;
int father[MAX] = {0};
int dp[MAX][2] = {0};		//dp[i][0] = 0表示不去，dp[i][1]=1表示去了
bool think[MAX] = {0};
void getDp(int i){	//在树中后根遍历求dp 
	think[i] = 1;
	for(int j = 1;j<=n;j++){
		if(think[j] == 0 && father[j] == i){
			//员工j是员工i的下属，并且没有被考虑过
			getDp(j);
			dp[i][1] += dp[j][0];	//主管i来，下属j不来
			dp[i][0] += max(dp[j][1],dp[j][0]); //主管i不来，选择下属来或不来的较大值 
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
			//查找根节点
			root = father[root]; 
		}
		getDp(root);
		int ans = max(dp[root][0],dp[root][1]);
		printf("%d\n",ans);
	} 
	return 0;
} 
