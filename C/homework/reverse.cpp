// 输入一个正整数，并将其颠倒过来组成一个新的数再输出这个数，如12345对应为54321
#include <stdio.h>
#include <string.h>
int main()
{
    printf("请输入一个正整数：\n");
    char nums[101];
    gets(nums);
    int l = strlen(nums);
    for (int i = l - 1; i >= 0 ; --i) {
        printf("%c", nums[i]);
    }
    return 0;
}