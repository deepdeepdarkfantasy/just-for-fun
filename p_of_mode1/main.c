#include <stdio.h>
#include <math.h>
long long factorial(int m, int n)
{
    long long ans = 1;	if(m < n-m) m = n-m;
    for(int i = m+1; i <= n; i++)
    ans *= i;
    for(int j = 1;j <= n - m; j++)
        ans /= j;	return ans;
}
    int main()
    {	int i, n;	long long count = 0;
    float p1,p2,p3;
    for(n=1;n<=20;n++)
    {
        p2=0;
        for(i=1;i<=n;i++)
        {
            count = factorial(i, n);
            p2+=(count*pow(0.23,i)*pow(0.73,n-i));
        }
        p1=pow(0.73,n);
        p3=1-pow(0.96,n);
        printf("n=%d\nP(该批次车最终耗时t含于A)=%f\nP(该批次车最终耗时t含于B)=%f\nP(该批次车最终耗时t含于C)=%f \n",n,p1,p2,p3);
       // count = factorial(m, n);	printf("%I64d", count);
       }
       return 0;
    }
