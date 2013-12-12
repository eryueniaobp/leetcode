// http://blog.csdn.net/atupal/article/details/7956040
# include <stdlib.h>  
# include <string.h>  
# include <stdio.h>  
# define DEBUG  
  
int w, h;  
int used[110][110];  
int wall[100][100][4];  
int unuse[100][100];  
int from[100][100];  
char way[10000];  
int data[100][100];  
int m;  
int ex, ey;  
int xx[] = {1,-1,0,0};  
int yy[] = {0,0,1,-1};  
  
int is_block(int x1, int y1, int x2, int y2) {  
    if (x1 >= w || x1 < 0) return 1;  
    if (x2 >= w || x2 < 0) return 1;  
    if (y1 >= h || y1 < 0) return 1;  
    if (y2 >= h || y2 < 0) return 1;  
    for (int i = 0; i < 4; ++ i) {  
        if (wall[x1][y1][i]) {  
            int x = wall[x1][y1][i] / 100;  
            int y = wall[x1][y1][i] % 100;  
            if (x == x2 && y == y2) return 1;  
        }  
        if (wall[x2][y2][i]) {  
            int x = wall[x2][y2][i] / 100;  
            int y = wall[x2][y2][i] % 100;  
            if (x == x1 && y == y1) return 1;  
        }  
    }  
    return 0;  
}  
  
  
  
  
int make_the_way() {  
    int k = (int)strlen(way);  
    char away[k + 1];  
    memset(away, 0, sizeof(away));  
    int xxx = ex;   
    int yyy = ey;  
    for (int i = k - 1; i >= 0; -- i) {  
        if (xxx - from[xxx][yyy] / 100 == -1) {  
            away[i] = 'L';  
            if (way[i] != 'L') return -1;  
        }  
        if (xxx - from[xxx][yyy] / 100 == 1) {  
            away[i] = 'R';  
            if (way[i] != 'R') return -1;  
        }  
        if (yyy - from[xxx][yyy] % 100 == -1) {  
            away[i] = 'D';  
            if (way[i] != 'D') return -1;  
        }  
        if (yyy - from[xxx][yyy] % 100 == 1) {  
            away[i] = 'U';  
            if (way[i] != 'U') return -1;  
        }  
        int t = from[xxx][yyy];  
        xxx = t / 100;  
        yyy = t % 100;  
        data[xxx][yyy] = k - i;  
    }  
    away[k] = '\0';  
    return 0;  
}  
  
int bfs(int, int, int, int);  
int abs(int a) {  
    return a > 0 ? a : -a;  
}  
  
int min(int a, int b) {  
    return a > b ? b : a;  
}  
  
int is_unuse() {  
    int k = strlen(way);  
    for (int x1 = 0; x1 < w; ++ x1) {  
        for (int y1 = 0; y1 < h; ++ y1) {  
            for (int x2 = 0; x2 < w; ++ x2) {  
                for (int y2 = 0; y2 < h; ++ y2) {  
                    if (is_block(x1, y1, x2, y2)) {  
                        int b1 = abs(bfs(0, 0, x1, y1));  
                        int b2 = abs(bfs(0, 0, x2, y2));  
                        int e1 = abs(bfs(x1, y1, ex, ey));  
                        int e2 = abs(bfs(x2, y2, ex, ey));  
                        int t = min(b1 + e2 + 1, b2 + e1 + 1);  
                        if (t > k) return 1;  
                    }  
                }  
            }  
        }  
    }  
    return 0;  
}  
  
int bfs(int bx, int by, int ex, int ey) {  
    if(bx == ex && by == ey) return 0;  
    int head = 0;  
    int tail = 0;  
    int step = 0;  
    int queue[10010];  
    int ans = 0;  
    memset(queue, 0, sizeof(queue));  
    memset(used, 0, sizeof(used));  
    queue[0] = bx * 100 + by;  
    while (tail >= head) {  
        ++ step;  
        int size = tail - head;  
        for (int i = head; i <= size + head; ++ i) {  
            int x1, y1, x2, y2;  
            x1 = queue[i] / 100;  
            y1 = queue[i] % 100;  
            used[x1][y1] = 1;  
            for (int j = 0; j < 4; ++ j) {  
                x2 = x1 + xx[j];  
                y2 = y1 + yy[j];  
                if (!used[x2][y2] && !is_block(x1, y1, x2, y2)) {  
                    from[x2][y2] = queue[i];  
                    //printf("%d is from %d\n", x2 * 100 + y2, from[x2][y2]);  
                    used[x2][y2] = 1;  
                    ++ tail;  
                    queue[tail] = x2 * 100 + y2;  
                    if (x2 == ex && y2 == ey) {  
                        ++ ans;  
                    }  
                }  
            }  
        }  
        if (ans > 1) return -step;  
        if (ans == 1){   
            return step;  
        }  
        head += size + 1;  
    }  
    return 10010;  
}  
  
int main() {  
    int ts;  
    for (scanf("%d", &ts); ts; -- ts) {  
        scanf("%d %d\n%s\n%d", &w, &h, way, &m);  
        memset(from, 0, sizeof(from));  
        memset(unuse, 0, sizeof(unuse));  
        memset(wall, 0, sizeof(wall));  
        for (int i = m; i; -- i) {  
            int x1, y1, x2, y2;  
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);  
            for (int i = 0; i < 4; ++ i) {  
                if(!wall[x1][y1][i]) {  
                    wall[x1][y1][i] = x2 * 100 + y2;  
                    break;  
                }  
            }  
            unuse[x1][y1] = unuse[x2][y2] = 1;  
        }  
        ex = 0; ey = 0;  
        for (int i = 0; i < (int)strlen(way); ++ i) {  
            switch(way[i]) {  
                case 'R' : ++ ex; break;  
                case 'U' : ++ ey; break;  
                case 'L' : -- ex; break;  
                case 'D' : -- ey; break;  
            }  
        }  
        int t = bfs(0, 0, ex, ey);  
        if (!make_the_way() && !is_unuse()){  
            printf("CORRECT\n");  
        }  
        else {  
            printf("INCORRECT\n");  
        }  
    }  
    return 0;  
}  


