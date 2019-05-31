#encoding=utf-8
from typing import List
class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        # 很硬核的解决->回溯
        # print(nums)
        if len(nums) == 1:
            # print(nums)
            return abs(nums[0]-24) < 0.001
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                nums_ = nums.copy()
                nums_.remove(nums[i])
                nums_.remove(nums[j])
                resultList = []
                if self.judgePoint24(nums_+[nums[i]+nums[j]]) or self.judgePoint24(nums_+[nums[i]-nums[j]]) or \
                self.judgePoint24(nums_+[nums[j]-nums[i]]) or \
                 self.judgePoint24(nums_+[nums[i]*nums[j]]) or \
                 (nums[j]!=0 and self.judgePoint24(nums_+[nums[i]/nums[j]])) or \
                 (nums[i]!=0 and self.judgePoint24(nums_+[nums[j]/nums[i]])):
                    return True
        return False
