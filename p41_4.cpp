#include <iostream>
#include <string>
#define N 100002
using namespace std;
string multiply(int num1[] ,int num2[] ,int n,int m){
	//k��¼��λ��˽��������������е�λ�� 
	int ret[N] = {0};
	int k = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			k = i + j;
			ret[k] += num1[i] * num2[j];
			if(ret[k]>9){
				//����9��λ����λ��Ϊģ10������ 
				ret[k+1] += ret[k]/10;
				ret[k] = ret[k] % 10;
			}
		} 
	} 
	//�ҵ���߷�0λ 
	int high = n + m;
	while(ret[high]==0){
		high--;
	}
	//������תΪ�ַ������� 
	string str="";
	for(int i = high; i>=0 ;i--){
		//cout<<ret[i];
		str += '0' + ret[i];
	}
	return str;
}
int main()
{
	string str1,str2;
	int num1[N] = {0};
	int num2[N] = {0};

	cin>>str1;
	cin>>str2;
	int n = str1.size();
	int count = 0;
	//���ַ�������洢�������� 
	for(int i = n-1;i>=0;i--){
		num1[count] = str1.at(i) - '0';
		count++;
	}

	int m = str2.size();
	count = 0;
	for(int i = m-1;i>=0;i--){
		num2[count] = str2.at(i) - '0';
		count++;
	}

	cout<<multiply(num1,num2,n,m);

	return 0;
}
