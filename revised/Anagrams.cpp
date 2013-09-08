/**
 * 假设 strs[i]的平均长度为 k  i<n
 * 那么总的时间复杂度主要是排序 
 * O(n klogk) 
 * 利用桶排序，可以到O(nk)
 */
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) return res;
        unordered_map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

