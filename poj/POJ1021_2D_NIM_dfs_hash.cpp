// poj 1021 2D-Nim
/*

别看它名字，其实这题跟Nim游戏一点关系都没有，是判断棋盘上两个连通分支（经过翻转、镜像后）是否等价 
做了本题才知道可以用hash来判断，不然可能真的要八种情况都考虑 ，那样会写死人。。。hash方法很巧妙，见代
码 ，本题 0 Ms(数据太弱)，再接再厉！

*/ 
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1<<29;
int n,m,k,c,mini,minj,maxi,maxj;
int grid[2][110][110];
int move[4][2]={0,1,1,0,0,-1,-1,0};
int id[2][110][110],cnt[2];
struct node {
     int mini,maxi,minj,maxj;
     int hash;
}stock[2][10000];
int xx[10000],yy[10000];


void dfs(int j,int v,int w)
{
     xx[c]=v;yy[c++]=w;

     if (v<=mini && w<=minj) mini=v,minj=w;
     if (v>=maxi && w>=maxj) maxi=v,maxj=w;

     id[j][v][w]=cnt[j];
     int x,y;
     for (int i=0;i<4;i++)
     {
         x=v+move[i][0],y=w+move[i][1];
         if (x>=0 && x<n && y>=0 && y<m && grid[j][x][y] && id[j][x][y]==-1)
         dfs(j,x,y);
     }
}

int cmp(node a,node b)
{
    return a.hash<b.hash;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d%d%d",&n,&m,&k);
          int a,b;
          memset(grid,0,sizeof(grid));
          for (int i=0;i<k;i++)
          {
           scanf("%d%d",&a,&b);
           grid[0][a][b]=1;
          }
          for (int i=0;i<k;i++)
          {
              scanf("%d%d",&a,&b);
              grid[1][a][b]=1;
          }
          
          memset(id,-1,sizeof(id));
          cnt[0]=cnt[1]=0;
          for (int v=0;v<2;v++)
              for (int i=0;i<n;i++)
                  for (int j=0;j<m;j++)
                      if (grid[v][i][j] && id[v][i][j]==-1)
                      {
                          ++cnt[v];
                          mini=minj=inf;
                          maxi=maxj=-1;
                          c=0;
                          dfs(v,i,j);
                          stock[v][cnt[v]].mini=mini;
                          stock[v][cnt[v]].minj=minj;
                          stock[v][cnt[v]].maxi=maxi;
                          stock[v][cnt[v]].maxj=maxj;
                          stock[v][cnt[v]].hash=0;
                          for (int ii=0;ii<c;ii++) //hash函数，连通分支的棋子两两距离和，这里距离就不开方了，一样的 
                              for (int jj=ii+1;jj<c;jj++)
                              {
                                  stock[v][cnt[v]].hash+=(xx[ii]-xx[jj])*(xx[ii]-xx[jj])+(yy[ii]-yy[jj])*(yy[ii]-yy[jj]);
                              }

                      }
         // printf("%d %d/n",cnt[0],cnt[1]);
          if (cnt[0]!=cnt[1]) printf("NO\n");
          else {
               sort(stock[0]+1,stock[0]+1+cnt[0],cmp);
               sort(stock[1]+1,stock[1]+1+cnt[1],cmp);  
               int i;

               for (i=1;i<=cnt[0];i++){
                   if (stock[0][i].hash!=stock[1][i].hash)
                       break;
               }

               if (i>cnt[0]) printf("YES\n");
               else printf("NO\n");             
          }
          
    }
    
   // system("pause");
    return 0;
}


