#include<stdio.h>
void f(int n,int &m)
{
	if(n<1){
		return;
	} 
	else{
		printf("调用f(%d,%d)前,n=%d,m=%d\n",n-1,m-1,n,m);
		n--;
		m--;
		f(n-1,m);
		printf("调用f(%d,%d)后,n=%d,m=%d\n",n-1,m-1,n,m);
	}
 } 
 
int main()
{
	int n=4,m=4;
	f(n,m);
	return 0;
} 
