import java.io.*;
import java.util.*;

class Solution {
    static boolean[] chk;
    static ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
    static Queue<Integer> que = new LinkedList<>();
    
    public int solve() {
        int cnt = 0;
        
        que.add(1);
        chk[1] = true;
        
        while(true) {
            Queue<Integer> tmp = new LinkedList<>();
            
            while(!que.isEmpty()) {
                int cur = que.poll();
                
                for(int i : arr.get(cur)) {
                    if(!chk[i]) {
                        tmp.add(i);
                        chk[i] = true;
                    }
                }
            }
            
            if(tmp.isEmpty()) {
                break;
            }
            
            que.addAll(tmp);
            cnt = tmp.size();
        }
        
        return cnt;
    }
    
    public int solution(int n, int[][] edge) {
        chk = new boolean[n + 1];
        
        for(int i = 0; i <= n; i++) {
            arr.add(i, new ArrayList<>());
        }
        
        for(int i = 0; i < edge.length; i++) {
            arr.get(edge[i][0]).add(edge[i][1]);
            arr.get(edge[i][1]).add(edge[i][0]);
        }
        
        int answer = solve();
        
        return answer;
    }
}