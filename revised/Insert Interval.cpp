/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 * Prerequisite: intervals is sorted, 
 * Time:  O(n)
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.size() == 0 ) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int size = intervals.size() ; 
        for(int i = 0 ; i < intervals.size() ; i++){
            if(newInterval.start < intervals[i].start){
                intervals.insert(intervals.begin() + i ,newInterval);
                break;
            }
        }
        if( size == intervals.size()) {
            intervals.push_back(newInterval);
        }
        int i = 0 , j = 0 ;
        vector<Interval> ret;
        size = intervals.size() ; 
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


