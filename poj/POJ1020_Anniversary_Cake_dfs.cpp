// http://blog.csdn.net/lyy289065406/article/details/6683250
//Memory Time 
//208K  32MS 
// tip: 先选择空格最多的一列，再选最大的填进去。 启发式规则 

#include<iostream>
using namespace std;

int BoxSize;      //盒子尺寸
int n;            //蛋糕的总个数
int SizeNum[11];  //各种尺寸的蛋糕个数
int col[41];      //把盒子纵行分割成BoxSize*BoxSize个1*1大小的小格子
//col[i]记录第i列被填充了的格子数

bool DFS(int FillNum)   //FillNum:已放入盒子的蛋糕数
{
    if(FillNum==n)
        return true;

    /*寻找格子数被填充最少的列，靠左优先*/
    int min=50;
    int prow;
    for(int i=1;i<=BoxSize;i++)
        if(min>col[i])
        {
            min=col[i];
            prow=i;
        }

    /*枚举各种尺寸的蛋糕自下而上地放入盒子*/
    for(int size=10;size>=1;size--)
    {
        if(!SizeNum[size])
            continue;

        //检查尺寸为size的蛋糕放入盒子时在纵向和横向是否越界
        if(BoxSize-col[prow]>=size && BoxSize-prow+1>=size)
        {
            //检查盒子从第prow列到第prow+size-1列，共size列的宽度wide中
            //是否每列剩余的空间都足够放入高度为size的蛋糕
            int wide=0;
            for(int r=prow;r<=prow+size-1;r++)
            {
                if(col[r]<=col[prow])  //比较各列的"填充数"
                {    //注意，这里若比较"未填充数"BoxSize-col[r]<size会TLE
                    wide++;       //虽然两个条件等价，但确实计算了3秒左右，不知何故
                    continue;
                }
                break;
            }

            if(wide>=size)
            {
                int r;
                //放入尺寸为size的蛋糕
                SizeNum[size]--;
                for(r=prow;r<=prow+size-1;r++)
                    col[r]+=size;

                if(DFS(FillNum+1))
                    return true;

                //回溯
                SizeNum[size]++;
                for(r=prow;r<=prow+size-1;r++)
                    col[r]-=size;
            }
        }
    }
    return false;
}

int main(void)
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        memset(SizeNum,0,sizeof(SizeNum));
        memset(col,0,sizeof(col));

        cin>>BoxSize>>n;

        int cnt=0;   //记录size>(BoxSize/2)的蛋糕个数
        int area=0;  //计算所有蛋糕的面积之和
        for(int i=1;i<=n;i++)
        {
            int size;
            cin>>size;
            area+=size*size;
            SizeNum[size]++;

            if(size>BoxSize/2)
                cnt++;
        }

        if(cnt>1 || area!=BoxSize*BoxSize)
        {
            cout<<"HUTUTU!"<<endl;
            continue;
        }

        if(DFS(0))
            cout<<"KHOOOOB!"<<endl;
        else
            cout<<"HUTUTU!"<<endl;
    }
    return 0;
}

