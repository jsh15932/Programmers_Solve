import java.util.*;
import java.io.*;

class Solution {
    public class Printer {
        int location;
        int prior;
        
        Printer(int location, int prior) {
            this.location = location;
            this.prior = prior;
        }
    }
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Printer> que = new LinkedList<>();
        
        for(int i = 0; i < priorities.length; i++) {
            que.offer(new Printer(i, priorities[i]));
        }
        
        while(que.size() != 0) {
            boolean chk = false;
            int cur = que.peek().prior;
            
            for(Printer p : que) {
                if(cur < p.prior) {
                    chk = true;
                }
            }
            
            if(chk) {
                que.offer(que.poll());
            }
            
            else {
                if(que.poll().location == location) {
                    answer = priorities.length - que.size();
                }
            }
        }
        
        return answer;
    }
}