#include <stdio.h>
int m,n; 
int ans;
//��ֻ����������û˵���������� 
void solve(int curx,int cury){
	if(curx==m && cury==n){
		ans++;
	}else if(curx<m && cury<n){
		//����ǰ��
		 curx+=2;
		 cury+=1;
		 solve(curx,cury);
		 //�ص�ԭλ 
		 curx-=2;
		 cury-=1;
		 //�������� 
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
