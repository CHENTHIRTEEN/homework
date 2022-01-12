#include <iostream>
using namespace std;

void reverse(int a[]){
    int *p = a;
    p = p + 10 - 1;
    for (int i = 0; i < 10; ++i) {
        cout << *p << " ";
        p--;
    }
}
int  main()
{
    int a[10];
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    reverse(a);
    return 0;
}



