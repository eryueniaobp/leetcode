
"""
https://leetcode-cn.com/problems/cat-and-mouse/  
思路：
将该问题视为状态方程，状态公式[mouse,cat,turn]代表老鼠的位置，猫的位置，下一步轮到谁走
猫胜利的状态为[i,i,1]或[i,i,2]（i!=0），1代表老鼠走，2代表猫走
老鼠胜利的状态为[0,i,1]或[0,i,2]
用0代表未知状态，1代表老鼠赢，2代表猫赢
由最终的胜利状态，回推
假如当前父节点轮次是1（父节点轮次是2同样的道理）
父节点=1 if 子节点是1
或者
父节点=2 if 所有子节点是2
"""
class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        n = len(graph)
        draw, mouse, cat = 0, 1, 2
        
        #获得任意节点的所有父节点
        def parent(m, c, t):
            if t == 1:
                for i in graph[c]:
                    if i:
                        yield m, i, 3 - t
            else:
                for i in graph[m]:
                    yield i, c, 3 - t
 
        color = collections.defaultdict(int)
        color[0, 0, 1] = mouse
        color[0, 0, 2] = mouse
        queue = []
        degree = collections.defaultdict(int)
        # 计算父节点的子节点数目
        for i in range(n):
            for j in range(n):
                degree[i, j, 1] = len(graph[i])
                degree[i, j, 2] = len(graph[j]) - (0 in graph[j])
        # 计算已知节点
        for i in range(1, n):
            for j in range(1, 3):
                color[i, i, j] = cat
                color[0, i, j] = mouse
                queue.append((i, i, j, cat))
                queue.append((0, i, j, mouse))
        while queue:
            m, c, t, w = queue.pop(0)
            for mp, cp, tp in parent(m, c, t):
                if not color[mp, cp, tp]:
                    if tp == w:
                        color[mp, cp, tp] = w
                        queue.append([mp, cp, tp, color[mp, cp, tp]])
                    else:
                        degree[mp, cp, tp] -= 1
                        if not degree[mp, cp, tp]:
                            color[mp, cp, tp] = w
                            queue.append([mp, cp, tp, color[mp, cp, tp]])
        return color[1, 2, 1]
