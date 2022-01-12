#include <stdio.h>

int product(int width, int height);
int main()
{
    int width, height;
    printf("请输入长方形的和宽，用空格隔开：\n");
    scanf("%d %d", &width, &height);
    int s = product(width, height);
    printf("长方形的面积是：%d \n", s);
}

int product(int width, int height)
{
    int temp = 0.0;
    temp = width * height;
    return temp;
}
