import java.io.*;
import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();
        int idx = 0;
        int cmp = 0;
        
        for(int i = 0; i < number.length() - k; i++) {
            cmp = 0;
            
            for(int j = idx; j <= i + k; j++) {
                if(cmp < number.charAt(j) - '0') {
                    cmp = number.charAt(j) - '0';
                    idx = j + 1;
                }
            }
            
            answer.append(cmp);
        }
        
        return answer.toString();
    }
}