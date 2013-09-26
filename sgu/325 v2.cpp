//这个代码容易理解，但是sgu上无法通过
//易懂的思路: 
/**
 * http://tieba.baidu.com/p/1876429105  DreamerIndeed 写的逆序对  
 * mississippi  
 *  
 * i[1,10]  -> [0 , 10 ] 
 * s[2,6]   -> [1, 9 ] 
 * s[3,5]   -> [2, 7 ] 
 * i[4,7]   -> [3 , 6 ] 
 * p[8,9]   -> [ 4, 5 ] 
 * m[11(假设的),0]   -> [5,5]  xx 奇数字符特殊处理 即可 
 * 那么 最终 各字符对应的位置是： 
 *  m i s s i s s i p p i  
 *  5,0,1,2,3,8,9,7,4,6,10  -> posArr
 *  每一个逆序对，对应一次相邻位置的交换 
 *  求出 posArr中的逆序对即可 (利用归并算法 nlogn求出逆序对)
*/
#include <iostream>
using namespace std;
int main()
{
    int N;     // 字符串长度
    //cin >> N;
    char s[8001] = {0};  // 保证可存下结尾的'/0'
    cin >> s;
    N = strlen(s) ; 
    //cout<<N<<endl;
    // 判断是否可变为回文串
    int b[26] = {0};   // 记录'a'~'z'出现的次数
    for (int i = 0; i < N; i++)
        b[s[i] - 'a']++;  // 相应字母出现次数加一
    int odd = 0;    // 有多少个字母出现奇数次
    char charodd = '/0';  // 出现奇数次的字母
    for (int i = 0; i < 26; i++)
        if (b[i] % 2 == 1)  // b[i]是奇数
        {
            odd++;
            charodd = i + 'a'; // 记录该字母
        }
    //cout<<odd<<endl;
    if (odd > (N&1))
        cout << -1 << endl; // 输出
    else
    {
        int change = 0;     // 交换次数
        for (int i = 0; i < N/2; i++) // 依次考虑左侧的字母
        {
            if (s[i] == charodd)  // 是charodd，转而考虑右侧字母
            {
                int j = 0;
                for (j = i; j <= N-i-1; j++) // 从左侧该位置开始，找相同字母
                    if (s[j] == s[N-i-1])  // 找到
                        break;
                change += j - i;    // 需要j-i次移动可到左侧位置
                for (int k = j; k > i; k--)  // 实现字母的移动
                    s[k] = s[k-1];
                s[i] = s[N-i-1]; 
            }
            else  // 考虑左侧字母
            {
                int j = 0;
                for (j = N-i-1; j >= i; j--) // 从右侧对称位置开始，找相同字母
                    if (s[j] == s[i])   // 找到
                        break;
                change += N-i-1 - j;   // 需要N-i-j-j次移动可到右侧位置
                for (int k = j; k < N-i-1; k++) // 实现字母的移动
                    s[k] = s[k+1];
                s[N-i-1] = s[i];
            }
        }
        cout << change << endl;     // 输出
    }
    //system("pause");
    return 0;
}

