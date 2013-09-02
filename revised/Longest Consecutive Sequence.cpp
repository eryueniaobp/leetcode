/**
 * O(n) 复杂度 
 * 借用 hash ,来查找连续的数是否存在，并即时消除连续的数字 
 */
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> map;
        int n = num.size();
        for(int i = 0;i < n; ++i){
            map.insert(num[i]);
        }
        int max = 1;
        for(int i = 0; i< n; ++i){
            if(map.find(num[i]) != map.end()){
                int temp = 1;
                int cur = num[i];
                map.erase(cur);
                temp += getCount(map, cur + 1, true);
                temp += getCount(map, cur - 1, false);
                max = temp > max ? temp : max;
            }
        }
        return max;
    }
    int getCount(unordered_set<int> &map, int cur, bool asc){
        int count = 0;
        while(map.find(cur) != map.end()){
            map.erase(cur);
            count ++;
            if(asc)
                cur++;
            else
                cur--;
        }
        return count;
    }
};

