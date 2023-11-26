#include<stdio.h>
#define MAX 100
#define N 4
int ans[MAX][MAX];
void screw(int start,int end,int startNum){
	if(start > end) return;
	if(start == end){
		ans[start][end] = startNum;
		return;
	}
	for(int i = start;i <= end;i++){
		ans[start][i] = startNum;
		startNum++;
	}
	int diff = end - start;
	for(int i = 0,s = start + 1; i < diff; i++,s++){
		ans[s][end] = startNum;
		startNum++;
	}
	for(int i = 0,s=end-1; i < diff; i++,s--){
		ans[end][s] = startNum;
		startNum++;
	}
	for(int i = 0,s=end-1; i < diff - 1 ; i++,s--){
		ans[s][start] = startNum;
		startNum++;
	} 
	screw(start+1,end-1,startNum);
} 
int main(){
	int n;
	while(true){
		scanf("%d",&n);
		if(n != 0){
			screw(1,n,1);
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					printf("%d ",ans[i][j]);
				}
				printf("\n");
			}		
		}
		printf("\n");
	}
	return 0;
} 
