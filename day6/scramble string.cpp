class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValid(0,s1.size()-1,0,s2.size()-1,s1,s2);
    }
    bool isValid(int l1,int r1,int l2,int r2,string &s1,string &s2)
    {
        if(r1 - l1 != r2 - l2)
            return false;
        int key = 1;
        int mark1[26];
        int mark2[26];
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        for(int i = 0; i <= r1 - l1;i++)
        {
            mark1[s1[l1 + i] - 'a']++;
            mark2[s2[l2 + i] - 'a']++;
            if(s1[l1 + i] != s2[l2 + i])
                key = 0;
        }
        if(key == 1)
            return true;
        if(l1 == r1)
            return false;
        for(int i = 0;i < 26;i++)
        {
            if(mark1[i] != mark2[i])
                return false;
        }
        for(int i = 0; i <= r1 - l1 -1;i++)
        {
            bool tag1,tag2; 
            tag1 = isValid(l1,l1 + i,r2 - i,r2,s1,s2);
            tag2 = isValid(l1+i+1,r1,l2,r2-i-1,s1,s2);
            if(tag1 && tag2)
                return true;
            tag1 = isValid(l1,l1 + i,l2,l2 + i,s1,s2);
            tag2 = isValid(l1+i+1,r1,l2+i+1,r2,s1,s2);
            if(tag1 && tag2)
                return true;            
        }
        return false;
    }
};

