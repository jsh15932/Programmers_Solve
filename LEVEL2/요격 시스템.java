import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, (a, b) -> {
            return a[1] - b[1];
        });
            
        int k = -1;
            
        for(int[] t : targets) {
            if(k == -1) {
                answer++;
                k = t[1] - 1;
                continue;
            }
            
            if(k >= t[0] && k <= t[1]) {
                continue;
            }
            
            answer++;
            k = t[1] - 1;
        }
        
        return answer;
    }
}