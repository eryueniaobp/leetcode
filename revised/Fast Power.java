// http://lintcode.com/zh-cn/problem/fast-power/ 
// 取模运算的 乘法规则
class Solution {
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    public int fastPower(int a, int b, int n) {
        if (n==0) return 1%b;

        int res = fastPowerRecur(a,b,n);
        return res;
    }

    public int fastPowerRecur(int a, int b, int n){
        if (n==1)
            return a%b;
    
        long temp = fastPowerRecur(a,b,n/2);
        temp = temp*temp%b;
        int res = (n%2==0) ? (int) temp: (int)(temp*a%b);
        return res;
    }
};
