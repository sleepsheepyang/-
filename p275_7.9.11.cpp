#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int A[] = {1,2,3};
	int B[] = {3,2,4};
	int nA = sizeof(A)/sizeof(A[0]);
	int nB = sizeof(B)/sizeof(B[0]);
	//��A��ÿ�������������B�л����ҵ������ֱ����򣬽��ٵ������Ƚ���������С�Ļ����� 
	sort(A,A+nA);
	sort(B,B+nB);
	int i = 0;
	int j = 0;
	int cnt = 0;
	while(i<nA && j<nB){
		if(A[i] <= B[j]){
			i++;
			j++;
			cnt++;
		} else{
			j++;
		}
	} 
	printf("������ͬʱ�ٰ�%d������\n",cnt);
	return 0;
} 
