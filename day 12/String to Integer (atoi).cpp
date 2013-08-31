class Solution {
    public:
        int atoi(const char *str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            // 13141423
            bool negative = false;

            while(*str == ' ') ++str;
            if(*str == '-') {
                negative = true;
                ++str;
            }
            if(*str == '+') ++str;

            long long res = 0;
            while(*str!='\0'){
                if( *str>='0' && *str<='9') {
                    res = res*10 + *str - '0';
                } else {
                    break;
                }
                ++str;
            }
            res = negative ? -res : res;

            if(res>INT_MAX) return INT_MAX;
            else if(res<INT_MIN) return INT_MIN;
            else return res;
        }
};

