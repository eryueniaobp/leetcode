//http://www.cnblogs.com/kuangbin/archive/2011/08/04/2126809.html#2810063
/*
   在遥远的国家佛罗布尼亚，嫌犯是否有罪，须由陪审团决定。陪审团是
   由法官从公众中挑选的。先随机挑选n 个人作为陪审团的候选人，然后
   再从这n 个人中选m 人组成陪审团。选m 人的办法是：控方和辩方会
   根据对候选人的喜欢程度，给所有候选人打分，分值从0 到20。为了
   公平起见，法官选出陪审团的原则是：选出的m 个人，必须满足辩方
   总分和控方总分的差的绝对值最小。如果有多种选择方案的辩方总分
   和控方总分的之差的绝对值相同，那么选辩控双方总分之和最大的
   方案即可。最终选出的方案称为陪审团方案。
   为叙述问题方便，现将任一选择方案中，辩方总分和控方总分
   之差简称为“辩控差”，辩方总分和控方总分之和称为“辩控和”。
   第i 个候选人的辩方总分和控方总分之差记为V(i)，辩方总分和控
   方总分之和记为S(i)。现用f(j, k)表示，取j 个候选人，使其辩
   控差为k 的所有方案中，辩控和最大的那个方案（该方案称为“方
   案f(j, k)”）的辩控和。并且，我们还规定，如果没法选j 个人，
   使其辩控差为k，那么f(j, k)的值就为-1，也称方案f(j, k)不可行。
   本题是要求选出m 个人，那么，如果对k 的所有可能的取值，求
   出了所有的f(m, k) (-20×m≤ k ≤ 20×m)，那么陪审团方案
   自然就很容易找到了。
   问题的关键是建立递推关系。需要从哪些已知条件出发，
   才能求出f(j, k)呢？显然，方案f(j, k)是由某个可行的方案f(j-1, x)
   ( -20×m ≤ x ≤ 20×m)演化而来的。可行方案f(j-1, x)能演化成
   方案f(j, k)的必要条件是：存在某个候选人i，i 在方案f(j-1, x)中
   没有被选上，且x+V(i) = k。在所有满足该必要条件的f(j-1, x)中，
   选出 f(j-1, x) + S(i) 的值最大的那个，那么方案f(j-1, x)再加上候选人i，
   就演变成了方案 f(j, k)。这中间需要将一个方案都选了哪些人都记录下来。
   不妨将方案f(j, k)中最后选的那个候选人的编号，记在二维数组的
   元素path[j][k]中。那么方案f(j, k)的倒数第二个人选的编号，
   就是path[j-1][k-V[path[j][k]]。假定最后算出了解方案的辩控差是k，
   那么从path[m][k]出发，就能顺藤摸瓜一步步求出所有被选中的候选人。
   初始条件，只能确定f(0, 0) = 0。由此出发，一步步自底向上递推，
   就能求出所有的可行方案f(m, k)( -20×m ≤ k ≤ 20×m)。实际解题
   的时候，会用一个二维数组f 来存放f(j, k)的值。而且，由于题目中辩
   控差的值k 可以为负数，而程序中数租下标不能为负数，所以，在程序中
   不妨将辩控差的值都加上400，以免下标为负数导致出错，即题目描述中，
   如果辩控差为0，则在程序中辩控差为400。
   */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
usingnamespace std;
int f[30][1000];
//f[j,k]表示：取j个候选人，使其辩控差为k的方案中
//辩控和最大的那个方案（该方案称为“方案f(j,k)”)的控辩和
int Path[30][1000];
//Path数组用来记录选了哪些人
//方案f(j,k)中最后选的那个候选人的编号，记在Path[j][k]中
int P[300];//控方打分 
int D[300]; //辩方打分

int Answer[30];//存放最终方案的人选

int cmp(constvoid*a,constvoid*b)
{
    return*(int*)a-*(int*)b;
}     
int main()
{
    int i,j,k;
    int t1,t2;
    int n,m;
    int nMinP_D;//辩控双方总分一样时的辩控差
    int iCase;//测试数据编号
    iCase=0;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)break;
        iCase++;
        for(i=1;i<=n;i++)
            scanf("%d %d",&P[i],&D[i]);
        memset(f,-1,sizeof(f));
        memset(Path,0,sizeof(Path));
        nMinP_D=m*20;//题目中的辩控差为0，对应于程序中的辩控差为m*20
        f[0][nMinP_D]=0;
        for(j=0;j<m;j++)//每次循环选出第j个人，共要选出m人 
        {
            for(k=0;k<=nMinP_D*2;k++)//可能的辩控差为[0，nMinP_D*2] 
                if(f[j][k]>=0)//方案f[j,k]可行 
                {
                    for(i=1;i<=n;i++)
                        if(f[j][k]+P[i]+D[i]>f[j+1][k+P[i]-D[i]])
                        {
                            t1=j;t2=k;
                            while(t1>0&&Path[t1][t2]!=i)//验证i是否在前面出现过
                            {
                                t2-=P[Path[t1][t2]]-D[Path[t1][t2]];
                                t1--;
                            }
                            if(t1==0)
                            {
                                f[j+1][k+P[i]-D[i]]=f[j][k]+P[i]+D[i];
                                Path[j+1][k+P[i]-D[i]]=i;
                            }         
                        }    
                }    
        }

        i=nMinP_D;
        j=0;
        while(f[m][i+j]<0&&f[m][i-j]<0)  j++; // i+j i-j 的辩控差的绝对值是相等的
        if(f[m][i+j]>f[m][i-j])  k=i+j;
        else k=i-j;
        printf("Jury #%d\n",iCase);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",(k-nMinP_D+f[m][k])/2,(f[m][k]-k+nMinP_D)/2);
        for(i=1;i<=m;i++)
        {
            Answer[i]=Path[m-i+1][k]; 
            k-=P[Answer[i]]-D[Answer[i]];
        }
        qsort(Answer+1,m,sizeof(int),cmp);
        for(i=1;i<=m;i++)  
            printf(" %d",Answer[i]);
        printf("\n\n");     

    }  
    return0;   
}

