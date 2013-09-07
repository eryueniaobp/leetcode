class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string rret;
        int k = 0 ;
        if(a.size() < b.size()){
            swap(a,b);
        }
        int i = b.size() -1 ; 
        int j = a.size() -1 ;
        while(i>=0){
            int ca = a[j--] - '0';
            int cb = b[i--] - '0';
            int sum = ca+cb + k;
            if(sum < 2 ){
                rret.push_back(sum+'0'); 
                k = 0 ;
            }else{
                rret.push_back(sum-2+'0');
                k = 1;
            }
        }
        while(j >= 0 ){
            int sum = a[j--] -'0'  + k ;
            if(sum <2){
                rret.push_back(sum+'0');
                k = 0 ;
            }else{
                rret.push_back('0');
                k = 1;
            }
        }
        if(k ==1 ){
    		rret.push_back('1');
		}
        for(int i = 0  ; i < rret.size()/2 ;i++){
            //ret.push_back(rret[i]);
            swap(rret[i],rret[rret.size() -1 -i]);
        }
        return rret;
    }
};

