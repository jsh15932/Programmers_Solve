import java.io.*;
import java.util.*;

class Solution {
    static int[][] picture;
    static boolean[][] chk;

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        this.picture = picture;
        chk = new boolean[m][n];
        int[] answer = bfs(m, n);

        return answer;
    }

    public int[] bfs(int m, int n) {
        int[] answer = new int[2];
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;

                if(picture[i][j] != 0 && !chk[i][j]) {
                    s1.add(i);
                    s2.add(j);
                    chk[i][j] = true;
                    cnt++;
                    answer[0]++;
                }

                while(!s1.isEmpty()) {
                    int x = s1.pop();
                    int y = s2.pop();

                    if(x > 0 && picture[x - 1][y] == picture[i][j] && !chk[x - 1][y]) {
                        s1.add(x - 1);
                        s2.add(y);
                        chk[x - 1][y] = true;
                        cnt++;
                    }

                    if(y > 0 && picture[x][y - 1] == picture[i][j] && !chk[x][y - 1]) {
                        s1.add(x);
                        s2.add(y - 1);
                        chk[x][y - 1] = true;
                        cnt++;
                    }

                    if(x < m - 1 && picture[x + 1][y] == picture[i][j] && !chk[x + 1][y]) {
                        s1.add(x + 1);
                        s2.add(y);
                        chk[x + 1][y] = true;
                        cnt++;
                    }

                    if(y < n - 1 && picture[x][y + 1] == picture[i][j] && !chk[x][y + 1]) {
                        s1.add(x);
                        s2.add(y + 1);
                        chk[x][y + 1] = true;
                        cnt++;
                    }
                }

                answer[1] = Math.max(cnt, answer[1]);
            }
        }

        return answer;
    }
}