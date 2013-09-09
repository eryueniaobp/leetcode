class Solution {
public:
    string next(const string & cas) { 
        string ret; 
        char cur_str=cas.at(0); 
        int num=0; 
        for (int i=0;i<cas.length();i++)  { 
            if (cur_str==cas.at(i)) { 
                num++; 
            } else{ 
                stringstream ss; 
                ss<<num<<cur_str; 
                ret+=ss.str(); 
                cur_str=cas.at(i); 
                num=1; 
            } 
        } 
        if (num > 0)     {       
            stringstream ss;                    
            ss << num << cur_str;                 
            ret += ss.str();       
        } 
        return ret; 
    } 
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1)     return "";  
        string s="1"; 
        for (int i=1;i<n;i++){ 
            s=next(s); 
        } 
        return s; 
    }
};



