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
/** java **/
public class Solution {
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    public List<String> anagrams(String[] strs) {
        List<Item> items= new ArrayList<Item>() ; 
        for(String str:strs) {
            items.add(new Item(str)) ; 
        }
        Collections.sort(items,new Comparator<Item>() {
            public int compare(Item a , Item b) {
                return a.sorted.compareTo(b.sorted) ; 
            }    
        }); 
        List<String> ret = new ArrayList<String>() ; 
        Item prev = null ;
        boolean first = true; 
        for(Item item:items) {
            if(item.sortedEquals(prev)) {
                if( first) { 
                    ret.add(prev.raw) ; 
                    first= false ;
                }
                ret.add(item.raw) ; 
            }else{
                first = true ; 
                prev = item ;
            }
        }
        return ret; 
        
    }
    public static class Item {
        String raw ; 
        String sorted ; 
        public Item(String str){
            this.raw = str  ; 
            char []arr = str.toCharArray() ; 
            Arrays.sort(arr) ; 
            sorted = new String(arr) ; 
        }
        public boolean sortedEquals(Item e) {
            return sorted.equals(e==null?null:e.sorted) ; 
        }
    }
}
/** python **/
class Solution:
    # @param strs: A list of strings
    # @return: A list of strings
    def anagrams(self, strs):
        # write your code here
        a = [ (sorted(i),i) for i in strs ]
        a = sorted(a , key=lambda x: x[0] ) 
        
        pre = None 
        ret = [] 
        k =  1 
        for item in a:
            if pre == None:
                pre = item
                continue
            if item[0] == pre[0]:
                if k == 1 : 
                    ret.append(pre[1]) 
                    k = 0
                ret.append(item[1])
            else:
                k = 1 
            pre = item 
                
        return ret
                

