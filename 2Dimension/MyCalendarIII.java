package twoDimension;

import java.util.TreeMap;

/**
 * 扫描线方法!  使用类似 会议室的方法 不太能做了 
 */
class MyCalendarIII {

    private TreeMap<Integer, Integer> calendar;

    public MyCalendarIII() {
        calendar = new TreeMap<>();
    }

    public int book(int start, int end) {

        // 添加至日程中
        calendar.put(start, calendar.getOrDefault(start, 0) + 1);
        calendar.put(end, calendar.getOrDefault(end, 0) - 1);

        // 记录最大活跃的日程数
        int max = 0;
        // 记录活跃的日程数
        int active = 0;

        for (Integer d : calendar.values()) {
            // 以时间线统计日程
            active += d;

            // 找到活跃事件数量最多的时刻，记录下来。
            if (active > max) {
                max = active;
            }
        }

        System.out.println(calendar);
        return max;
    }

    public static void main(String[] args) {
        MyCalendarIII cal = new MyCalendarIII();
        cal.book(10, 12);
        int k = cal.book(11, 13);

        System.out.println(k);




    }

}
