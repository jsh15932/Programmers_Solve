import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[] a = {1, 2, 3, 4, 5};
        int[] b = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int ans_a = 0, ans_b = 0, ans_c = 0;
        
        for(int i = 0; i < answers.length; i++) {
            if(a[i % a.length] == answers[i]) {
                ans_a++;
            }
            
            if(b[i % b.length] == answers[i]) {
                ans_b++;
            }
            
            if(c[i % c.length] == answers[i]) {
                ans_c++;
            }
        }
        
        int max = Math.max(Math.max(ans_a, ans_b), ans_c);
        
        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        if(ans_a == max) {
            arr.add(1);
        }
        
        if(ans_b == max) {
            arr.add(2);
        }
        
        if(ans_c == max) {
            arr.add(3);
        }
        
        answer = new int[arr.size()];
        
        for(int i = 0; i < arr.size(); i++) {
            answer[i] = arr.get(i);
        }        
        
        return answer;
    }
}
