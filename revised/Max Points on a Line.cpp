/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 * O(n * ( n+ nlogn +n))
 */

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) {
            return 0 ; 
        }
        int max = 0; 
        int size = points.size() ; 
        vector<float> angles; 
        for(int i = 0 ; i< size;  i ++ ) {
            angles.clear();  
            int repeated = 0 ; 
            for(int j = 0; j< size ; j++){ // 这里用 j = i +1 为什么不对呢？？ 
                if(i == j ) continue; 
                int diffx = (points[j].x - points[i].x) ; 
                int diffy = (points[j].y - points[i].y ) ; 
                if(diffx == 0 && diffy == 0) {
                    repeated ++ ; 
                }else{
                    if(diffx == 0) {
                        angles.push_back(INT_MAX) ; 
                    }else{
                         angles.push_back(diffy/(float)diffx) ; 
                    }
                }
            }
            sort(angles.begin(),angles.end(), less<float>()); 
            int cur = repeated  ; 
            float pre = INT_MIN; 
            for(int k = 0 ; k < angles.size();k++){
                if(k == 0 )  cur ++ ; 
                else{
                    if(abs(angles[k] - pre) < 0.000001)  cur ++ ; 
                    else {
                        max = cur > max ? cur:max ;
                        cur = 1; 
                    }
                }
                pre = angles[k] ; 
            }
            if(cur > max )  max = cur; 
            //max += repeated;
            
        }
        return max +1 ; 
    }
};

