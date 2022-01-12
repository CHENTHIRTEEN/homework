#include <iostream>
using namespace std;

int fact(int n){
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main()
{
    cout << "10的阶乘是：" << fact(10) << endl;
    return 0;
}
