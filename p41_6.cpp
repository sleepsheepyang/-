#include <iostream>
#include <map>
using namespace std;
int main(){
	int n;
	map<int, int> myMap;
	cin>>n;
	for(int i = 0; i<n ;i++){
		int rd;
		cin>>rd;
		if(myMap.find(rd) == myMap.end()){
			//Ã»ÕÒµ½
			myMap.insert(pair<int,int>(rd,1));
			cout<<myMap[rd]<<" "; 
		} else{
			myMap[rd]++;
			cout<<myMap[rd]<<" ";
		}
	}
	cout<<endl;
	return 0;
}
