import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public static List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> result = new ArrayList<>();
        List<Interval> timeLine = new ArrayList<>();
        schedule.forEach(e -> timeLine.addAll(e));
        Collections.sort(timeLine, (a, b) -> a.start - b.start);
        Interval temp = timeLine.get(0);
        for (Interval each : timeLine) {
            if (temp.end < each.start) {
                result.add(new Interval(temp.end, each.start));
                temp = each;
            } else {
                temp = temp.end < each.end ? each : temp;
            }
        }
        return result;
    }

    public static void main(String[] args) {

        List<List<Interval>> schedule = new ArrayList<>();
        List<Interval> list1 = new ArrayList<>();
        list1.add(new Interval(1, 2));
        list1.add(new Interval(5, 6));
        List<Interval> list2 = new ArrayList<>();
        list2.add(new Interval(1, 3));
        List<Interval> list3 = new ArrayList<>();
        list3.add(new Interval(4, 10));
        schedule.add(list1);
        schedule.add(list2);
        schedule.add(list3);
        List<Interval> result = employeeFreeTime(schedule);
        for (Interval interval : result) {
            System.out.println(interval.start + " " + interval.end);
        }
    }
}

class Interval {
    public int start;
    public int end;

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
}