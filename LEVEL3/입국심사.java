import java.io.*;
import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        long min = 1;
        long max = (long)times[times.length - 1] * n;
        long sum;
        long mid = 0;
        answer = max;
        
        while(max >= min) {
            sum = 0;
            mid = (max + min) / 2;
            
            for(int t : times) {
                sum += mid / t;
            }
            
            if(sum >= n) {
                if(mid < answer) {
                    answer = mid;
                }
                
                max = mid - 1;
            }
            
            else {
                min = mid + 1;
            }
        }
        
        return answer;
    }
}