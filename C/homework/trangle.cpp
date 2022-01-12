#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "请输入三角形的三边长：" << endl;
    cin >> a
        >> b
        >> c;
    if(a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "不构成三角形";
        return 0;
    }else{
        if( a == b || a == c || b == c)
        {
            if (a == b && b == c)
            {
                cout << "等边三角形"<< endl;
                return 0;
            }else{
                cout << "等腰三角形"<< endl;
            }
        }
    }
}
