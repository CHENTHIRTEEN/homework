#include <stdio.h>

int product(int width, int height);
int main()
{
    int width, height;
    printf("�����볤���εĺͿ��ÿո������\n");
    scanf("%d %d", &width, &height);
    int s = product(width, height);
    printf("�����ε�����ǣ�%d \n", s);
}

int product(int width, int height)
{
    int temp = 0.0;
    temp = width * height;
    return temp;
}
