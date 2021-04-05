import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        ArrayList<Integer> tmp = new ArrayList<>();
        tmp.add(arr[0]);
        
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] != arr[i - 1]) {
                tmp.add(arr[i]);
            }
        }
        
        answer = new int[tmp.size()];
        
        for(int i = 0; i < tmp.size(); i++) {
            answer[i] = tmp.get(i);
        }
      
        return answer;
    }
}