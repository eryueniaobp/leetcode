
class Solution:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        win, ret = [] ,  []
        
        """
        win 是 单调栈，简单看时间负责度是 O(k*N) 但实际上远快于这个速度..  甚至要比使用 堆 的算法都快 
        """
        for i , v in enumerate(nums):
            if i >= k and win[0] <= i-k : win.pop(0)
            while win and nums[win[-1]] <= v: win.pop() 
            win.append(i) 
            if i >= k -1 : ret.append(nums[win[0]])
        return ret 
        
        
import heapq
class Solution:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ret = []
        N = len(nums)
        if N == 0: return []


        H = []
        j =0
        while j < k:
            heapq.heappush(H, (-nums[j], j))
            j += 1


        j = k
        while j < N:
            while True:
                prev, idx  = H[0]
                if idx >= j - k :
                    break
                else:
                    heapq.heappop(H)

            ret += [prev ]

            heapq.heappush(H , (-nums[j], j ))

            j += 1
        while True:
            prev, idx = heapq.heappop(H)
            if idx >= j - k:
                break
        ret += [prev]
        return [ -i for i in ret ]
