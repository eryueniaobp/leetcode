#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10010],b[10010],c[10010],stack[10010],top = 0;
int n,k;
/**
 * O(n) 
 */
int main(){
   
   cin >> n >> k ;
   memset(a,0,sizeof a);
   memset(b,0,sizeof b);
   memset(c,0,sizeof c);
   
   int s,m = 0;
   for (int i = 1;i <= k;i ++){
       cin >> s;
       for (int j = 1;j <= s;j ++){
           int p;
           cin >> p;
           a[p] = ++m; //a[p]表示第p空间的内容应该在的目标位置
           b[m] = p;  //b[m]表示最后第m空间的内容原本在的位置
       }
   }
   
   bool needed = false; //是否需要处理
   
   for (int i = 1;i <= m;i ++){
       int t = i;
       while (a[t] != t){ //t的内容不在目标位置上
           needed = true;
           if (c[t] == 1){ //访问到已做过标记的，说明是一个完整的环，就需要有一个点先跳到后面的空格，破坏为链
               for (int j = n;j > 0;j --){
                   if (a[j] == 0){
                       cout <<stack[top] <<" "<<j<<endl;
                       b[ a[stack[top]] ] = j;
                       a[j] = a[stack[top]];
                       break; 
                   }
               }
               break;
           }
           stack[++top] = t;//入栈
           if (a[t] == 0) break;//处理过了
           else c[t] = 1,t = a[t];//标记，并寻找t延伸下去的一个
       }
       while (top){//栈非空
           int to = stack[top]; //处理链上的冲突
           cout << b[to] <<" "<<to<<endl;
           a[to] = to; //更新已经处理好的点
           a[b[to]] = 0;
           b[to] = to;
           top --;
       }
       memset(c,0,sizeof c);
   }
   
   if (!needed) puts("No optimization needed");
   return 0;
}
