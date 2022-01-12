#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int *a = new int[10];
    int *b = new int[20];
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    memcpy(b,a,sizeof(int)*10);
    for (int i = 0; i < 20; i++) {
        cout << b[i];
    }
}

