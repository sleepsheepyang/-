#include<stdio.h>
#define min(x,y) x<y ? x:y
int main(){
	int n;
	int a[202][2];
	int curSum = 0;	//记录当前总分 
	int r;
	double avg;
	
	while(true){
		scanf("%d",&n);
		if(n==0) break;
		for(int i = 0; i<n;i++){
			scanf("%d %d",&a[i][0],&a[i][1]);
			curSum += a[i][0];
		}	
		scanf("%d %lf",&r,&avg);
		int reSum = avg*n;	//记录需要得到的总分 
		//按复习时间递增排序，先复习用时少的，尽量在短时间内获得较大收益 
		for(int i = 0;i < n-1;i++){
			for(int j = n-1;j > i;j--){
				if(a[j][1] < a[j-1][1]){
					int temp = a[j][1];		//交换复习时间 
					a[j][1] = a[j-1][1];
					a[j-1][1] = temp;
				
					int temp1 = a[j][0];		//交换分数 
					a[j][0] = a[j-1][0];
					a[j-1][0] = temp1;	
				
				}
			}
		}
	
		int time = 0;	//记录复习时间 
		//按时间排序完成后，开始复习
		for(int i = 0;i<n;i++){
			if(curSum > reSum){
				//当前总分已经超过需要的总分，直接跳出；
				break; 
			} else{
				int thisSum = min(reSum - curSum,r - a[i][0]);	//该门课程需要获得的分数，从需要获得的总分数和这门课能获得的最大分数中取较小者
				curSum += thisSum;	//当前获得的总分数增加
				time +=  thisSum*a[i][1];	//当前复习时间加上该门课程花费的复习时间 
			}
		} 
		printf("最小复习时间为：%d",time);
	}
	return 0;
}
