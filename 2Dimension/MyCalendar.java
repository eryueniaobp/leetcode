class MyCalendar {
    TreeMap<Integer,Integer> cal = new TreeMap<>();
    public MyCalendar() {

    }

    public boolean book(int start, int end) {
        Map.Entry<Integer,Integer> floor = cal.floorEntry(start) ;

        Map.Entry<Integer,Integer> ceil = cal.ceilingEntry(start);
        
        if(floor == null && ceil == null ){
            cal.put(start,end) ; 
            return true ;
        }
        if(floor == null ){
            if(end <= ceil.getKey()){
                return true; 
            }
            return false;
        }
        if(ceil == null){
            return start >= floor.getValue(); 
        }
        
        return start >= floor.getValue() && end <= ceil.getKey(); 



    }
}
