class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s = "1";
        for(int i = 2; i <= n; i++)
        {
            string nextS;
            char key = '-';
            int j = 0;
            int count = 0;
            while(j < s.size())
            {
                if (key == s[j])
                    count++;
                else
                {
                    if (key != '-')
                    {
                        nextS = nextS + (char)(count + '0');
                        nextS = nextS + key;
                    }
                    
                    key = s[j];
                    count = 1;                    
                }
                
                j++;
            }
            nextS = nextS + (char)(count + '0');
            nextS = nextS + key;
            
            s = nextS;
        }
        
        return s;
    }
};

