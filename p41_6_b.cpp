#include <iostream>
using namespace std;
#define N 1002
int main(){
	int a[N] = {0};		//�������±��ʾ���߱�ţ��������ݼ�¼���ô��� 
	int n = 0;
	cin>>n;
	int num;	//������¼���߱�ţ�ͬʱ��ʾ�����������е��±� 
	for(int i = 0;i<n;i++){
		cin>>num;
		a[num]++;
		cout<<a[num]<<" ";
	}
	cout<<endl;
	return 0;
} 
