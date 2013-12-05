// http://www.cnblogs.com/jiaohuang/archive/2010/10/16/1853206.html 
// poj 1050
// 时间效率  O(n^3) 空间 O(n^2) 
#include <cstdio>
#include <cstring>

 using namespace std;

 #define MX 110
 int num[MX][MX];

 int MaxSum(int n , int *a){
    int i , j , ret;
    int t[MX];
    ret = a[0];
    t[0] = a[0];
    for(i=1 ; i<n ; i++){
        if( a[i]+t[i-1] > a[i])t[i] = t[i-1] + a[i];
        else t[i] = a[i];
        if(t[i] > ret)ret = t[i];
    }
    return ret;
}

int MaxSum2( int n , int a[][MX]){
    int i , j , k;
    int sum = -0x7FFFFFFF;
    int b[MX];
    for(i=0 ; i<n ; i++)
    {
        memset(b , 0 , sizeof(b));
        for(j=i ; j<n ; j++)
        {
            for(k=0 ; k<n ; k++)b[k] += a[j][k];
            int max = MaxSum(n , b);
            if(max > sum)sum = max;
        }
    }
    return sum;
}

int main(){
    int i, j , N;
    scanf("%d" , &N );
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<N ; j++)
            scanf("%d" , &num[i][j]);
    }

    printf("%d\n" , MaxSum2(N , num) );
    return 0;
}

