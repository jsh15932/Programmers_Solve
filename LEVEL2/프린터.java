import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Printer> que = new LinkedList<>();
        
        for(int i = 0; i < priorities.length; i++) {
            que.add(new Printer(i, priorities[i]));
        }
        
        while(!que.isEmpty()) {
            boolean chk = false;
            int x = que.peek().priority;
            
            for(Printer p : que) {
                if(x < p.priority) {
                    chk = true;
                }
            }
            
            if(chk) {
                que.add(que.poll());
            }
            
            else {
                if(que.poll().location == location) {
                    answer = priorities.length - que.size();
                }
            }
        }
        
        return answer;
    }
    
    class Printer {
        int location;
        int priority;
        
        Printer(int location, int priority) {
            this.location = location;
            this.priority = priority;
        }
    }
}