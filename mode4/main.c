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
    //int a[20]; // 存储结果。
    int all_t=0;
    int a[10];
    int i,n;
    int t_count=0;
    float zh;
    n=1;
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
            car[i]=fabs((m1*(zh-0.5))-m1*n/2)+t[rand()%225]+1.5+1.1;
        }
       printf("\n");
    while(1)
    {
    for(i=0;i<n;i++)
    {
        car[i]=car[i]-1;
        if(car[i]>-5000&&car[i]<=0)
        {
           t_count++;   //走了几辆；
           car[i]=-10000;
        }
        if(t_count==n)
        {

            count+=n;
            t_count=0;
            for(i = 0; i < n; i++) //输出得到的数值。
        {
            zh=i+1;
            car[i]=fabs((m1*(zh-0.5))-m1*n/2)+t[rand()%225]+1.5+1.1;
        }
        }

    }
    all_t++;
    if(all_t==3600)
        break;
    }
    printf("情况4，%d个泊位时，1小时能发%d辆车\n",2*n,2*count);


    return 0;
}
