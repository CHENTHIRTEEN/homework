#include <iostream>

int main() {
    cout << "乘法表" << endl;
    cout << "====================================" << endl;
    for (int i = 0; i < 20; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i < 20; ++i) {
        cout << i << " ";
        for (int j = 1; j < 20; ++j) {
            cout << i * j << " ";
        }
        cout << endl;
    }
}
