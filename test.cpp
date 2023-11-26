#include<iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    /**********FOUND**********/ 

    for(int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << "1到" << n << "的所有整数的和为：" << sum;
    return 0;
}
