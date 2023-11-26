#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 201
#define min(x,y) x<y ? x:y
int n;
struct NodeType{
	int a;
	int b;
	bool operator<(const NodeType &s){
		return b<s.b;
	}
}; 
NodeType A[MAXN];
double avg;
int r;
int effort = 0;
void solve(){
	int Sums = (int)n*avg;
	printf("%d\n",Sums);
	int sum = 0;
	for(int i = 0;i<n;i++){
		sum+=A[i].a;
	}
	sort(A,A+n);
	for(int j=0;j<n;j++){
		if(sum>=Sums){
			break;
		}
		sum+=min(Sums-sum,r-A[j].a);
		effort+= A[j].b*min(Sums-sum,r-A[j].a);
	}
}
int main(){
	while(true){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		for(int i = 0;i<n;i++){
			scanf("%d%d",&A[i].a,&A[i].b);
		}
		scanf("%d%lf",&r,&avg);
		solve();
		printf("%d",effort);
	} 
	return 0;
}
