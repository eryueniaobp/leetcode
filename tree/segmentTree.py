class NumArray:
    
    def __init__(self, nums: List[int]):
        self.value = [0] * len(nums) * 3 
        self.len = len(nums) -1 
        if self.len >= 0:
            self.build_segment_tree(nums, 0 , 0 , self.len)

    def build_segment_tree(self, nums, pos, left , right):
        if left == right:
            self.value[pos] = nums[left]
            return 
        mid = (left + right)//2 
        self.build_segment_tree(nums, pos* 2 + 1, left, mid)
        self.build_segment_tree(nums, pos*2 + 2, mid+1, right) 
        self.value[pos] = self.value[pos* 2 + 1] + self.value[pos * 2 +2 ]
    def update_segment_tree(self, pos, left, right, index, newval):
        if left == right and left == index:
            self.value[pos] = newval
            return 
        mid = (left + right)//2 
        if index <= mid:
            self.update_segment_tree(pos * 2 + 1, left,  mid, index, newval) 
        else:
            self.update_segment_tree(pos * 2 + 2 , mid + 1 , right,index, newval) 
        self.value[pos] = self.value[pos * 2 + 1] + self.value[pos* 2 + 2]
    def sum_range_segment_tree(self, pos, left, right, qleft, qright):
        if qleft > right or qright < left:
            return 0
        if qleft <= left and qright >= right:
            return self.value[pos]
        mid = (left + right) //2 
        return self.sum_range_segment_tree(pos* 2 + 1, left , mid, qleft , qright)  +  self.sum_range_segment_tree(pos* 2 + 2, mid+1 , right, qleft , qright) 
    def update(self, i: int, val: int) -> None:
        self.update_segment_tree(0, 0 , self.len, i , val) 

    def sumRange(self, i: int, j: int) -> int:
        return self.sum_range_segment_tree(0, 0 , self.len, i, j)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
