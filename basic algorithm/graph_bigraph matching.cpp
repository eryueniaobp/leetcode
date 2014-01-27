//ref: http://qa4862741.blog.163.com/blog/static/56587549201072492131195/   
/**
 * 消除增广路径 最终找到最大值即可
 */
#define N 205 
int useify[N];  // 记录y中节点是否使用
int link[N];  // 记录当前与y节点相连的x的节点
int mat[N][N];// 记录连接x和y的边，如果i和j之间有边则为1，否则为0
int gx,gy;    //二分图中x和y中点的数目

int can(int t) //DFS的过程
{ 
    int i; 
    for(i=1;i<=gy;i++) 
    { 
        if(useify[i]==0 && mat[t][i]) 
        { 
            useify[i]=1; 
            if(link[i]==-1||can(link[i])) 
            { 
                link[i]=t; 
                return 1; 
            } 
        } 
    } 
    return 0; 
} 

int MaxMatch() //主函数中调用它就能求得二分图最大匹配
{ 
    int i,num; 
    num=0; 
    memset(link,0xff,sizeof(link)); 
    for(i=1;i<=gx;i++) 
    { 
        memset(useify,0,sizeof(useify)); 
        if(can(i)) num++; 
    } 
    return num; 
} 
