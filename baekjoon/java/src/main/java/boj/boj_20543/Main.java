package boj.boj_20543;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static long[][] result, tmp1, tmp2, ans;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        result = new long[n][n];
        tmp1 = new long[n][n];
        tmp2 = new long[n][n];
        ans = new long[n][n];

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line);
            for (int j = 0; j < n; j++) {
                result[i][j] = Long.parseLong(st.nextToken());
            }
        }

        // 이차원 배열 누적 합을 역순으로 진행한다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp1[i][j] = result[i][j] - (j > 0 ? result[i][j - 1] : 0);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                tmp2[i][j] = tmp1[i][j] - (i > 0 ? tmp1[i - 1][j] : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp2[i][j] < 0) {
                    if (i + m / 2 < n && j + m / 2 < n) {
                        ans[i + m / 2][j + m / 2] = -tmp2[i][j];
                    }

                    if (i + m < n && j + m < n) tmp2[i + m][j + m] -= tmp2[i][j];
                    if (i + m < n) tmp2[i + m][j] += tmp2[i][j];
                    if (j + m < n) tmp2[i][j + m] += tmp2[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(ans[i][j]).append(' ');
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }
}