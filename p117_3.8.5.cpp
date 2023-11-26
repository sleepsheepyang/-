#include<stdio.h>
#include<malloc.h>
//�Ե�һ����Ϊ��׼���л��� 
int Partition(int a[],int s,int t){
	int i = s,j = t;
	int temp = a[s];
	while(i!=j){
		while(j>i && a[j]>=temp)
			j--;
		a[i] = a[j];
		while(i<j && a[i]<=temp)
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}

int getRes(int a[],int n){
	int s = 0,t = n-1;
	int flag = 1;
	while(flag){
		int i = Partition(a,s,t);
		if(i == n/2 - 1)	//���i���ô����м�����֣��ôλ������ý���Сһ���ֻ�����i��ߣ��ϴ��һ���ֻ������ұ�,��ʱֹͣ����
			flag = 0;
		else if(i < n/2-1){
			//���λ���iС���м�λ�ã��������ұ߲��ֽ��л���
			s = i+1;  
		} else{
			//���λ���i�����м�λ�ã���������߲��ֽ��л���
			t = i-1;
		}
	}
	//������ɺ󣬷ֱ���������ֵĺ�
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i<n/2;i++){
		sum1+=a[i];
	} 
	for(int i = n/2;i<n;i++){
		sum2+=a[i];
	}
	//����������ֲ�ľ���ֵ�������ýϴ�ĺ�벿�ּ���С��ǰ�벿�� 
	return sum2 - sum1;
}

//������� 
void disp(int a[],int s,int t){
	for(int i = s;i<=t;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int a[] = {9,8,1,1,1};
	int n = sizeof(a)/sizeof(a[0]); 
	printf("ԭ���飺");
	disp(a,0,n-1);
	int ans = getRes(a,n);
	printf("���ֺ�A1:");
	disp(a,0,n/2-1);
	printf("���ֺ�A2:");
	disp(a,n/2,n-1);
	printf("���ֵ��%d\n\n",ans);
	
	int b[] = {9,8,1,3,1,4,5};
	int n1 = sizeof(b)/sizeof(b[0]); 
	printf("ԭ���飺");
	disp(b,0,n1-1);
	int ans1 = getRes(b,n1);
	printf("���ֺ�A1:");
	disp(b,0,n1/2-1);
	printf("���ֺ�A2:");
	disp(b,n1/2,n1-1);
	printf("���ֵ��%d\n\n",ans1);
	
	return 0;
} 
