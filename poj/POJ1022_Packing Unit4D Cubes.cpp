// http://www.2cto.com/kf/201209/153339.html 
# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# define get(x) (((x-1)&((1 << 31) - 2)+((x-1)&1)^1)+1) 
# define DEBUG 
 
int s[111][11]; 
int use[111]; 
int check[111]; 
int re[111]; 
 
int go(int x, int n) { 
    for (int i = 1; i <= n; ++ i){ 
        if(re[i] == x) return i; 
    } 
} 
 
int check1(int n) { 
    for (int i = 1; i <= n; ++ i) { 
        for (int j = 1; j <= 8; ++ j) { 
            if (s[i][j] && s[go(s[i][j], n)][get(j)] != re[i]) return 1; 
        } 
    } 
    return 0; 
} 
 
int dfs(int x, int n) { 
    if(check[x]) return 0; 
    check[x] = 1; 
    for (int i = 1; i <= 8; ++ i) { 
        if(s[x][i]) { 
            int t = go(s[x][i], n); 
            use[t] = 1; 
            dfs(t,n); 
        } 
    } 
    return 0; 
} 
 
int check2(int n, int x) { 
    dfs(x,n); 
    for (int i = 1; i <= n; ++ i) { 
        if (!use[i]) return 1; 
    } 
    return 0; 
} 
 
int getAns(int n) { 
    int x[5]; 
    memset(x, 0, sizeof(x)); 
    for (int i = 1; i <= n; ++ i) { 
        for (int j = 1; j <= 8; ++ j) { 
            if(s[i][j]) { 
                ++ x[(j + 1) >> 1]; 
            } 
        } 
    } 
    int su = 1; 
    for (int i = 1; i <= 4; ++ i) { 
        su *= (x[i] >> 1) + 1; 
    } 
    printf ("%d\n", su); 
    return 0; 
} 
 
int main () { 
    int ts; 
    for (scanf("%d", &ts); ts; -- ts) { 
        int n; 
        scanf("%d", &n); 
        memset(s, 0, sizeof(s)); 
        memset(use, 0, sizeof(use)); 
        memset(check, 0, sizeof(check)); 
        memset(re, 0, sizeof(re)); 
        int t; 
        for (int i = 1; i <= n; ++ i) { 
            scanf("%d", &t); 
            re[i] = t; 
            s[i][0] = t; 
            for (int j = 1; j <= 8; ++ j) { 
                scanf("%d", &s[i][j]); 
            } 
        }   
        //printf ("%d %d", check1(n), check2(n, t)); 
        if(check1(n) || check2(n, 1)) { 
            printf ("Inconsistent\n"); 
        } 
        else { 
            getAns(n); 
        } 
    } 
 
 
 
    return 0; 
} 


