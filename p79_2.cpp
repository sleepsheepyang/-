#include<stdio.h>
void f(int n,int &m)
{
	if(n<1){
		return;
	} 
	else{
		printf("����f(%d,%d)ǰ,n=%d,m=%d\n",n-1,m-1,n,m);
		n--;
		m--;
		f(n-1,m);
		printf("����f(%d,%d)��,n=%d,m=%d\n",n-1,m-1,n,m);
	}
 } 
 
int main()
{
	int n=4,m=4;
	f(n,m);
	return 0;
} 
