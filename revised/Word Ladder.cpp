/**
 * BFS复杂度较高 
 */
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<string> set;
        list<string> slist; 
        slist.push_back(start);
        set.insert(start);
        int distance = 1; 
        int count = 1 ; 
        while(count > 0 ) {
            while(count-- > 0 ) {
                string cur = slist.front() ; slist.pop_front();
                for(int i = 0 ; i< cur.size() ; i++){
                    string tmp = cur;
                    for(int j =  0 ;j < 26 ; j ++ ){
                        tmp[i] = j + 'a' ; 
                        if(tmp == end ) {
                            return distance  + 1; 
                        }
                        if(dict.count(tmp) > 0 && set.count(tmp) == 0 ){
                            set.insert(tmp);
                            slist.push_back(tmp);
                        }
                    }
                }
            }
            distance++ ;
            count = slist.size() ;
        }
        return 0;
    }
};

