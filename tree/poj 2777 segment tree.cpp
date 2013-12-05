// http://www.cnblogs.com/rainydays/archive/2011/05/14/2046419.html  
// 非常清晰的线段树的代码  染色
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100004

struct Node
{
    int color;
    int l, r;
    Node *pleft, *pright;
    bool end;
} tree[maxn * 3];

int n, t, o, ncount;

void buildtree(Node *proot, int l, int r)
{
    proot->l = l;
    proot->r = r;
    proot->color = 1;
    proot->end = true;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    ncount++;
    proot->pleft = tree + ncount;
    ncount++;
    proot->pright = tree + ncount;
    buildtree(proot->pleft, l, mid);
    buildtree(proot->pright, mid + 1, r);
}

void paint(Node *proot, int l, int r, int color)
{
    if (proot->l == l && proot->r == r)
    {
        proot->end = true;
        proot->color = color;
        return;
    }
    if (proot->end)
    {
        proot->end = false;
        proot->pleft->color = proot->color;
        proot->pleft->end = true;
        proot->pright->color = proot->color;
        proot->pright->end = true;
    }
    int mid = (proot->l + proot->r) / 2;
    if (r <= mid)
        paint(proot->pleft, l, r, color);
    else if(l > mid)
    paint(proot->pright, l, r, color);
    else
    {
        paint(proot->pleft, l, mid, color);
        paint(proot->pright, mid +1, r, color);
    }
    proot->color = proot->pleft->color | proot->pright->color;
}

int query(Node *proot, int l, int r)
{
    if (proot->end)
        return proot->color;
    if (proot->l == l && proot->r == r)
        return proot->color;
    int mid = (proot->l + proot->r) / 2;
    if (r <= mid)
        return query(proot->pleft, l, r);
    else if(l > mid)
    return query(proot->pright, l, r);
    return query(proot->pleft, l, mid) | query(proot->pright, mid + 1, r);
}

int countbit(int a)
{
    int x = 1;
    int ret = 0;
    for (int i = 0; i < 32; i++, x <<= 1)
        if (x & a)
            ret++;
    return ret;
}

int main()
{
//    freopen("t.txt", "r", stdin);
    ncount = 0;
    scanf("%d%d%d", &n, &t, &o);
    getchar();
    buildtree(tree, 1, n);
    for (int i = 0; i < o; i++)
    {
        char order;
        int l, r, c;
        scanf("%c", &order);
        if (order == 'C')
        {
            scanf("%d%d%d", &l, &r, &c);
            if (l > r)
                swap(l, r);
            paint(tree, l, r, 1 << (c - 1));
        }
        else
        {
            scanf("%d%d", &l, &r);
            if (l > r)
                swap(l, r);
            printf("%d\n", countbit(query(tree, l, r)));
        }
        getchar();
    }
    return 0;
}


