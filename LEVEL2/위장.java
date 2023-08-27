import java.io.*;
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String[] c : clothes) {
            String type = c[1];
            map.put(type, map.getOrDefault(type, 0) + 1);
        }
        
        Iterator<Integer> it = map.values().iterator();
        
        while(it.hasNext()) {
            answer *= it.next().intValue() + 1;
        }
        
        return answer - 1;
    }
}