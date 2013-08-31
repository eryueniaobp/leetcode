public class Solution {
    public int ladderLength(String start, String end, HashSet dict) {
        Set<String> set=new HashSet<String>();
        Queue<String> queue=new LinkedList<String>();
        queue.offer(start);
        int distance=1;
        int count=1;
        set.add(start);
        
        while(count>0){
            while(count>0){
                char[] curr=queue.poll().toCharArray();
                for(int i=0; i<curr.length;i++){
                    char tmp=curr[i];
                    for(char c='a';c<='z';c++){
                        if(c==tmp) continue;
                        curr[i]=c;
                        String str=new String(curr);
                        if(str.equals(end)) return distance+1;
                        if(dict.contains(str) && !set.contains(str)){
                            queue.offer(str);
                            set.add(str);
                        }
                    }
                    curr[i]=tmp;
                }
                count--;
            }
            distance++;
            count=queue.size();
        }
        return 0;
    }
}

