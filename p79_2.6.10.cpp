#include<stdio.h>
#include<string.h>
bool isFal(const char *str,int n){
	if(n == 0 || n == 1){
		return true;
	}
	if(str[0] == str[n-1]){
		isFal(str+1,n-2);	//减去第一个和最后一个，字符串长度减2 ,str+1，字符串起始位置向后移动一位 
	}else{
		return false;
	}
}
void disp(const char * str){
	int n = strlen(str);
	if(isFal(str,n)){
		printf("是回文字符串\n");
	}else{
		printf("不是回文字符串\n");
	}
}
int main(){
	char str[] = "abba";
	disp("abbaa");
	return 0;
}
