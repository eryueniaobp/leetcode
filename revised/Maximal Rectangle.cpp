/**
 * O(m*n ) 的总效率
 */
class Solution {
    int left[1000];
    int right[1000];
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = matrix.size();
        if(l == 0 ) return 0 ;
        int c = matrix[0].size();
        deque<int> oned; 
        vector<vector<int> >tag(l);
        for(int i = 0 ; i< l ; i++){
            int j = 0 ;
            while(j<c){
                char ch = matrix[i][j];
                if(ch == '1' ){
                    oned.push_back(j);
                    j++;
                }else{
                    while(!oned.empty()){
                        int s = oned.size();
                        int k = oned.front();
                        oned.pop_front();
                        tag[i].push_back(s);
                    }
                    tag[i].push_back(0);
                    j++;
                }
            }
            while(!oned.empty()){
                tag[i].push_back(oned.size());
                oned.pop_front();
            }
        }
        int max = INT_MIN;
        for(int i =  0 ; i<c ; i ++ ){
           for( int j = 0 ; j < l ;j ++ ){
                left[j] = right[j] = j ; 
           }
           for( int j = 0 ; j< l ; j ++ ) {
               while( left[j] > 0 && tag[j][i] <= tag[ left[j] - 1 ] [i] ) {
                   left[j] = left [ left[j] - 1 ] ; 
               }
           }
           for ( int j = l-1 ; j>=0 ;j -- ) {
               while (right[j] < l-1 && tag[j][i] <= tag[ right[j] + 1 ] [i] ) {
                   right[j] = right[ right[j] + 1 ] ;
               }
           }
           for( int  j = 0 ; j < l ; j++ ){
               int tmp = tag[j][i] * ( right[j] - left[j] + 1 ) ; 
               if(tmp > max ) {
                   max =tmp ;
               }
           }
        }
        return max;
    }
};

