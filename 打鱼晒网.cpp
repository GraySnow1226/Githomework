#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;
bool isRun(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}
int main()
{
    int year, month, day, sum = 0, monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    printf("Input year, month, day: \n");
    scanf("%d%d%d", &year, &month, &day);
    //判断输入的年月日是否合法
    if(month < 1 || month > 12)
    {
        printf("Invalid month! \n");
        return 0;
    }
    if(month == 2)
    {
        if(isRun(year))
        {
            if(day < 1 || day > 29)
            {
                printf("Invalid day! \n");
                return 0;
            }
        }
        else
        {
            if(day < 1 || day > 28)
            {
                printf("Invalid day! \n");
                return 0;
            }
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        if(day < 1 || day > 30)
        {
            printf("Invalid day! \n");
            return 0;
        }
    }
    else
    {
        if(day < 1 || day > 31)
        {
            printf("Invalid day! \n");
            return 0;
        }
    }
    if(year<1990)
    {
        printf("Invalid year! \n");
        return 0;
    }
    //计算从1990年1月1日到输入日期的天数
    for(int i=1990;i<year;i++)
    {
        if(isRun(i))
            sum+=366;
        else
            sum+=365;
    }
    if(month>1)
    {
        for(int i=0;i<month-1;i++)
            sum+=monthDays[i];
    }
    if(month>2 && isRun(year))
        sum++;
    sum+=day-1;
    if(sum%5<=2)
        printf("Today is for fishing! \n");
    else
        printf("Today is for sunning the net! \n");
    sleep(1);
    return 0;
}