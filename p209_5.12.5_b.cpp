#include <stdio.h>
//只能向右方跳，在不越界的情况下，有四种跳法
//(x+=2,y+=1)	(x+=1,y+=2)		(x+=2,y-=1)		(x+=1,y-=2)
//将四种跳法用数组保存 
int dx[4] = {2,1,2,1};
int dy[4] = {1,2,-1,-2};
int cnt = 0;	//用来记录路径条数 
int m,n;	//m行n列 
void dfs(int curx,int cury){
	if(curx == m && cury == n){
		//刚好跳到右上角，形成一条路径
		cnt++; 
	} else if(curx >= 1 && curx<=m && cury>= 1 && cury<=n){
		//还在棋盘内就可以尝试跳跃 
		//遍历每一种跳法 
		for(int i=0;i<4;i++){
			curx += dx[i];
			cury += dy[i];
			dfs(curx,cury);
			//回溯
			curx -=dx[i];
			cury -=dy[i]; 
		}		
	}	
}
int main(){
	while(scanf("%d%d",&m,&n) && m * n){
		cnt=0;
		dfs(1,1);
		printf("%d",cnt);
	}
	return 0;
} 
