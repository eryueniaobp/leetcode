/**
 * O(n) , n为罗马字符串的长度
 */
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 } ; 
        string roman[] = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" 
        };
        int size = sizeof(values)/sizeof(int) ; 
        string ret ; 
        for(int i =  0 ;i < size ; i ++ ) {
            while(num >= values[i] ) {
                num -= values[i];
                ret.append(roman[i]);
            }
        }
        return ret;
    }
};


