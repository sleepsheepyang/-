#include <stdio.h>
#define MAX 20
int w[] = {1,2,6,4,3};	//����װ������� 
int n = 5,W = 10;
int best[MAX];
int cur = 0;	//��ű�ѡ�е���Ʒ�������� 
bool flag = false;	//�Ƿ��н�ı�־ 
void dfs(int i){
	if(i > n-1){
		//�ҵ�Ҷ�ӽڵ�
		for(int i = 0;i<n;i++){
			printf("%d",best[i]);
		}
		printf("\n");
		if(cur == W){
			flag = true;
		} 
		return;
	}
	if(cur + w[i] <= W){
		best[i] = 1;
		cur+=w[i];
		dfs(i+1);	
		cur-=w[i];
	}
	best[i] = 0;
	dfs(i+1); 
} 
int main(){
	flag = false;
	dfs(0);
	printf("%d",flag);
	return 0;
} 
