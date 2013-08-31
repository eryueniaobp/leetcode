public class Solution {
    public boolean isPalindrome(String s) {
        if(s == null || s.length() == 0) return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!isAlphanumeric(s.charAt(i))) {
                i++;
            } else if (!isAlphanumeric(s.charAt(j))) {
                j--;
            } else if (Character.toLowerCase(s.charAt(i)) == Character.toLowerCase(s.charAt(j))) {
                i++;
                j--;
           } else {
                return false;
           }
        }
        return true;
    }
    
	public boolean isAlphanumeric(char ch) {
		if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z') return true;
		return false;	
	}
}

