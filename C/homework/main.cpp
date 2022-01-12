#include <iostream>
using namespace std;

int main() {
    cout << "乘法表" << endl;
    cout << "=====================================================================================" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << i;
        if (i < 10)
        {
            cout << "   ";
        } else{
            cout << "  ";
        }
    }
    cout << endl;
    for (int i = 1; i < 20; ++i) {
        cout << i;
        if (i < 10)
        {
            cout << "   ";
        } else{
            cout << "  ";
        }
        for (int j = 1; j < 20; ++j) {
            cout << i * j;
            if (i * j < 10)
            {
                cout << "   ";
            } else{
                if(i * j < 100)
                {
                    cout << "  ";
                } else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
