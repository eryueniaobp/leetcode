//refer  http://hzaskywalker.blog.163.com/blog/static/203798157201271662251150/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

const int MAXA=100;
const int MAX=1000000+100;
typedef long long LL;

char str[MAX],a[MAX],b[MAX];
LL ans;
int num[MAXA],del[MAX],used[MAXA],begin[MAXA],st[MAX],next[MAX],sum[MAX],len;

void add(int x)
{
    int i;
    for(i=x;i<=len/2+1;i+=i&(-i))
        ++sum[i];
}

int ask(int x)
{
    int i,ans=0;
    for(i=x;i;i-=i&(-i))
        ans+=sum[i];
    return ans;
}

int main()
{

    int i,d=0,j,odd=0,ll=0,lr=0,t,oddc,nowc=0;
    gets(str+1);
    len=strlen(str+1);
    for(i=1;i<=len;++i)
    {
        ++num[str[i]];
    }
    for(i='A';i<='Z';++i)
        if(num[i]&1)
        {
            ++odd;
            oddc=i;
        }
    if(odd>(len&1))
    {
        printf("-1\n");
        return 0;
    }
    for(i=1;i<=len;++i)
        a[i]=str[i];
    for(i=1;i<=len/2;++i)
        ++used[a[i] ];
    ll=len/2+1;lr=len/2;
    
    for(i=len/2;i>=1;--i)
        if(used[a[i] ]>num[a[i] ]/2)
        {
            --used[a[i] ];
            --ll;
            ans+=ll-i;
            del[i]=1;
            st[ll]=a[i];
            ++d;
        }

    int top=0;
    for(i=1;i<=len/2;++i)
        if(!del[i])a[++top]=a[i];
    for(i=ll;i<=len/2;++i)
        a[++top]=st[i];

    for(i=len/2+1;i<=len;++i)
        if(used[a[i] ]<num[a[i] ]/2)
        {
            ++used[a[i] ];
            ++lr;
            ans+=i-lr;
            del[i]=1;
            st[lr]=a[i];
        }
    
    top=0;
    for(i=len;i>=len/2+1;--i)
        if(!del[i])a[len-(++top) +1 ]=a[i];
    for(i=lr;i>=len/2+1;--i)
        a[len-(++top) +1]=st[i];

    ans=ans+(LL)d*d;
    top=0;
    for(i=len/2+1;i<=lr;++i)
        st[++top]=a[i];
    for(i=ll;i<=len/2;++i)
        st[++top]=a[i];
    for(i=ll;i<=lr;++i)
        a[i]=st[i-ll+1];

    if(len&1)
    {
        for(i=1;i<=len;++i)
            if(a[i]==oddc)
            {
                ++nowc;
                if(nowc==num[oddc]/2+1)
                {
                    if(i>=len/2+1)
                    {
                        while(i!=len/2+1)
                        {
                            swap(a[i],a[i-1]);
                            --i;
                            ++ans;
                        }
                    }else
                    {
                        while(i!=len/2+1)
                        {
                            swap(a[i],a[i+1]);
                            ++i;
                            ++ans;
                        }
                    }
                    break;
                }
            }
    }

    for(i=1,j=len;i<=len/2;++i,--j)
        b[i]=a[j];
    for(i=len/2;i>=1;--i)
    {
        next[i]=begin[a[i] ];
        begin[a[i] ]=i;
    }
    for(i=1;i<=len/2;++i)
    {
        t=begin[ b[i] ];
        begin[b[i]  ]=next[begin[b[i] ]];
        ans+=i-1-ask(t);
        add(t);
    }
    printf("%I64d\n",ans);
    //system("pause");
}

