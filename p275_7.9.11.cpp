#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int A[] = {1,2,3};
	int B[] = {3,2,4};
	int nA = sizeof(A)/sizeof(A[0]);
	int nB = sizeof(B)/sizeof(B[0]);
	//将A中每个会议的人数和B中会议室的容量分别排序，较少的人数先进入容量较小的会议室 
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
	printf("最多可以同时举办%d场会议\n",cnt);
	return 0;
} 
