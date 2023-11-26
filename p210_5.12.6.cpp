#include <stdio.h>
int curT[20] = {0};	//存放当前团 
int grap[20][20];	//存放图 
int max = 0;	//存放最大团的顶点个数 
int cur;	//存放当前团的顶点个数 
int n,m;
void dfs(int i){
	if(i > n){
		//到达子节点
		if(cur > max){
			max = cur;
		}
		return;
    }
    bool flag = true;	//用来标志该节点是否加入当前团
	for(int j = 1; j < i; j++){
		if(curT[j] != 0 && grap[j][i] == 0){
			//当前团中存在节点与节点i之间没有边，不能将节点i加入当前团
			flag = false; 
			break;
		}
	} 
	if(flag){
		//可以将当前节点加入当前团
		curT[i] = 1;	 
		cur++; 		//当前团内节点数加一 
		dfs(i+1);	//继续向下一节点搜索 
		//回溯
		curT[i] = 0;
		cur--; 
	}

	curT[i] = 0;
	dfs(i + 1);
//	if(cur + n - i >= max){
//		//当把剩余节点全加入团中能超过当前最大子团中节点数时，才有必要向右子树搜索 
//		curT[i] = 0;
//		dfs(i + 1);
//	}
}

int main(){
	int x,y;
	while(true){
		scanf("%d %d",&n,&m);
		if(m == 0 && n == 0){
			break;
		}
		for(int i = 1; i <= m ;i++){
			scanf("%d %d",&x,&y);
			grap[x][y] = 1;
			grap[y][x] = 1;
		}
		dfs(1);
		printf("%d",max);
	}
	return 0;
} 
