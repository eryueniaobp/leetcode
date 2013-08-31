#define CONTINUE 1 
#define BREAK 0 
#define POSSIBLE 2
class Solution {
    vector<int> _num;
    int _size;
    public:
    int possible(int pos,int cur ,int target,int len ){
        int sum = 0 ;
        for(int i = 0 ; i< len ; i ++ ){
            sum += _num[_size - 1 - i ] ; 
        }
        int zsum = 0 ;
        for(int i = 0 ; pos+i+1<_size && i< len ; i ++){
            zsum += _num[pos+i+1];
        }
        if(target >= 0 ){
            if(cur < target ) {
                if( cur + sum <target) return CONTINUE;
                return POSSIBLE ; 
            }
            if(cur >target){
                return BREAK; 
            }
            return POSSIBLE;
        }else{
            if(cur <target) {
                if( cur+sum < target ) return CONTINUE ; 
                return POSSIBLE;
            }
            if(cur>target) {
                if( cur + zsum > target ) return BREAK; 
                return POSSIBLE;
            }
            return POSSIBLE;
        }
    }
    vector<vector<int> > fourSum(vector<int> &num,int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        _num = num;
        //	copy(num.begin(),num.end(),ostream_iterator<int>(cout," "));
        //	cout<<endl;
        int size = num.size();
        _size = size;
        vector<vector<int> > ret;
        vector<int> vset;
        if(size == 0 ) {
            return  ret;
        }
        unordered_set<int> tag;
        unordered_set<int> tag1;
        unordered_set<int> tag2;
        unordered_set<int> tag3;
        int p =  0 ;
        for(int i = 0 ;i<size; i ++ ){
            p = possible(i,num[i],target,3) ;
            //	cout<<"pass i = " << i <<endl;
            if( p == CONTINUE )       continue;
            if( p == BREAK ) break;

            if(tag.find(num[i]) != tag.end() ) continue; 
            tag.insert(num[i]);
            for(int j = i +1 ; j<size; j++){

                p = possible(j, num[i]+num[j],target,2) ; 
                if( p == CONTINUE )       continue;
                if( p == BREAK ) break;
                if(tag1.find(num[j]) != tag1.end()) continue; 
                tag1.insert(num[j]);
                for(int k = j + 1; k<size; k++){


                    p = possible(k,num[i]+num[j]+num[k],target, 1) ; 
                    if( p == CONTINUE )       continue;
                    if( p == BREAK ) break;
                    if(tag2.find(num[k]) != tag2.end()) continue; 
                    tag2.insert(num[k]);
                    for(int l = k+1; l<size; l++){
                        p = possible(k,num[i]+num[j]+num[k]+num[l],target, 0) ;
                        if( p == CONTINUE )       continue;
                        if( p == BREAK ) break;

                        if(tag3.find(num[l]) != tag3.end()) continue;  
                        tag3.insert(num[l]);
                        if(num[i] + num[j] + num[k] + num[l] == target ) {
                            vset.push_back(num[i]);
                            vset.push_back(num[j]);
                            vset.push_back(num[k]);
                            vset.push_back(num[l]);
                            ret.push_back(vset);
                            vset.clear();
                        }
                    }
                    tag3.clear();
                }
                tag2.clear();
            }
            tag1.clear();
        }
        return ret;
    }
};

