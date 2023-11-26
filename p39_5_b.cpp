#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> myv;
	myv.push_back(2);
	myv.push_back(4);
	myv.push_back(1);
	myv.push_back(3);
	sort(myv.begin(),myv.end());
	//vector<int>::iterator it;
	for(int i = 0;i<myv.size();i++){
		cout<<myv[i]<<" ";
	}
	cout<<endl;
	int n = myv.size();
	if(n%2 != 0){
		cout<<"中位数为："<<myv[n/2]<<endl;
	}else{
		cout<<"中位数为："<<myv[n/2 - 1]<<"或者"<<myv[n/2]<<endl;
	}
	return 0;
}
