import java.io.*;
import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = String.valueOf(n);
        char[] c = new char[s.length()];
        
        for(int i = 0; i < s.length(); i++) {
            c[i] += s.charAt(i);
        }
        
        Arrays.sort(c);
        
        String res = "";
        
        for(int i = c.length - 1; i >= 0; i--) {
            res += c[i];
        }
        
        answer = Long.parseLong(res);
        
        return answer;
    }
}