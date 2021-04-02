import java.io.*;
import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        String s = "";
        
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        int i = 0;
        
        while(i < completion.length) {
            if(!completion[i].equals(participant[i])) {
                s = participant[i];
                break;
            }
            
            else {
                i++;
            }
        }
        
        if(!s.equals("")) {
            answer = s;
        }
        
        else {
            answer = participant[participant.length - 1];
        }
        
        return answer;
    }
}
