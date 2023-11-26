#include <stdio.h>
//��x�����ϵ�ÿ���̵� ·��֮����С�ĺ�����Ϊ�����̵���������λ��
//y������ͬ�����Բֿ��λ��Ӧ�������̵�ĺ��������λ�������������λ��
//����λ�����ÿ��������л��ֵķ����Ͽ죬ֻҪ���ֵ�λ�øպ����м䣬�Ϳ���ֹͣ���֣������������������������������
int selectMid(int a[],int s,int t,int mid){
	int i = s;
	int j = t;
	int temp;
	if(s < t){
		temp = a[s];	//��һ��Ԫ����Ϊ��׼���л���
		while(i != j){
			while(j>i && a[j] >= temp){	//��������������ҵ�һ����tempС��Ԫ�� 
				j--;		
			}
			a[i] = a[j];	//���ҵ��ı�tempС��Ԫ�ط���a[i]�� 
			while(i<j && a[i] <=temp){	//�������ұ������ҵ�һ����temp���Ԫ�� 
				i++;
			}
			a[j] = a[i];	//���ҵ��ı�tempС��Ԫ�ط���a[j]�� 
		} 
		a[i] = temp;	//����׼Ԫ�طŵ����ִ�
		if(mid - 1 == i){	//���ִ��պ�Ϊ��mid�� 
			return a[i];
		} else if(mid - 1 < i){	//mid �ڻ��ִ���ߣ���������������� 
			return selectMid(a,s,i-1,mid);
		} else{	//mid �ڻ��ִ��ұߣ���������������� 
			return selectMid(a,i+1,t,mid);
		}
	}else if(s == t && s==mid-1){
		//������ֻ��һ��Ԫ��
		return a[mid-1]; 
	}
	
} 

int main(){
	
	int m = 8;
	int n = 3;
	int midx,midy;
	int x[3] = {2,5,6};
	int y[3] = {4,3,6};
	if(n%2 == 0){
		midx = selectMid(x,0,n-1,n/2);
		midy = selectMid(y,0,n-1,n/2);
	}else{
		midx = selectMid(x,0,n-1,n/2 + 1);
		midy = selectMid(y,0,n-1,n/2 + 1);
	}
	printf("�ֿ�λ��Ϊ��%d,%d��",midx,midy);
	return 0;
} 
