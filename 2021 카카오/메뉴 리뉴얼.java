import java.io.*;
import java.util.*;

class Solution {
    
    List<String> answerList = new ArrayList<>();
    Map<String, Integer> hashMap = new HashMap<>();
    
     public void combination(String order, String others, int cnt) {
        if(cnt == 0) {
            hashMap.put(order, hashMap.getOrDefault(order, 0) + 1);
            return;
        }
        
        for(int i = 0; i < others.length(); i++) {
            combination(order + others.charAt(i), others.substring(i + 1), cnt - 1);
        }
    }
    
    public String[] solution(String[] orders, int[] course) {       
        for(int i = 0; i < orders.length; i++) {
            char[] arr = orders[i].toCharArray();
            Arrays.sort(arr);
            orders[i] = String.valueOf(arr);
        }
        
        for(int c : course) {
            for(String o : orders) {
                combination("", o, c);
            }
            
            if(!hashMap.isEmpty()) {
                List<Integer> cntList = new ArrayList<>(hashMap.values());
                int maxN = Collections.max(cntList);
                
                if(maxN > 1) {
                    for(String key : hashMap.keySet()) {
                        if(hashMap.get(key) == maxN) {
                            answerList.add(key);
                        }
                    }
                }
                
                hashMap.clear();
            }
        }
        
        Collections.sort(answerList);
        String[] answer = new String[answerList.size()];
        
        for(int i = 0; i < answer.length; i++) {
            answer[i] = answerList.get(i);
        }
        
        return answer;
    }
}