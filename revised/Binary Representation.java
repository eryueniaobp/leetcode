/**
Given a (decimal - e g  3.72) number that is passed in as a string,return the binary representation that is passed in as a string.If the number can not be represented accurately in binary, print “ERROR” 
*/
public class Solution {
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    public String binaryRepresentation(String n) {

        int pos = n.indexOf('.') ;

        String ins = n.substring(0,pos==-1?n.length():pos)  ;
        int num = Integer.parseInt(ins);
        StringBuilder sb = new StringBuilder();
        if(num == 0 ) sb.append(0) ;
        while(num > 0 ) {
            if( (num&01) == 1 ) {
                sb.append(1) ;
            }else{
                sb.append(0) ;
            }
            num = num >> 1 ;
        }
        sb.reverse() ;
        if(pos == -1 ) return sb.toString() ;
       
        double dn = Double.parseDouble(n.substring(pos)) ;
        if(dn>0)  sb.append('.') ; 
        int cnt = 0  ;
        while(dn > 0 ) {
            if( 2*dn >=1 ) {
                sb.append(1) ;
                dn = 2*dn - 1 ;
            }else{
                sb.append(0) ;
                dn = 2*dn ;
            }
            if(cnt++ > 32 ) { // tricy..not perfect
                sb = new StringBuilder("ERROR") ;
                break ; 
            }

        }
        return sb.toString() ;


    }
    public static void main(String []args){
        Solution sol = new Solution();
        System.out.println(sol.binaryRepresentation("4.5") ) ;
    }

}

