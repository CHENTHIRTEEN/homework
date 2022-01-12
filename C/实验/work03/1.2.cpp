//编写一个程序，输入系数a，b，c，求一元二次方程ax2+bx+c=0的根，包括主函数和如下函数。
//① 判断a是否为零。
//② 计算判别式 。
//③ 计算根的情况。
//④ 输出根。
#include <iostream>
#include <cmath>
using namespace std;

bool isZero(double a){
    if (a == 0.0){
        return true;
    }
    return false;
}

double judge(double a, double b, double c){
    return pow(b, 2) - 4 * a * c;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (isZero(a)){cout << "不是一元二次方程！"; return 0;}
    double j = judge(a, b, c);
    double x1, x2;
    if (j < 0){
        cout << "不存在实根" << endl;
    } else{
        if (j == 0){
            x1 = x2 = -b / 2 / a;
            cout << "x1 = x2 = " << x1;
            return 0;
        } else{
            x1 =  (-b + sqrt(j)) / 2 / a;
            x2 =  (-b - sqrt(j)) / 2 / a;
            cout << "x1 = " << x1 << " x2 = " << x2;
            return 0;
        }
    }
}
