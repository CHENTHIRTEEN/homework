// （2）将一个长整型数s的每一位数位上的偶数依次取出来，
// 构成一个新的数t，其高位仍在高位，低位仍在低位，
// 例如：s=87653142时，t中的数为8642。
#include <iostream>
using namespace std;

int main()
{
    long l;
    cout << "请输入一个整数:" << endl;
    cin >> l;
    int k = 1;
    int result = 0;
    while(l != 0)
    {
        int temp = l % 10;
        if (temp % 2 == 0)
        {
            result += temp * k;
            k *= 10;
            l /= 10;
        } else{
            l /= 10;
            continue;
        }
    }
    cout << "构成的新数字t是:" << result << endl;
    return 0;
}
