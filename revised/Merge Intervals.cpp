/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 * O(nLogn) + O(n) 
 */
bool cmp(const Interval & a,const Interval & b){
    return a.start < b.start ;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(),intervals.end(),cmp);     
        int i = 0 , j = 0 ;
        vector<Interval> ret;
        int size = intervals.size() ; 
        while( i < size){
            j = i ; 
            int max = intervals[j].end;
            while(j+1<size && intervals[j+1].start <= max ){
                if(max < intervals[j+1].end){
                    max = intervals[j+1].end;
                }
                j++ ; 
            }
            
            ret.push_back(Interval(intervals[i].start,max)); 
            i = j +1;
        }
        return ret;
    }
};


