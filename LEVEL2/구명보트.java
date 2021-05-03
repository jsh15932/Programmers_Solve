import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int min = 0;
        
        for(int idx = people.length - 1; idx >= min; idx--) {
            if(people[idx] + people[min] <= limit) {
                min++;
            }
            
            answer++;
        }
        
        return answer;
    }
}