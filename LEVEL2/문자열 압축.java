import java.io.*;
import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = s.length();
        
        if(s.length() == 1) {
            return 1;
        }
        
        for(int i = 1; i < s.length(); i++) {
            String cur = "";
            String tmp = "";
            String comp = "";
            int cnt = 1;
            
            for(int j = 0; j <= s.length() / i; j++) {
                int from = i * j;
                int to = i * (j + 1);
                
                if(to > s.length()) {
                    to = s.length();
                }
                
                cur = comp;
                comp = s.substring(from, to);
                
                if(cur.equals(comp)) {
                    cnt++;
                }
                
                else {
                    if(cnt > 1) {
                        tmp += String.valueOf(cnt);
                    }
                    
                    tmp += cur;
                    cnt = 1;
                }
            }
            
            if(cnt > 1) {
                tmp += String.valueOf(cnt);
            }
            
            tmp += comp;
            answer = Math.min(tmp.length(), answer);
        }
        
        return answer;
    }
}