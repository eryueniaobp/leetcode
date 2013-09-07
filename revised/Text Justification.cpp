/**
 * 贪心算法   O(n) 
 */
class Solution {
private:
    string handle_normal(vector<string> &word, int L, int wordL) {
        string answer;
        if (word.size() == 1) {
        	answer += word[0];
    		for (int i = 0; i < L - wordL; i++) {
    			answer += " ";
    		}
    		return answer;
    	}
        int d = (L - wordL) / (word.size() - 1);
        int r = (L - wordL) % (word.size() - 1);
        answer = word[0];
        for (int i = 1; i < word.size(); i++) {
            for (int j = 0; j < d; j++) {
                answer += " ";
            }
            if (r > 0) {
                answer += " ";
                r--;
            }
            answer += word[i];
        }
        return answer;
    }
    
    string handle_end(vector<string> &word, int L, int count) {
        string answer;
        answer = word[0];
        for (int i = 1; i < word.size(); i++) {
            answer += " " + word[i];
        }
        for (int i = 0; i < L - count; i++) {
            answer += " ";
        }
        return answer;
    }
    
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        vector<string> selWord;
        int count = -1, wordL = 0;
        for (int i = 0 ; i < words.size() ; i++){
            if (count + words[i].size() + 1 > L) {
                ans.push_back(handle_normal(selWord, L, wordL));
                selWord.clear();
                count = -1;
                wordL = 0;
            }
            count += 1 + words[i].size();
            wordL += words[i].size();
            selWord.push_back(words[i]);
        }
        ans.push_back(handle_end(selWord, L, count));
        return ans;
    }
};

