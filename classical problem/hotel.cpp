#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
 
struct Hotel
{
    int dist, cost;
    bool operator < (const Hotel &other) const
    {
        if(dist == other.dist)
        {
            return cost < other.cost;
        }
        return dist < other.dist;
    }
} hotel[MAXN];
 
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &hotel[i].dist, &hotel[i].cost);
        }
        sort(hotel, hotel + n);
        int min = MAXN, ans = 0;
        for(int i=0;i<n;++i)
        {
            if(hotel[i].cost < min)
            {
                ++ ans;
                min = hotel[i].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
