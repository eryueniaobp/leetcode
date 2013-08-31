class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char> rret;
        int k = 0 ;
        if(a.size() < b.size()){
            swap(a,b);
        }
        std::string::reverse_iterator rit=a.rbegin(),bit ;
        for( bit = b.rbegin();bit!=b.rend(); ++bit,++rit){
            int ca = *rit - '0';
            int cb = *bit - '0';
            int sum = ca+cb + k;
            if(sum < 2 ){
                rret.push_back(sum+'0'); 
                k = 0 ;
            }else{
                rret.push_back(sum-2+'0');
                k = 1;
            }
        }
        while(rit != a.rend()){
            int sum = *rit -'0'  + k ;
            if(sum <2){
                rret.push_back(sum+'0');
                k = 0 ;
            }else{
                rret.push_back('0');
                k = 1;
            }
            ++rit;
        }
        if(k ==1 ){
    		rret.push_back('1');
		}
        string ret ; 
        for(int i =rret.size() - 1 ; i>=0 ;i--){
            ret.push_back(rret[i]);
        }
        return ret;
    }
};

