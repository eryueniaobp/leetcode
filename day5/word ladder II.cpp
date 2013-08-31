/**
 * pass small test cases
 * */
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<string> ldeq;
        deque<string> tmp;
        vector<vector<string> > ans;
        vector<vector<string> > path; 
       /* for(int i = 0 ; i<10000 ; i++ ) {
                path.push_back(vector<string>());
        }*/
         
        set<string> pset;
        
        unordered_set<string> all ;
        if(start.compare(end ) == 0  ) {
            return ans;
        }
        ldeq.push_back(start);
        all.insert(start);
        vector<string > node ;
        map< string,vector<string> > cache ; 
        node.push_back(start);
        path.push_back(node);
        bool flag = false;
        bool final = false;
        int level = 0 ; 
        while(!ldeq.empty()){
            int dn = 0 ; 
            cache.clear();
            //cout<<"level = " << level++ <<" size = " << ldeq.size()<<endl;
            while(!ldeq.empty()){
                //if(!path.empty()) path.pop_back();
                if(dn > 0 ) {
                    //pset.erase(path[path.size()-1]);
                    //path.pop_back();
                    
                }
               
                string a = ldeq.front();ldeq.pop_front();
                if(cache.find(a) != cache.end()){
                    vector<string> ns = cache.get(a);
                    path[dn].push_back(ns[0]);
                    for(int i = 1 ; i<ns.size() ; i++){
                        vector<string> a(path[dn].begin(),path[dn].end()-1);
                        a.push_back(ns[i]);
                        path.push_back(a);
                    }
                    dn++;
                    continue;
                }
                
               // path[dn].push_back(a); //pset.insert(a);
                flag = false;
                // dn++ ; 
               //cout<<"current string = " << a<< " path sizes="<< path.size()<<endl;
                int count = 0 ; 
                for(int i = 0 ;i<a.size() && !flag ; i++ ) {
                    for( char j = 'a' ; j<= 'z' ; j++ ) {
                        if(j == a[i] ) continue;
                        string b = a.substr(0,i) + j + a.substr(i+1,a.size()-i-1);
                      //  if(j == 'g' ) cout<<"   " << b<<endl;
                        if(b.compare(end) != 0 ){
                            if(dict.find(b) != dict.end() && pset.find(b) ==pset.end()
                               /*&& find(tmp.begin(),tmp.end(),b) == tmp.end()*/ && all.find(b) == all.end()) {
                              //cout<<b<<endl;
                            //  cout<<b<<" ";
                               //tmp.insert(b);
                               //    cache[a].push_back(b);
                               tmp.push_back(b);
                               if(count++ == 0 ) {
                                  path[dn].push_back(b);
                               }else{
                                  vector<string> a (path[dn].begin(),path[dn].end()-1);
                                  a.push_back(b);
                                  path.push_back(a);
                                  //cout<<"   add one path -> " ; 
                                  /*for(int v = 0 ; v<a.size();v++){
                                          cout<<a[v]<<" ";
                                  }
                                  cout<<endl;*/
                               }
                              // path.push_back(path[dn]                            
                               //all.insert(b);
                               
                            }
                        }else{
                            //cout<<"+++++++++ find one " ;
                            //cache[a].push_back(b);
                            vector<string> node; 
                            if(count++ == 0 ){
                                node.assign(path[dn].begin(),path[dn].end());
                                node.push_back(b);
                            }else{
                                node.assign(path[dn].begin(),path[dn].end()-1);
                                node.push_back(b);
                            }
                            //path[dn].push_back(b);
                            ans.push_back(node);
                          //  for(int n = 0 ; n<node.size(); n++ ) cout<< node[n]<<' ';
                           // cout<<" ---- ans size = " << ans.size()<<endl;
                           // path[dn].pop_back();
                            
                            flag = true;

                            final = true;
                            break;
                        }
                    }//for
                }
                if(count == 0 ) {
                   //删掉无用边
                   path.erase(path.begin()+dn);
                   dn -- ; 
                }
                dn++;
               
            }// inner while
            if( final){
                break;
            }
            ldeq.clear(); 
            //cout<<tmp.size()<<endl;
          //  system("pause");
            ldeq.assign(tmp.begin(),tmp.end());
            all.insert(tmp.begin(),tmp.end());
            tmp.clear();
        }
        return ans;
    }
};

