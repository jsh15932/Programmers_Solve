import java.io.*;
import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String[] str = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++) {
            str[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(str, (str1, str2) -> (str2 + str1).compareTo(str1 + str2));
        
        if(str[0].equals("0")) {
            return "0";
        }
        
        StringBuilder answer = new StringBuilder();
        
        for(int i = 0; i < str.length; i++) {
            answer.append(str[i]);
        }
        
        return answer.toString();
    }
}