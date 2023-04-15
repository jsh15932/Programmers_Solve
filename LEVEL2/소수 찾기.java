import java.io.*;
import java.util.*;

class Solution {
    HashSet<Integer> numberSet = new HashSet<>();
    
    public boolean isPrime(int num) {
        if(num == 0 || num == 1) {
            return false;
        }
        
        for(int i = 2; i <= (int) Math.sqrt(num); i++) {
            if(num % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    public void solve(String comb, String others) {
        if(!comb.equals("")) {
            numberSet.add(Integer.valueOf(comb)); 
        }
        
        for(int i = 0; i < others.length(); i++) {
            solve(comb + others.charAt(i), others.substring(0, i) + others.substring(i + 1));
        }
    }
    
    public int solution(String numbers) {
        int cnt = 0;
        
        solve("", numbers);
        
        Iterator<Integer> it = numberSet.iterator();
        
        while(it.hasNext()) {
            int number = it.next();
            
            if(isPrime(number)) {
                cnt++;
            }
        }
        
        return cnt;
    }
}