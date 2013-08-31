class Solution {
public:
    struct Node {
        vector<string> parent;
        int layer;
    };
    
    void buildResult( vector<vector<string>> &result, list<string> &r, string start, string end, unordered_map<string, Node> &checkmap)
    {
        r.push_front(end);
        if(end==start) {
            vector<string> oneresult(r.begin(), r.end());
            result.push_back(oneresult);
        } else {
            for(const string &s:checkmap[end].parent) {
                buildResult(result, r, start, s, checkmap);
            }
        }

        r.pop_front();
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, Node> checkmap;
        list<string> layer;
        checkmap[start].layer = 1;
        checkmap[start].parent.push_back(start);
        layer.push_back(start);

        vector<vector<string>> result;

        bool hasfind = false;
        string layerend = start;
        string last;
        while(!layer.empty())
        {
            string s = layer.front();
            layer.pop_front();
            int currentlayer = checkmap[s].layer;
            int L = s.size();
            for(int i = 0; i< L; i++)
            {
                string temp = s;
                for(int j = 0; j < 26; j++)
                {
                    temp[i] = j+'a';
                    if(temp==end) {
                        checkmap[temp].parent.push_back(s);
                        checkmap[temp].layer = checkmap[s].layer+1;

                        hasfind = true;
                    } else if(dict.count(temp)&&s!=temp) {
                        if(checkmap.count(temp)==0){
                            checkmap[temp].parent.push_back(s);
                            checkmap[temp].layer = checkmap[s].layer+1;
                            layer.push_back(temp);
                            last = temp;
                        } else if(checkmap[s].layer<checkmap[temp].layer) {
                            checkmap[temp].parent.push_back(s);   
                        }
                    }

                }
            }   // end for 

            if(s == layerend) 
            {
                layerend = last;
                if(hasfind) {
                    list<string> r;
                    buildResult(result, r, start, end, checkmap);
                    break;
                }
            }
            
        }   // end while 

        return result;
    }
};

