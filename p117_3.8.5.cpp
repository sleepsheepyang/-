#include<stdio.h>
#include<malloc.h>
//以第一个数为基准进行划分 
int Partition(int a[],int s,int t){
	int i = s,j = t;
	int temp = a[s];
	while(i!=j){
		while(j>i && a[j]>=temp)
			j--;
		a[i] = a[j];
		while(i<j && a[i]<=temp)
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}

int getRes(int a[],int n){
	int s = 0,t = n-1;
	int flag = 1;
	while(flag){
		int i = Partition(a,s,t);
		if(i == n/2 - 1)	//如果i正好处于中间的数字，该次划分正好将较小一部分划分在i左边，较大的一部分划分在右边,此时停止划分
			flag = 0;
		else if(i < n/2-1){
			//本次划分i小于中间位置，继续在右边部分进行划分
			s = i+1;  
		} else{
			//本次划分i大于中间位置，继续在左边部分进行划分
			t = i-1;
		}
	}
	//划分完成后，分别计算两部分的和
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i<n/2;i++){
		sum1+=a[i];
	} 
	for(int i = n/2;i<n;i++){
		sum2+=a[i];
	}
	//求得是两部分差的绝对值，所以用较大的后半部分减较小的前半部分 
	return sum2 - sum1;
}

//遍历输出 
void disp(int a[],int s,int t){
	for(int i = s;i<=t;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int a[] = {9,8,1,1,1};
	int n = sizeof(a)/sizeof(a[0]); 
	printf("原数组：");
	disp(a,0,n-1);
	int ans = getRes(a,n);
	printf("划分后A1:");
	disp(a,0,n/2-1);
	printf("划分后A2:");
	disp(a,n/2,n-1);
	printf("结果值：%d\n\n",ans);
	
	int b[] = {9,8,1,3,1,4,5};
	int n1 = sizeof(b)/sizeof(b[0]); 
	printf("原数组：");
	disp(b,0,n1-1);
	int ans1 = getRes(b,n1);
	printf("划分后A1:");
	disp(b,0,n1/2-1);
	printf("划分后A2:");
	disp(b,n1/2,n1-1);
	printf("结果值：%d\n\n",ans1);
	
	return 0;
} 
