class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ,j = 0 ;
        vector<int> iv ; 
        while(i<m && j < n) {
            if(A[i] < B[j] ){
                iv.push_back(A[i++]);
            }else{
                iv.push_back(B[j++]);
            }
        }
        while(i<m){
            iv.push_back(A[i++]);
        }
        while(j<n){
            iv.push_back(B[j++]);
        }
        for(int i =  0 ;i< m +n ; i++){
            A[i] = iv[i];
        }
    }
};

