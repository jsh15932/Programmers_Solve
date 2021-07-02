import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        
        for(int i = 0; i < edge.length; i++) {
            list.add(new ArrayList<Integer>());
        }
        
        for(int[] node : edge) {
            int a, b;
            a = node[0];
            b = node[1];
            list.get(a).add(b);
            list.get(b).add(a);
        }
        
        int[] cnt = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> que = new LinkedList<>();
        que.add(1);
        visited[0] = true;
        visited[1] = true;
        
        while(!que.isEmpty()) {
            int cur = que.poll();
            
            for(int v : list.get(cur)) {
                if(!visited[v]) {
                    cnt[v] = cnt[cur] + 1;
                    visited[v] = true;
                    que.add(v);
                }
            }
        }
        
        int max = 0;
        
        for(int i : cnt) {
            if(i > max) {
                max = i;
                answer = 1;
            }
            
            else if(i == max) {
                answer++;
            }
        }
        
        return answer;
    }
}