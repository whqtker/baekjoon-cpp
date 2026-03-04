package boj.boj_2056;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] duration = new int[n + 1];
        int[] inDegree = new int[n + 1];
        int[] dp = new int[n + 1];
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);

            int dur = Integer.parseInt(st.nextToken());
            duration[i] = dur;

            int cnt = Integer.parseInt(st.nextToken());
            for (int j = 0; j < cnt; j++) {
                int prev = Integer.parseInt(st.nextToken());
                inDegree[i]++;
                graph.get(prev).add(i); // prev -> i
            }
        }

        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
                dp[i] = duration[i];
            }
        }

        while (!queue.isEmpty()) {
            int x = queue.poll();

            for (int y : graph.get(x)) {
                inDegree[y]--;
                dp[y] = Math.max(dp[y], dp[x] + duration[y]);

                if (inDegree[y] == 0) queue.offer(y);
            }
        }

        int ans = Arrays.stream(dp).max().getAsInt();
        sb.append(ans);
        System.out.println(sb);
    }
}
