/**
 * O(n) 
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        for(int i = 0; i < n; i++)
            if (elem != A[i])
            {
                A[start++] = A[i];
            }
            
        return start;
    }
};

