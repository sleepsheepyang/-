#include <iostream>
using namespace std;
#define N 100
typedef struct arr{
	int data[N];
	int count;
} Arr;

void add(Arr & test,int n){
	test.data[test.count] = n;
	test.count++;
}

void middle(Arr & test){
	//����
	int n = test.count;
	for(int i = 0;i < n - 1;i++){
		for(int j = n - 1;j > i;j--){
			if(test.data[j] < test.data[j-1]){
				int temp = test.data[j];
				test.data[j] = test.data[j-1];
				test.data[j-1] = temp;
			}
		}
	} 
	//���������λ�� 
	if(n%2 != 0){
		cout<<"��λ��Ϊ��"<<test.data[n/2]<<endl;
	}else{
		cout<<"��λ��Ϊ��"<<test.data[n/2 - 1]<<"����"<<test.data[n/2]<<endl;
	}
}
int main(){
	Arr test;
	add(test,3);
	add(test,1);
	add(test,2);
	add(test,4);
	middle(test);
	return 0;
	
}

 
