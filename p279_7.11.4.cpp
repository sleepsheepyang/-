#include<stdio.h>
#define min(x,y) x<y ? x:y
int main(){
	int n;
	int a[202][2];
	int curSum = 0;	//��¼��ǰ�ܷ� 
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
		int reSum = avg*n;	//��¼��Ҫ�õ����ܷ� 
		//����ϰʱ����������ȸ�ϰ��ʱ�ٵģ������ڶ�ʱ���ڻ�ýϴ����� 
		for(int i = 0;i < n-1;i++){
			for(int j = n-1;j > i;j--){
				if(a[j][1] < a[j-1][1]){
					int temp = a[j][1];		//������ϰʱ�� 
					a[j][1] = a[j-1][1];
					a[j-1][1] = temp;
				
					int temp1 = a[j][0];		//�������� 
					a[j][0] = a[j-1][0];
					a[j-1][0] = temp1;	
				
				}
			}
		}
	
		int time = 0;	//��¼��ϰʱ�� 
		//��ʱ��������ɺ󣬿�ʼ��ϰ
		for(int i = 0;i<n;i++){
			if(curSum > reSum){
				//��ǰ�ܷ��Ѿ�������Ҫ���ܷ֣�ֱ��������
				break; 
			} else{
				int thisSum = min(reSum - curSum,r - a[i][0]);	//���ſγ���Ҫ��õķ���������Ҫ��õ��ܷ��������ſ��ܻ�õ���������ȡ��С��
				curSum += thisSum;	//��ǰ��õ��ܷ�������
				time +=  thisSum*a[i][1];	//��ǰ��ϰʱ����ϸ��ſγ̻��ѵĸ�ϰʱ�� 
			}
		} 
		printf("��С��ϰʱ��Ϊ��%d",time);
	}
	return 0;
}
