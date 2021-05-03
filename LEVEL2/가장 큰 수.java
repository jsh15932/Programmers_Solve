import java.io.*;
import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] s = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++) {
            s[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(s, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                return (b + a).compareTo(a + b);
            }
        });
        
        if(s[0].equals("0")) {
            return "0";
        }
        
        for(String i : s) {
            answer += i;
        }
        
        return answer;
    }
}