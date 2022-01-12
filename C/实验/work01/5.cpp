#include<cstdio>

int main()
{
    double x,y;
    char c1,c2,c3;
    int a1,a2,a3;
    scanf("%d%d%d", &a1, &a2, &a3);
    printf("%d,%d,%d\n",a1,a2,a3);
    scanf(" %c%c%c",&c1,&c2,&c3);
    printf("%c%c%c\n",c1,c2,c3);
    scanf("%lf%lf",&x,&y);
    printf("%lf,%lf\n",x,y);
    return 0;
}

