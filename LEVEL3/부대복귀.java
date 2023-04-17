import java.io.*;
import java.util.*;

class Solution {
    static ArrayList<Integer> arr[];
    static boolean[] chk;
    static int[] dist;
    static Queue<Integer> que;
    
    public void solve() {
        while(!que.isEmpty()) {
            int cur = que.poll();
            
            for(int next : arr[cur]) {
                if(!chk[next]) {
                    chk[next] = true;
                    que.add(next);
                    dist[next] = dist[cur] + 1;
                }
            }
        }
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        arr = new ArrayList[n + 1];
        chk = new boolean[n + 1];
        dist = new int[n + 1];
        
        Arrays.fill(dist, -1);
        
        for(int i = 0; i <= n; i++) {
            arr[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < roads.length; i++) {
            arr[roads[i][0]].add(roads[i][1]);
            arr[roads[i][1]].add(roads[i][0]);
        }
        
        que = new LinkedList<>();
        que.add(destination);
        chk[destination] = true;
        dist[destination] = 0;
        
        solve();
        
        for(int i = 0; i < sources.length; i++) {
            answer[i] = dist[sources[i]];
        }
        
        return answer;
    }
}