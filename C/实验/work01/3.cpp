#include <cstdio>
using namespace std;

int main()
{
    int a = 5, b = 8, c = 8;
    printf("%d, %d, %d, %d\n", a == b && a == c,
           a != b && a != c, a >= b && a >= c, a <= b && a <= c);
    printf("%d, %d\n",a <= b || a >= c, a == b || b == c);
    printf("%d, %d, %d, %d\n", !(a == b), !(a >= b), !(a >= c), !(a <= b));
    return 0;
}
