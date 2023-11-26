#include <iostream>
using namespace std;
#define N 1002
int main(){
	int a[N] = {0};		//用数组下标表示读者编号，数组内容记录到访次数 
	int n = 0;
	cin>>n;
	int num;	//用来记录读者编号，同时表示读者在数组中的下标 
	for(int i = 0;i<n;i++){
		cin>>num;
		a[num]++;
		cout<<a[num]<<" ";
	}
	cout<<endl;
	return 0;
} 
