class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        vector<vector<int> > ret;
        vector<int> vset;
        if(size == 0 ) {
            return  ret;
        }
        sort(num.begin(),num.end());
        unordered_set<int> tag;
        unordered_set<int> tag1;
        unordered_set<int> tag2;

        for(int i = 0 ;num[i]<=0 && i<size; i ++ ){
            if(tag.find(num[i]) != tag.end()){
                continue;
            }
            tag.insert(num[i]);
            for(int j = i +1 ; j<size; j++){
                if(num[i] + num[j] > 0 ) {
                    break;
                }
                if(tag1.find(num[j]) != tag1.end()){
                    continue;
                }
                tag1.insert(num[j]);
                for(int k = j + 1; k<size; k++){
                    if(num[i] + num[j] + num[k] > 0 ) {
                        break;
                    }
                    if(tag2.find(num[k]) != tag2.end()){
                        continue;
                    }
                    tag2.insert(num[k]);
                    if(num[i] + num[j] + num[k] == 0 ) {
                        vset.push_back(num[i]);
                        vset.push_back(num[j]);
                        vset.push_back(num[k]);
                        ret.push_back(vset);
                        vset.clear();
                    }
                }
                tag2.clear();
            }
            tag1.clear();
        }
        return ret;
    }
};


