#include<stdio.h>
#include<string.h>
bool isFal(const char *str,int n){
	if(n == 0 || n == 1){
		return true;
	}
	if(str[0] == str[n-1]){
		isFal(str+1,n-2);	//��ȥ��һ�������һ�����ַ������ȼ�2 ,str+1���ַ�����ʼλ������ƶ�һλ 
	}else{
		return false;
	}
}
void disp(const char * str){
	int n = strlen(str);
	if(isFal(str,n)){
		printf("�ǻ����ַ���\n");
	}else{
		printf("���ǻ����ַ���\n");
	}
}
int main(){
	char str[] = "abba";
	disp("abbaa");
	return 0;
}
