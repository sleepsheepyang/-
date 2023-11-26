#include <stdio.h>
int m,n; 
int ans;
//马只能往右跳，没说不能往下跳 
void solve(int curx,int cury){
	if(curx==m && cury==n){
		ans++;
	}else if(curx<m && cury<n){
		//向右前跳
		 curx+=2;
		 cury+=1;
		 solve(curx,cury);
		 //回到原位 
		 curx-=2;
		 cury-=1;
		 //向右上跳 
		 curx+=1;
		 cury+=2;
		 solve(curx,cury);
	}
}
int main(){
	while(scanf("%d%d",&m,&n) && m * n){
		ans=0;
		solve(1,1);
		printf("%d",ans);
	}
	return 0;
} 
