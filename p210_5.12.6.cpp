#include <stdio.h>
int curT[20] = {0};	//��ŵ�ǰ�� 
int grap[20][20];	//���ͼ 
int max = 0;	//�������ŵĶ������ 
int cur;	//��ŵ�ǰ�ŵĶ������ 
int n,m;
void dfs(int i){
	if(i > n){
		//�����ӽڵ�
		if(cur > max){
			max = cur;
		}
		return;
    }
    bool flag = true;	//������־�ýڵ��Ƿ���뵱ǰ��
	for(int j = 1; j < i; j++){
		if(curT[j] != 0 && grap[j][i] == 0){
			//��ǰ���д��ڽڵ���ڵ�i֮��û�бߣ����ܽ��ڵ�i���뵱ǰ��
			flag = false; 
			break;
		}
	} 
	if(flag){
		//���Խ���ǰ�ڵ���뵱ǰ��
		curT[i] = 1;	 
		cur++; 		//��ǰ���ڽڵ�����һ 
		dfs(i+1);	//��������һ�ڵ����� 
		//����
		curT[i] = 0;
		cur--; 
	}

	curT[i] = 0;
	dfs(i + 1);
//	if(cur + n - i >= max){
//		//����ʣ��ڵ�ȫ���������ܳ�����ǰ��������нڵ���ʱ�����б�Ҫ������������ 
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
