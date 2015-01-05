import  java.util.* ;
/**
 * below the problem ,it 's a graph model .  you can touch a word from different parent words .
 * we use queue to make bfs . and we use Item#layer to guarantee the shortest path .
 */
public class Solution {
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return a list of lists of string
     */
    Set<String> visited = null;
    // critical map
    Map<String,Item> w2ps  = null;
    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
        // write your code here  
        List<List<String>> ret = new ArrayList<List<String>>() ;
        visited = new HashSet<String>() ;

        Queue<Item> q = new LinkedList<Item>() ;
        int cnt = 1  , ncnt = 0 ;

        w2ps = new HashMap<String,Item>() ;
        w2ps.put(start ,new Item(start).addParent(null)) ;
        q.offer(w2ps.get(start)) ;

        while(cnt > 0 ){
            cnt -- ;
            Item item = q.poll()  ;

            visited.add(item.word) ;

            if(item.word.equals(end)) {
                dfs(item) ;
                break ;
            }
            List<String> neighbors = getNeighbors(item.word, dict) ;
            ncnt += addNeighborsToQueue(item, neighbors ,q) ; // parent ,neighbors ,queue
            if(cnt == 0 ) {
                cnt = ncnt ;
                ncnt = 0 ;
            }
        }
        return this.paths ;
    }
    public int addNeighborsToQueue(Item parent,List<String> neighbors ,Queue<Item> q) {
        int cnt = 0 ;
        for(String nb : neighbors){
            if(w2ps.containsKey(nb)) {
                Item item = w2ps.get(nb) ;
                item.addParent(parent) ;
                // q.offer(item) ;     
            }else{
                Item item = new Item(nb).addParent(parent) ;
                q.offer(item) ;
                w2ps.put(nb,item) ;
                cnt++ ;
                //System.out.printf(" [ %s , %s ] \n" , parent.word ,item.word );
            }
        }
        // System.out.println("=======");
        return cnt ;
    }
    public List<String> getNeighbors(String word,Set<String> dict){
        List<String> ret = new ArrayList<String>();
        char []charr = word.toCharArray();

        for(int i = 0 ; i< charr.length ; i++){
            char t = charr[i] ;
            for(int j = 0 ;j<26 ; j++){
                char c = (char)('a' + j)  ;
                if( c == charr[i] ) continue ;
                charr[i] = c ;
                String neighbor = new String(charr) ;
                if(dict.contains(neighbor) && !visited.contains(neighbor)) {
                    ret.add(neighbor);
                }
            }
            charr[i] =t ;
        }
        return ret;
    }
    public void reverse(List<String> path) {
        int i = 0 , j = path.size() -1 ;
        while(i < j) {
            Collections.swap(path, i , j );
            i++ ; j -- ;
        }
    }
    List<List<String>> paths = new ArrayList<List<String>>() ;
    List<String> path = new ArrayList<String>() ;
    public void dfs(Item cur) {
        path.add(cur.word) ;
        if(cur.parents == null ) {
            List<String> np = new ArrayList<String>(); np.addAll(path) ;
            reverse(np) ;
            paths.add(np) ;
            path.remove(path.size()-1) ;
            return;
        }
        for(Item item : cur.parents ) {
            dfs(item) ;
        }
        path.remove(path.size()-1);
    }

    public static void main(String []args){
        Solution sol = new Solution();
        Set<String> dict = new HashSet<String>();

//        String start = "hot";
//        String end = "dog" ;
//        dict.addAll(Arrays.asList("hot","cog","dog","tot","hog","hop","pot","dot")) ;
//
        String start = "a" ,end = "c" ;
        dict.addAll(Arrays.asList("a","b","c")) ;

        List<List<String>> ladders = sol.findLadders(start,end,dict) ;
        for(List<String> lad :ladders) {
            for(String s : lad) {
                System.out.printf("%s\t" , s );
            }
            System.out.println();
        }
    }
    public static class Item {
        String word;
        List<Item> parents ;
        int pos = 0 ;
        int layer ;
        public Item(String word){
            this.word= word ;
            this.parents = null ;
            layer = Integer.MAX_VALUE ;
        }
        // It's critical to keep the right layer . So we can get the shortest path
        public Item addParent(Item parent){
            if(parent == null) {
                this.layer = 0 ;
                return this ;
            }
            if(this.layer <= parent.layer ) {
                return this ;
            }
            this.layer = parent.layer + 1 ;
            if(parents == null) {
                parents = new ArrayList<Item>() ;
            }
            parents.add(parent) ;
            return this;
        }
    }
}

