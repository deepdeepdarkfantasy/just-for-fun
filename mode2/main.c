#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define  walk_speed  1
#define  m1  6.00
#define  m2  8.00
int main()
{
    int count=0;
    int all_t=0;
    int a[10];
    int i,n;
    float zh;
    n=5;
    int cc=0;
    float car[20];
    float t[225];
    for(i=0;i<165;i++)
        t[i]=11.24;
    for (i=0;i<51;i++)
        t[i+165]=33.70;
    for (i=0;i<9;i++)
      t[i+216]=68.4;
    srand(time(NULL));//通过获取时间值来设定随机数种子，以保证每次运行结果不同。
           for(i = 0; i < n; i++) //输出得到的数值。
        {
            zh=i+1;
            car[i]=fabs((m2*(zh-0.5))-m2*n/2)+t[rand()%225]+i*m2/5.5+1.5;
        }
       printf("\n");
    while(1)
    {
    for(i=0;i<n;i++)
    {
        car[i]=car[i]-1;
        if(car[i]<=0)
        {
           count++;   //走了几辆；
           car[i]=fabs(m2*(i-1/2)-m2*i/2)+t[rand()%225]+i*m2/5.5+3.5;
        }

    }
    all_t++;
    if(all_t==3600)
        break;
    }
    printf("情况2，%d个泊位时，1小时能发%d辆车\n",n,count);

    return 0;
}
