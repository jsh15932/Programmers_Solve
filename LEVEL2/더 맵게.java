import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue();
        
        for(int i : scoville) {
            pq.offer(i);
        }
        
        while(pq.peek() <= K) {
            if(pq.size() == 1) {
                return -1;
            }
            
            int x = pq.poll();
            int y = pq.poll();
            int res = x + (y * 2);
            
            pq.offer(res);
            answer++;
        }
        
        return answer;
    }
}