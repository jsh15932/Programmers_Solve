import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> time = new ArrayList<>();
        
        for(int i = 0; i < progresses.length; i++) {
            arr.add(progresses[i]);
            time.add(speeds[i]);
        }
        
        ArrayList<Integer> res = new ArrayList<>();
        
        while(arr.size() > 0) {
            int cnt = 0;
            
            for(int i = 0; i < arr.size(); i++) {
                arr.set(i, arr.get(i) + time.get(i));
            }
            
            for(int i = 0; i < arr.size(); i++) {
                if(i == 0 && arr.get(i) >= 100) {
                    cnt++;
                    arr.remove(i);
                    time.remove(i);
                    i--;
                }
                
                else if(cnt > 0 && arr.get(i) < 100) {
                    break;
                }
                
                else if(cnt > 0 && arr.get(i) >= 100) {
                    cnt++;
                    arr.remove(i);
                    time.remove(i);
                    i--;
                }
            }
            
            if(cnt > 0) {
                res.add(cnt);
            }
        }
        
        answer = new int[res.size()];
        
        for(int i = 0; i < res.size(); i++) {
            answer[i] = res.get(i);
        }
        
        return answer;
    }
}