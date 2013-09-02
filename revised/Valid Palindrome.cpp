/**
 * O(n) 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0 ) return true ; 
        int i = 0 ; 
        int j = s.size() -1 ;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
            } else if (!isAlphanumeric(s[j])) {
                j--;
            } else if (tolower(s[i])  == tolower( s[j] ) ) {
                i++;
                j--;
           } else {
                return false;
           }
        }
        return true;
    }
   	bool isAlphanumeric(char ch) {
		if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z') return true;
		return false;	
	}
};

