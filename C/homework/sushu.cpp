#include <iostream>
#include <cmath>
using namespace std;

int isprimer(int n){
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int count = 0;
    for (int i = 101; i <= 200 ; ++i) {
        if (isprimer(i)){
            count ++;
        }
    }
    cout << count << endl;
}
