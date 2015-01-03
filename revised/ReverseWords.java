public class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
    public void reverse(char [] a,int start ,int end ) {
        int i = start , j =end; 
        while( i < j) {
            char t = a[i];
            a[i] = a[j];
            a[j] = t ; 
            i++ ; j -- ; 
        }

    }
    public void fill(StringBuilder sb , char []a,int start,int end){
        while(end >= start) {
            sb.append(a[end]) ; 
            end -- ; 
        }
        
    }
    public String reverseWords(String s) {
        if(s == null ||s.length() == 0 ) return "" ; 
        int i =  0   , j = s.length() - 1;
        while(i< s.length() && s.charAt(i) ==' ') i ++ ;
        while(j >= 0 && s.charAt(j) ==' ') j -- ;
        if(j< i) {
            return "";
        }
        char []a = new char[j-i+1] ; 
        s.getChars(i,j+1,a,0) ;
        reverse(a ,0 , a.length-1) ; 
        StringBuilder sb = new StringBuilder() ; 
        i = 0  ;
        j = 0 ; 
        while(true) {
            while(j<a.length && a[j] != ' ') {
                j++ ; 
            }
            fill(sb, a, i, j - 1) ;
            if(j == a.length ) {
                break; 
            }
            sb.append(' ') ; 
            while( j <a.length && a[j] == ' ') j++ ; 
            i = j  ;
        }
        return sb.toString();
    }
}


