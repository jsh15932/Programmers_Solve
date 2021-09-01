import java.io.*;
import java.util.*;

class Solution {
    static int[] arr;
    
    private int getParent(int node) {
        if(arr[node] == node) {
            return node;
        }

        return arr[node] = getParent(arr[node]);
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        Arrays.sort(costs, (int[] a, int[] b) -> a[2] - b[2]);
        arr = new int[n];
        
        for(int i = 0; i < n; i++) {
            arr[i] = i;
        }
        
        for(int[] edge : costs) {
            int start = edge[0];
            int end = edge[1];
            int cost = edge[2];
            
            if(getParent(start) == getParent(end)) {
                continue;
            }
            
            answer += cost;
            arr[getParent(end)] = getParent(start);
        }
            
        return answer;
    }
}