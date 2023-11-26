#include<stdio.h>
int Length(char *str){
	if(*str=='\0'){
		return 0;
	}
	else{
		return Length(str + 1) + 1;
	}
}
int main()
{
	char str[] = "abcde";
	printf("%d",Length(str));
	return 0;
 } 
