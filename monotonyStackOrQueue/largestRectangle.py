# 暴力解法是 O(n*2)  单调栈稍微好一些.. 这里是单调递增栈> 
class Solution(object):
    def largestRectangleArea(self, heights):
        s = []
        res = 0
        # 可以保证在最后总会计算
        heights.append(0)
        
        for i in range(len(heights)):
            # 当前位置小于栈顶位置时计算
            while s and heights[s[-1]] > heights[i]:
                h = heights[s.pop()]
                # i-s[-1]-1 和 i 是底
                area = h * (i-s[-1]-1 if s else i)
                res = max(res,area)
            s.append(i)
        return res
       
