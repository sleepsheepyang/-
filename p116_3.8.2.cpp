#include<stdio.h>
#include<iostream>
#include<malloc.h>
void findMost(int a[],int s,int t,int &most,int &count){
	if(s>t){
		return;
	}
	int mid = (s+t)/2;	//���м�����Ϊ��׼���ҵ��м�������������߽���ұ߽磬��������ֵĸ��� 
	int left=s,right=t;
	for(left = s;left < mid; left++){	
		//ȷ���������ֵ���߽� 
		if(a[left]== a[mid])
			break;
	}
	for(right = t;right>mid;right--){
		//ȷ���������ֵ��ұ߽�
		if(a[right]== a[mid])
			break;
	}
	int curCount = right - left + 1;	//��ǰ�������ָ���
	if(curCount > count){
		//��ǰ���ָ������ȼ�¼���������࣬����������¼
		most = a[mid];
	 	count = curCount;
	}
	findMost(a,s,left-1,most,count);	//�ݹ������ߵ�����
	findMost(a,right+1,t,most,count);	//�ݹ�����ұߵ�����  
}



int main(){
	int a[] = {1,2,2,2,3,3,3,3,3,5};
	int t = sizeof(a)/sizeof(int) - 1; 
	int most=0;
	int count=0;
	findMost(a,0,t,most,count);
	printf("������:%d\n������:%d\n",most,count);
	return 0;
}
