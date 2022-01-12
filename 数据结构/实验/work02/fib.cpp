#include <iostream>
using namespace std;

int fib(int n){
    if(n == 1)return 1;
    if(n == 2)return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << "斐波那契数列的第十位是：" << fib(10) << endl;
    return 0;
}

