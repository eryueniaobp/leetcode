// http://lintcode.com/zh-cn/problem/find-a-peak/ 
// There is an integer array which has the following features: 
// The numbers in adjacent positions are different. 
// A[0] < A[1] && A[A.length - 2] > A[A.length - 1]. 
// We define a position P is a peek if A[P] > A[P-1] && A[P] > A[P+1]. 
// Find a peak in this array. Return the index of the peak.
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> num) {
        // write your code here
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};



