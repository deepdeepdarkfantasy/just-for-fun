#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
float  function_0(int n,float A[30][30],float *total);                   //判断矩阵是否有解以及求解的函数
float  function_1(int a,int b,float D,float For[30][30]);                //传递数组的函数
int main()
{
    int a,b,Row,Column,Count_co;
    float Det_OR;
    float OR[30][30];
    //Count_co=0;
     int I ;                                  //用于重新执行循环
    do
    {
      I=0;
    printf("请输入合理的线性方程组\n");
    printf("即，行数，比列数小1.\n");
    printf("请输入增广矩阵的行数与列数。\n");
    scanf("%d "" %d",&Row,&Column);
    printf("请按顺序输入矩阵。\n");
    for(a=0;a<Row;a++)
        for( b=0;b<Column;b++)
           {
               scanf("%f",&OR[a][b]);
            //   printf("%f\n",OR[a][b]);
             //  printf("%d   %d\n",a,b);
           }
  /*  for(a=0;a<Row;a++)
        for( b=0;b<Column;b++)
         //  printf("%f\n",OR[a][b]);
    printf("%f    %f    %f     %f",OR[0][0] ,OR[1][1],OR[0][1],OR[1][0]); */
    if(Column==3)
      //  printf("%d      %d\n",a,b),
      //  printf("%f    %f    %f     %f",OR[0][0] ,OR[1][1],OR[0][1],OR[1][0]),
         Det_OR=OR[0][0]*OR[1][1]-OR[0][1]*OR[1][0],
         printf("%f\n",Det_OR);
    else
        function_0(Column-1,OR,&Det_OR);                        //求值函数
    while(Det_OR==0)
    {
        printf("所输入的线性方程组无解，或者有无穷多解，请重新输入。\n");
        I=1;
    }
        function_1(Row,Column,Det_OR,OR);                               //统计+克拉默法则
         scanf("%d",&a);
    }
    while(I==1);
    return 0;
}
float  function_0(int n,float A[30][30],float *total)
   {
      int a, b,c,d,C,D,i,p;
      float B[30][30];
    for(a=0,b=0;b<=n-1;b++)//                                               取第一排下标为1~n的数
    {
      if((2+b)%2!=0)
       {
         p=(-1);
       }
      else  p=1;
       // printf("b=   %d\n",b);
        for(i=0,D=0,d=0;d<=n-1;d++,D++)
        {
            if(d==0)
             {
               D-=1;
              // printf("%d\n",D);
               continue;

             }
       // printf("%d\n",D);
            for(C=0,c=0;c<=n-1;c++,C++)
            {
                if(c==b)
                   {
                    C-=1;
                    continue;
                   }
              if(D==0)
              { //    printf("B[D][C]=  B[%d][%d] =%d , A[D][C]=  A[%d][%d] =%d , A[a][b]=   A[%d][%d] =%d\n",D,C,B[D][C],D,C,A[D][C],a,b,A[a][b]);
                B[D][C]=A[d][c]*A[a][b]*p;
                //    printf("B[%d][%d]=A[%d][%d]*A[%d][%d]*%d =%d\n",D,C,D,C,a,b,p,B[D][C]);
                //    printf("B[D][C]=  B[%d][%d] =%d , A[D][C]=  A[%d][%d] =%d , A[a][b]=   A[%d][%d] =%d\n",D,C,B[D][C],D,C,A[D][C],a,b,A[a][b]);
                i++;
              }
              else
              {
                  B[D][C]=A[d][c];
              //    printf("*****B[D][C]=  %d   A[D][C]=  %d\n",B[D][C],A[D][C]);
                  i++;
              }
            //    printf("第%d个数:  %d\n",D*(n-1)+C+1,B[D][C]);
              //  printf("%d       %d\n",D,C);=
          //    printf("%d\n",i);
            }
        }
       // printf("A[0][b]=%d    B[0][0]=%d  B[1][1]=%d   B[0][1]=%d B[1][0]=%d\n",A[0][b],B[0][0],B[1][1],B[0][1],B[1][0]);
         if(i==4)
       {
        // printf("11111111total=%d\n",*total);
        (*total)+=(B[0][0]*B[1][1]-B[0][1]*B[1][0]);
    // printf("total=%d   p=%d    ",*total,p);
       }
       else
       {
       //    printf("B[0][0]=%d,B[0][1]=%d,B[0][2]=%d\nB[1][0]=%d,B[1][1]=%d,B[1][2]=%d\nB[2][0]=%d,B[2][1]=%d,B[2][2]=%d\n",B[0][0],B[0][1],B[0][2],B[1][0],B[1][1],B[1][2],B[2][0],B[2][1],B[2][2]);
    //       printf("B[1][0]=%d,B[1][1]=%d,B[1][2]=%d\n",B[1][0],B[1][1],B[1][2]B[2][0],B[2][1],B[2][2]);
       //    printf("B[2][0]=%d,B[2][1]=%d,B[2][2]=%d\n")
      // printf("222222222total=%d\n",*total);
        function_0(n-1,B,total);                             //用递归逐级化简


       }
    }
    return 0;
   }
   float function_1(int a ,int b,float D, float For[30][30])
   {
      float For_1[30][30];
      float For_2[30];
      float Det_OR;
      int c,d,e,i;
      int n=0;
       while(n<=a-1)
      {  // printf("%f   \n",D);
          Det_OR=0;
          for(c=0;c<a;c++)
             for(d=0;d<b-1;d++)
             {
               // printf("For[%d][%d]=%f\n",c,d,For[c][d]);
                For_1[c][d]=For[c][d];
               // printf("For_1[%d][%d]=%f\n",c,d,For_1[c][d]);
             }
             for(i=0;i<a;i++)

                {   //printf("For[%d][%d]=%f\n",i,b-1,For[i][b-1]);
                    For_1[i][n]=For[i][b-1];
                    //printf("For_1[%d][%d]=%f\n",i,n,For_1[i][n]);
                }
                if(a==2)
                {
                    Det_OR=For_1[0][0]*For_1[1][1]-For_1[0][1]*For_1[1][0];
                }
             function_0(a,For_1,&Det_OR);
            // printf("Det_or=%f\n",Det_OR);
             For_2[n]=Det_OR/D;                                 //克拉默法则
             printf("X%d =%f\n",n+1,For_2[n]);
             n++;


      }


      return 0;

   }






















