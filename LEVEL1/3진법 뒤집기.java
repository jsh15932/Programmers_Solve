import java.io.*;
import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        while(true) {
            if(n < 3) {
                arr.add(n);
                
                break;
            }
            
            arr.add(n % 3);
            n /= 3;
        }
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            answer += (Math.pow(3, i) * arr.get(arr.size() - i - 1));
        }
        
        return answer;
    }
}