//#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > A;	//小根堆,存放较大的一半数据 
priority_queue<int> B;//大根堆，存放较小的一半数据 
void insert(int x){
	if(A.size()==0){
		A.push(x);
	}else if(x>A.top()){
		A.push(x);
		if(A.size() > B.size()){
			int e = A.top();
			A.pop();
			B.push(e);
		}
	}else{
		B.push(x);
		if(B.size() > A.size()){
			int e = B.top();
			B.pop();
			A.push(e);
		}
	}
} 
void middle(){
	if(A.size() > B.size()){
		printf("%d ",A.top());
	}else if(A.size() < B.size()){
		printf("%d",B.top());
	}else{
		printf("%d 或 %d",A.top(),B.top());
	}
}
int main(){
	int a[] = {3,2,5,1};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 0;i<n;i++){
		insert(a[i]);
	}
	middle();
	return 0;
}
