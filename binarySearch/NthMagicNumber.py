import math 
class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        if N == 1:
            return min(A,B)
        C = A*B/math.gcd(A,B)
        left = min(A,B)
        right = left*N
        while left<right:
            mid = (left+right)//2
            temp = mid//A+mid//B-mid//C
            if temp>N:
                right = mid-1
            elif temp<N:
                left = mid+1
            elif mid%A!=0 and mid%B!=0:
                right = mid-1
            else:
                return mid%(10**9+7)
        return left%(10**9+7)
