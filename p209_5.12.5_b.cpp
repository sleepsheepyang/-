#include <stdio.h>
//ֻ�����ҷ������ڲ�Խ�������£�����������
//(x+=2,y+=1)	(x+=1,y+=2)		(x+=2,y-=1)		(x+=1,y-=2)
//���������������鱣�� 
int dx[4] = {2,1,2,1};
int dy[4] = {1,2,-1,-2};
int cnt = 0;	//������¼·������ 
int m,n;	//m��n�� 
void dfs(int curx,int cury){
	if(curx == m && cury == n){
		//�պ��������Ͻǣ��γ�һ��·��
		cnt++; 
	} else if(curx >= 1 && curx<=m && cury>= 1 && cury<=n){
		//���������ھͿ��Գ�����Ծ 
		//����ÿһ������ 
		for(int i=0;i<4;i++){
			curx += dx[i];
			cury += dy[i];
			dfs(curx,cury);
			//����
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
