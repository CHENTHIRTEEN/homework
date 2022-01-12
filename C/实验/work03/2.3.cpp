//操作符&用以求一个变量的地址，
//这在函数scanf中已经使用过了。现在要你设计一个程序，返回一个3×5 的二维数组各元素的地址，
//并由此说明二维数组中各元素是按什么顺序存储的。
#include <iostream>
using namespace std;

int main()
{
    int a[3][5] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "元素：" << "a[" << i << "][" << j << "]的地址是："<< &a[i][j] << endl;
        }
    }
}
