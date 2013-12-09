// http://hi.baidu.com/sjzezoi/item/42def37f365723136e29f60d 
#include<cstdio>
int T,k,cnt,ans[100];
long long n;
char s[100];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s%lld",&k,s,&n);
        cnt=0;
        while(cnt<k)
        {
            if(n&1)
            {
                ans[cnt]=1;
                if(s[k-cnt-1]=='p') n-=1;
                else n+=1;
            }
            else ans[cnt]=0;
            n>>=1;
            cnt++;
        }
        if(n) printf("Impossible");
        else
            for(int i=k-1;i>=0;i--)
                printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}


