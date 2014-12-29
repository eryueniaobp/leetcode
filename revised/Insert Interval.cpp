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
 * 直接merge就可以 ..比上面的方法更加直接。。如果不需要排序的话，那么返回的vector也不需要排序.
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
        vector<Interval> ret; 
        int size = intervals.size() ; 
        int i = 0 ; 
     
        for (  i = 0 ; i < intervals.size() ; i++){
            if(intervals[i].start > newInterval.end || intervals[i].end < newInterval.start)  {
                ret.push_back(intervals[i]) ; 
            }else{
                newInterval.start = min ( newInterval.start , intervals[i].start) ; 
                newInterval.end = max ( newInterval.end, intervals[i].end) ; 
            }
        }
        
        for( i = 0 ; i < ret.size() ; i ++  ) {
            if(ret[i].start < newInterval.start)  continue; 
            ret.insert(ret.begin() + i  ,newInterval) ; 
            break; 
        }
        if(ret.size() == i ) {
            ret.push_back(newInterval) ; 
            return ret; 
        }
        return ret;
    }
};


// 
/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */

class Solution {
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: A new interval.
     * @return: A new sorted interval list.
     */
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> result = new ArrayList<Interval>();
        if(intervals == null || intervals.size() == 0 ) {
            result.add(newInterval) ; 
            return result ; 
        }
        // write your code here
        int size = intervals.size() ; 
        
        int start = newInterval.start , end = newInterval.end ; 
        for(int i = 0 ; i<size ; i++ ){
            Interval val = intervals.get(i) ; 
            if(start == -1 ) {
                result.add(val) ; 
                continue;  
            }
            if(val.end < start ) {
                result.add(val) ; 
            }else if ( val.start > end) {
                result.add(new Interval(start,end) ) ; 
                result.add(val) ;  
                start = end = - 1; 
            }else {
                // intersect .. 
                start = start < val.start? start:val.start ; 
                end = end > val.end? end : val.end ; 
                
            }
        }
        
        if(start != -1 ) {
            result.add(new Interval(start,end)) ; 
        }
        return result ; 
    }
}

