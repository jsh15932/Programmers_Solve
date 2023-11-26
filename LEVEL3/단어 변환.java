import java.io.*;
import java.util.*;

class Solution {
    static boolean visited[];
    static int answer = 987654321;
    
    public int solution(String begin, String target, String[] words) {
        for(int i = 0; i < words.length; i++) {
            if(count(begin, words[i]) <= 1) {
                visited = new boolean[words.length];
                visited[i] = true;
                dfs(1, i, target, words);
                
            }
            
        }
        return answer == 987654321 ? 0 : answer;
    }
    
    static int count(String s1, String s2) {
        int cnt = 0;
        
        for(int i = 0; i < s1.length(); i++) {
            if(s1.charAt(i) != s2.charAt(i)) {
                cnt++;
            }
        }
        
        return cnt;
    }
    
    static void dfs(int cnt, int cur, String target, String[] words) {
        if(target.equals(words[cur])) {
            answer = Math.min(cnt, answer);
            return;
        }
        
        for(int i = 0; i < words.length; i++) {
            if(!visited[i] && count(words[cur], words[i]) == 1) {
                visited[i] = true;
                dfs(cnt + 1, i, target, words);
                visited[i] = false;   
            }
        }
    }
}