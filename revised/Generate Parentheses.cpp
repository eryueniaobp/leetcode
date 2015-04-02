/**
 * DFS 
 */
public class Solution {
      List<String> ret = new ArrayList<String>();
    public void dfs( int l ,int r , String str){
        if(l == 0 && r == 0) {
            ret.add(str) ;
            return ;
        }
        if(l>0) {
            dfs(l-1,r,str+'(');
        }
        if(r>l){
            dfs(l, r-1,str+')');
        }

    }
    public List<String> generateParenthesis(int n) {
        int l = n , r = n ;
        dfs(l ,r ,"");
        return ret;
    }
}
// Java Iterative Solution Perfect! 
public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String>  ret  = new ArrayList<String>() ;
        int left = n , right = n ;
        Stack<Character> stack = new Stack();
        while( true ) {
            while(left > 0 ){
                stack.push('(') ;
                left -- ;
            }
            if(right > left) {
                stack.push(')') ;
                right -- ;
            }

            if(left == 0 && right == 0 ) {
                String a = "" ;
                Iterator<Character> iter= stack.iterator();
                while(iter.hasNext()) {
                    a += iter.next();
                }
                ret.add(a) ;

                // pop out until  '(' and right >left ! 
                stack.pop() ;
                right++ ;
                while(!stack.isEmpty()){
                    char pc = stack.pop();
                    if(pc == '(' )   left++;
                    else  {
                        right++ ;
                    }

                    if(pc == '(' && right > left ) {
                        stack.push(')')  ;
                        right -- ;
                        break;
                    }
                }
                if(stack.isEmpty()) break;  // get all !

            }
        }
        return ret;
    }
}
