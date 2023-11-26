#include <stdio.h>
#define MAX 21
int dx[4] = {1,2,2,1};
int dy[4] = {-2,-1,1,2};
int n,m;
int cnt;
int visited[MAX][MAX];
void solve(int x,int y){
	visited[x][y] = 1;
	if(x==n && y==m){
		cnt++;
	}
	for(int i = 0;i<=3;i++){
		int x1 = x+dx[i];
		int y1 = y+dy[i];
		if(x1<1 || x1>n || y1<1 || y1>m){
			continue;
		}
		if(visited[x1][y1] == 0){
			solve(x1,y1);
		}
	}
	visited[x][y] = 0;	//»ØËÝ 
}
int main(){
	while(true){
		scanf("%d%d",&n,&m);
		if(n == 0 && m==0)break;
		cnt=0;
		solve(1,1);
		printf("%d\n",cnt);
	} 
	return 0;
}
