#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
char course[99][99][99];
int savecourse();
void menu()//菜单显示
{
    printf("***************课表系统菜单****************\n");
    printf("***************1.显示课表******************\n");
    printf("***************2.修改课表******************\n");
    printf("***************3.保存课表******************\n");
    printf("***************4.新建课表******************\n");
    printf("***************5.查看当前课程**************\n");
    printf("***************0.退出**********************\n");
}
//课程表输出函数
void print()
{
    FILE *fp;
    char time[5][99]={"8:00~8:55","10:00~10:55","14:00~14:55","16:00~16:55","19:00~19:55"};//设置时间
    int i,j;
    if((fp=fopen("g:\\cource.txt","r"))==NULL)
    {
        printf("can't open this file\n");
        exit(1);
    }
    printf("----------------------------------------------------------------------\n");
    printf("时间            星期一  星期二  星期三  星期四  星期五  星期六  星期天\n");
    printf("----------------------------------------------------------------------\n");
    for(i=0;i<5;i++)                                    //将课程表从文件中读出
    {
        printf("%5s\t",time[i]);
        for(j=0;j<7;j++)
        {
            fscanf(fp,"%s",course[i][j]);
            printf("%-8s",course[i][j]);
        }
        printf("\n");
        printf("---------------------------------------------------------------------\n");
    }
    fclose(fp);
    //recenttime();
    printf("\n\n");

}
void change()//修改函数
{
    char temp[10];
    char s;
    int date,time;
    char recourse[10];
    printf("输入你想要改的课程时间（星期1~7）");
    scanf("%d",&date);
    while(date<1||date>7)
    {
        printf("输入时间不合理，重新输入");
        scanf("%d",&date);
    }
    printf("输入你想要改的课程课次（1~5）");
    scanf("%d",&time);
    while(date<1||date>5)
    {
        printf("输入时间不合理，重新输入");
        scanf("%d",&time);
    }
    printf("你要将原来的课程修改为:");
    scanf("%s",recourse);
    strcpy(temp,recourse);
    getchar();
    strcpy(course[time-1][date-1],recourse);
    printf("是否保存（1 表示保存，否则不保存）");
    scanf("%c",&s);
    if(s=='1')
        savecourse();
    else
    {
        strcpy(course[time-1][date-1],temp);
    }
}
int savecourse()//保存函数
{
    FILE *fp;
    int i,j;
    if((fp=fopen("D:\\cource.txt","w"))==NULL)
    {
        printf("can't open this file");
        exit(1);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<7;j++)
            fprintf(fp,"%-8s",course[i][j]);
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("保存成功!\n");
}
void newcourse()//课表重置函数
{
    int i,j;
    printf("请一次输入一周的课程按回车开始\n");
    for(i=0;i<7;i++)
    {
        printf("请输入第%d天的课程：",i+1);
        for(j=0;j<7;j++)
            scanf("%s",course[i][j]);
    }
    savecourse();
}
void recenttime()
{
    struct tm *ptr;
    time_t it;
    int y,d,m,iWeek,h,min,l,c;
    char s[99];
    it=time(NULL);
    ptr=localtime(&it);
    y=ptr->tm_year+1900;
    d=ptr->tm_mday;
    m=ptr->tm_mon+1;
    h=ptr->tm_hour;
    min=ptr->tm_min;                                                              //时间转换程序
    printf("当前时间为%4d年%02d月%02d日 %d:%d:%d ",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
    iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    switch(iWeek)
    {
        case 0: strcpy(s,"星期一");printf("%s\n",s); break;
        case 1: strcpy(s,"星期二");printf("%s\n",s); break;
        case 2: strcpy(s,"星期三");printf("%s\n",s); break;
        case 3: strcpy(s,"星期四");printf("%s\n",s); break;
        case 4: strcpy(s,"星期五");printf("%s\n",s); break;
        case 5: strcpy(s,"星期六");printf("%s\n",s); break;
        case 6: strcpy(s,"星期天");printf("%s\n",s); break;
    }
    if((h<8||h>19)||h==9||h==11||h==12||h==13||h==15||h==17||h==18)
    {
        printf("当前无课");exit(1);
    }
    switch(h)
    {
        case 8:l=0;break;
        case 10:l=1;break;
        case 14:l=2;break;
        case 16:l=3;break;
        case 19:l=4;break;
    }
    if(strcmp(s,"星期一")==0) c=0;
    if(strcmp(s,"星期二")==0) c=1;
    if(strcmp(s,"星期三")==0) c=2;
    if(strcmp(s,"星期四")==0) c=3;
    if(strcmp(s,"星期五")==0) c=4;
    if(strcmp(s,"星期六")==0) c=5;
    if(strcmp(s,"星期天")==0) c=6;

    printf("要上的课程为 %s\n",course[l][c]);

}



int main()
{
    int select;
    int sign=1;
    char contin;
    FILE *fp;
    int i,j;
    if((fp=fopen("g:\\cource.txt","r"))==NULL)
    {
        printf("can't open this file");
        exit(1);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<7;j++)
            fscanf(fp,"%s",course[i][j]);

    }

    fclose(fp);
    while(sign)
    {
        menu();
        //music();
        printf("请输入操作：");
        scanf("%d",&select);
        while(select<0||select>5)
        {
            printf("你输入的操作不合法，请重新输入");
            scanf("%d",&select);

        }
        switch(select)
        {
            case 1:print();break;
            case 2:change();break;
            case 3:savecourse();break;
            case 4:newcourse();break;
            case 5:recenttime();break;
            case 0:printf("谢谢使用");sign=0;break;
        }
    }

}

