#include <stdio.h>


int main(void)
{
    int n,i,j,count;
    int output[50]={0};
    n = i = j = count = 0;

    scanf("%d", &n);

    for (i=2,j=0; i<50; i++,j++)
    {
        output[j] = i;
        count += i;
        if (count > n)
        {
            count -= i;
            j--;
            break;
        }
    }
    //printf("%d\n", j);

    count = n-count;

    i = j;
    while (count-- > 0)
    {
        output[i]++;
        i--;
        if (i<0)
            i = j;
    }

    for (i=0; i<=j; i++)
    {
        printf("%d ", output[i]);
    }


    getchar();getchar();
    return 0;
}
