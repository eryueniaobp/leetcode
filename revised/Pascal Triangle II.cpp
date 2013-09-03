/**
 * C(n,k)  n line ; k kth element
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rowIndex++;
        vector<double> ans(rowIndex, 0);
        vector<int> fans(rowIndex,0);
    	for(int i = 0 ; i<rowIndex ;i++){
			if(i == 0 ) {
				ans[i] = 1;
			}else{
				ans[i] =  ans[i-1]*((rowIndex - i)/(double)i);
			}
            fans[i] = ans[i];
		}	
        
		return fans;
    }

};


