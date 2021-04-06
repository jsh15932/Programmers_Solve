import java.io.*;
import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        int idx = 0;
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ' ') {
                sb.append(' ');
                idx = 0;
            }
            
            else {
                if(idx % 2 != 0) {
                    sb.append(Character.toLowerCase(s.charAt(i)));
                    idx++;
                }
                
                else {
                    sb.append(Character.toUpperCase(s.charAt(i)));
                    idx++;
                }
            }
        }
        
        answer = sb.toString();
        
        return answer;
    }
}