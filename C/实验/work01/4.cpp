#include<cstdio>

int main()
{
    int x=1234;
    float f=123.456;
    double m=123.456;
    char ch='a';
    char a[] = "Hello,world!";
    int y=3, z=4;
    printf("%d %d\n",y,z);
    printf("y=%d, z=%d\n",y,z);
    printf("%8d,%2d\n",x,x);
    printf("%f, %8f, %8.1f, %.2f, %.2e\n",f,f,f,f,f);
    printf("%lf\n",m);
    printf("%3c\n",ch);
    printf("%s\n%15s\n%10.5s\n%2.5s\n%.3s\n",a,a,a,a,a);
    return 0;
}


