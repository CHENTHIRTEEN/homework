#include <cstdio>
int main()
{
    int score;
    printf("请输入一个成绩（百分制）:");
    scanf("%d", &score);
    if (score > 100 || score < 0){
        printf("输入的成绩不合理");
        return 0;
    }
    if (score >= 90 && score <= 100){
        printf("您的成绩%d, 等级为A", score);
        return 0;
    }
    if (score >= 80 && score <= 89){
        printf("您的成绩%d, 等级为B", score);
        return 0;
    }
    if (score >= 70 && score <= 79){
        printf("您的成绩%d, 等级为C", score);
        return 0;
    }
    if (score >= 60 && score <= 69){
        printf("您的成绩%d, 等级为D", score);
        return 0;
    }
    if (score < 60){
        printf("您的成绩%d, 等级为E", score);
        return 0;
    }
}
