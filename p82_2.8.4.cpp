#include<stdio.h>
//int stepM(int n){
//	if(n == 1){
//		return 1;
//	}else{
//		return 2 * stepM(n-1);
//	}
//}
int stepM(int n){
	if( n == 1) return 1;
	if(n==2) return 2;
	long sum = 1;
	for(int i=1;i<=n-1;i++){
		sum+=stepM(i);
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int count = stepM(n);
	printf("%d\n",count);
	printf("%d\n",stepM(3));
	printf("%d\n",stepM(4));
	printf("%d\n",stepM(5));
	printf("%d\n",stepM(6));
	return 0;
}
