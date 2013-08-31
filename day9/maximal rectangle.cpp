class Solution {
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
            int j = 0 ;
            while(j<l){
                int t = j ;
                while(t>=0 && tag[t][i] >= tag[j][i] ) t--;
                int k = j;
                while(k<l && tag[k][i] >= tag[j][i] ) k++;
                
                int cur =( (j-t) + (k-j)  - 1 ) * tag[j][i] ;
                if(cur > max){
                    max = cur;
                }
                j++;
            }
        }
        return max;
    }
};

