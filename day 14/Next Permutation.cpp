class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }
        if (i < 0) {
            reverse(num.begin(), num.end() - 1);
        }
        else {
            int j = i + 2;
            while (j < num.size() && num[j] > num[i]) {
                j++;
            }
            j--;
            
            num[i] ^= num[j];
            num[j] ^= num[i];
            num[i] ^= num[j];
            
            reverse(num.begin() + i + 1, num.end() - 1);
        }
    }

private:
    void reverse(vector<int>::iterator i1, vector<int>::iterator i2) {
        while (i1 < i2) {
            *i1 ^= *i2;
            *i2 ^= *i1;
            *i1 ^= *i2;
            
            i1++;
            i2--;
        }
    }
};

