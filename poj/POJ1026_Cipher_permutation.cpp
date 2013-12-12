// http://lolita-angel.diandian.com/post/2012-10-14/40040336019 
/*
    置换群计算循环节个数。 
    问题描述：给一个置换群， 然后 给出一个字符串 需要让你帮他加密M次。。。 然后输出 结果。。
        其中 原串不足的地方用‘ ’补足。。。  结果 最后不要多余的‘ ’
*/
#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cstdio"
#define N 212
using namespace std;
int n;
int key[N];
int t[N];
inline void get_time(){
    int count=0;
    for (int i=1;i<=n;i++){
        int j=key[i];
        count=1;
        while(i!=j){
            count++;
            j=key[j];   
        }
        t[i]=count;
    }
}
char str[N];
char res[N];
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        memset(t,0,sizeof(int)*(n+2));
        for (int i=1;i<=n;i++) scanf("%d",&key[i]);
        get_time();
        int k;
        while(scanf("%d",&k)!=EOF&&k){
            getchar();
            gets(str+1);
            for (int i=strlen(str+1)+1;i<=n;i++) str[i]=' ';
            str[n+1]='\0';
            for (int i=1;i<=n;i++){
                int pos=i;
                for (int j=0;j<k%t[i];j++){
                    pos=key[pos];
                }
                res[pos]=str[i];
            }
            res[n+1]='\0';
            printf("%s\n",res+1);
        }
        puts("");
    }
    return 0;
}

