#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
//-----------------------------------------//
#define r_of_footbal 10.75   //足球半径
#define h_of_can 12.30        //易拉罐高度
#define w_of_can 3.30         //易拉罐半径
#define dot 0.01             //相邻离散点间距
double **x_y_label_of_e_n(int array_num_of_can[10],double array_xlabel[][2],double array_ylabel[][2] );//找出每个矩形右上角点的坐标
double **x_y_label_of_center_point(int array_num_of_can[10],double array_xlabel[][2],double array_ylabel[][2]);//找出每个矩形的中心点的坐标。
int *vector_circle_center_point_e_n(double **center_point,double **e_n);//用于计算相交与掉落的矩形个数
int main()
{
    int *p;
    double **center_point_1;
    double **e_n_1;
	int a, b, c,d;
	int num_of_can[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double xlabel[10][2];
	double ylabel[10][2];
	for(a=0,c=0,d=0;a<10;a++,d--)
    {
        if (a == 0 || a == 4 || a == 7 || a == 9)
            {
				d = 0;
				 c++;
            }
		for (b = 0; b < 2; b++)
		{

			xlabel[a][b] = d * 2*w_of_can + w_of_can * (c-1);
			ylabel[a][b]=(c-1)*h_of_can+b*h_of_can;
			d++;

     //   printf("num_of_can[%d]'s\n xlable[%d][%d]=%f \nylabel[%d][%d]=%f\n",num_of_can[a],a,b,xlabel[a][b],a,b,ylabel[a][b]);
		}
    }
    //每个罐子的宽的坐标以及高的坐标都存入了数组
    /*
                                       9
                                     7   8
                                    4  5  6
                                   1  2  3 4
    */

    center_point_1=x_y_label_of_center_point(num_of_can,xlabel,ylabel);  //矩形求中心点坐标；
    e_n_1=x_y_label_of_e_n(num_of_can,xlabel,ylabel);                      //求右上角点坐标；
    p=vector_circle_center_point_e_n(center_point_1,e_n_1);                           //求向量与判断是否相交；

   /*  for(int a=0;a<10;a++)
    {
        printf("罐子 %d 中心点的坐标是 (%f,%f)\n",num_of_can[a],center_point_1[a][0],center_point_1[a][1]);
        printf("罐子 %d 右上角点的坐标是(%f,%f)\n",num_of_can[a],e_n_1[a][0],e_n_1[a][1]);
    }
    */
    for(int a=0;a<10;a++)

    {
        printf("击倒%d个罐子的点集：S[%d]=%d\n",a+1,a+1,p[a]);
    }
    for(int a=0;a<10;a++)
    {

        free(center_point_1[a]);
        free(e_n_1[a]);
    }
    free(center_point_1);
    free(e_n_1);
    free(p);
  /*  for(a=0;a<10;a++)
    {
        printf("罐子 %d 中心点的坐标是 (%f,%f)\n右上角点的坐标是(%f,%f)\n",num_of_can[a],center_point[a][0],center_point[a][1],e_n[a][0],e_n[a][1]);
    }    */

    return 0;
}
double  **x_y_label_of_center_point(int array_num_of_can[10],double array_xlabel[][2],double array_ylabel[][2])
{
    int a,b;
    int num_of_can[10]={1,2,3,4,5,6,7,8,9,10};
    //double xlabel[10][2];
   // double ylabel[10][2];
    double **center_point;   //中心点坐标
    center_point=(double**)malloc(10*sizeof(double*));
    for( a=0;a<10;a++)
    {
        center_point[a]=(double*)malloc(2*sizeof(double));
        center_point[a][0]=(array_xlabel[a][0]+array_xlabel[a][1])/2;
        center_point[a][1]=(array_ylabel[a][0]+array_ylabel[a][1])/2;
    }
    /*----------------------------------------------------------------------------------------*/
    //[0]为横坐标，[1]为纵坐标。


  /*  for(int a=0;a<10;a++)
    {
        printf("罐子 %d 中心点的坐标是 (%f,%f)\n",num_of_can[a],center_point[a][0],center_point[a][1]);

    }
  // printf("222222222222222");
  printf("%p \n",center_point);*/
    return center_point;
}
/*----------------------------------------------------------------------------*/
//用于求矩形中心点的坐标。
double **x_y_label_of_e_n(int array_num_of_can[10],double array_xlabel[][2],double array_ylabel[][2] )
{
    int a,b;
    int num_of_can[10]={1,2,3,4,5,6,7,8,9,10};
    //double xlabel[10][2];
   // double ylabel[10][2];
    double **e_n;           //右上角点坐标
    e_n=(double**)malloc(10*sizeof(double*));
    for( a=0;a<10;a++)
    {
        e_n[a]=(double*)malloc(2*sizeof(double));
        e_n[a][0]=array_xlabel[a][1];
        e_n[a][1]=array_ylabel[a][1];
    }
    /*----------------------------------------------------------------------------------------*/
    //[0]为横坐标，[1]为纵坐标。


   /* for(int a=0;a<10;a++)
    {
        printf("罐子 %d 右上角点的坐标是(%f,%f)\n",num_of_can[a],e_n[a][0],e_n[a][1]);

    }
*/
    return e_n;
}
int *vector_circle_center_point_e_n(double **center_point,double **e_n)
{
    int c,d,e;
    int f;
    int num_of_can[10]={1,2,3,4,5,6,7,8,9,10};
    d=0;
    int *num_of_fallen_can;
    num_of_fallen_can=(int*)malloc(10*sizeof(int));
    for(c=0;c<10;c++)
        num_of_fallen_can[c]=0;
    int num_of_intersect[10];
    double  a=10.75;
    double  b=-10.75;
    double vector_u_xlabel;
    double vector_u_ylabel;
//printf("罐子 %d 右上角点的坐标是(%f,%f)\n",num_of_can[1],e_n[1][0],e_n[1][1]);
    for(a;a<=59.95;a=a+dot)
    {

        for(b=-10.75;b<=22.87;b=b+dot)
            {
               // printf("a=%f\n b=%f\n",a,b);
               // printf("b=%f\n");

                for(c=0;c<10;c++)
                {
                    num_of_intersect[c]=0;
           //         printf("c=%d\n",c);
                }


                for(c=0;c<10;c++)
                {

                    abs(b-center_point[c][0]);
                    abs(a-center_point[c][1]);     //向量v

                    e_n[c][0]-center_point[c][0];
                    e_n[c][1]-center_point[c][1];     //向量h
                 //  printf("c=%d\n",c);
                    vector_u_xlabel=abs(b-center_point[c][0])-(e_n[c][0]-center_point[c][0]);
                    vector_u_ylabel=abs(a-center_point[c][1])-(e_n[c][1]-center_point[c][1]);//向量u=v-h

                  //  printf("b=%f,c=%d,vector_u_xlabel=%f\n",b,c,vector_u_xlabel);
                  //  printf("a=%f,d=%d,vector_u_ylabel=%f\n",a,c,vector_u_ylabel);
                    if(vector_u_xlabel<0)
                          vector_u_xlabel=0;
                    if(vector_u_ylabel<0)
                          vector_u_ylabel=0;
                    if(vector_u_xlabel*vector_u_xlabel+vector_u_ylabel*vector_u_ylabel<=10.75*10.75)
                    {
                        num_of_intersect[c]=1;

                    }                                        //与哪个矩形相交，则与其对应的数组中的值变为1；不相交则为0.
                    if(num_of_intersect[0]==1)
                    {
                        num_of_intersect[4]=1;
                        num_of_intersect[7]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[1]==1)
                    {
                        num_of_intersect[4]=1;
                        num_of_intersect[5]=1;
                        num_of_intersect[7]=1;
                        num_of_intersect[8]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[2]==1)
                    {
                         num_of_intersect[6]=1;
                        num_of_intersect[5]=1;
                        num_of_intersect[7]=1;
                        num_of_intersect[8]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[3]==1)
                    {
                        num_of_intersect[6]=1;
                        num_of_intersect[8]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[4]==1)
                    {
                        num_of_intersect[7]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[5]==1)
                    {
                        num_of_intersect[7]=1;
                        num_of_intersect[8]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[6]==1)
                    {
                        num_of_intersect[8]=1;
                        num_of_intersect[9]=1;
                    }
                    if(num_of_intersect[7]==1||num_of_intersect[8]==1)
                    {
                        num_of_intersect[9]=1;
                    }
                   // printf("d=%d\nnum_of_fallen_can=%d\n",d,num_of_fallen_can[d]);
                   /*
                      连锁反应，如果底层地矩形掉落，则判定位于该矩形上方的矩形必掉落。
                      所以可直接判定为相交。
                      */
                }
                   for(d=0,e=0;e<10;e++)
                {
                    if(num_of_intersect[e]==1)
                        d++;
                        //统计相交的矩形个数。
                }
     /*           for(e=1;e<=10;e++)
                    {
                        printf("num_of_intersect:");
                        for(f=0;f<10;f++)
                           {
                             printf("%d ",num_of_intersect[f]);
                           }
                           printf("\n");
                        printf("d=%d:(%f,%f)\n",d,b,a);
                    }
            /*         if(d==10)
                    {
                        for(f=0;f<10;f++)
                           {
                             printf("num_of_intersect:%d ",num_of_intersect[f]);
                             printf("\n");
                           }
                        printf("d=10:(%f,%f)\n",b,a);
                    }*/
                if(d>0)
                    num_of_fallen_can[d-1]++;
                    /*因为掉落的矩形只能为1到10个，而数组又是从0开始，所以有如下对应
                    num_of_fallen_can[0]对应为掉落1个矩形对应的圆心数。
                    num_of_fallen_can[1]对应为掉落2个矩形对应的圆心数
                    以此类推···；
                    */

            }
    }


   return num_of_fallen_can;
}


