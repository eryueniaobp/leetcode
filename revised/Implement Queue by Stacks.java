// http://lintcode.com/zh-cn/problem/implement-queue-by-stacks/ 
/**
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.
*/
public class Solution {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Solution() {
       // do initialization if necessary
       stack1 = new Stack<Integer>() ;
       stack2 = new Stack<Integer>() ; 
    }
    
    public void push(int element) {
        stack1.push(element) ; 
    }

    public int pop() {
        if(stack2.isEmpty()) {
            while(!stack1.isEmpty()) {
                stack2.push(stack1.pop()) ;
            }
        }
        return stack2.pop() ; 
    }

    public int top() {
        if(stack2.isEmpty()) {
            while(!stack1.isEmpty()) {
                stack2.push(stack1.pop()) ;
            }
        }
        return stack2.peek() ; 
    }
}

