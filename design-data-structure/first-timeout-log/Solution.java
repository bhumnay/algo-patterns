import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

class Log {
    String id;
    int time;
    boolean isStart;

    public Log(String id, int time, boolean isStart) {
        this.id = id;
        this.time = time;
        this.isStart = isStart;
    }
}

public class Solution {
    public String getFirstTimeoutLog(Log[] logs, int timeout) {
        Set<String> map = new HashSet<>();
        Queue<Log> queue = new LinkedList<>();
        for (Log log : logs) {
            if (log.isStart) {
                map.add(log.id);
                queue.add(log);
            } else {
                if (map.contains(log.id)) {
                    map.remove(log.id);
                }
            }
            while (!queue.isEmpty() && queue.peek().time + timeout < log.time) {
                if (map.contains(queue.peek().id)) {
                    return queue.peek().id;
                }
                queue.poll();
            }
        }
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Log[] logs;
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(
                    "Logs.txt")));
            String line = reader.readLine();
            int n = Integer.parseInt(line);
            logs = new Log[n];
            for (int i = 0; i < n; i++) {
                line = reader.readLine();
                String[] parts = line.split(" ");
                System.out.println(parts[0] + " " + parts[1] + " " + parts[2]);
            }
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
        Solution solution = new Solution();
        System.out.println(solution.getFirstTimeoutLog(logs, 1));
    }
}
