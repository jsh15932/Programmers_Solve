class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = skill_trees.length;
        int pre = 0;
        int cur = 0;
        
        for(int i = 0; i < skill_trees.length; i++) {
            pre = skill_trees[i].indexOf(skill.charAt(0));
            
            for(int j = 1; j < skill.length(); j++) {
                cur = skill_trees[i].indexOf(skill.charAt(j));
                
                if((pre > cur && cur != -1) || (pre == -1 && cur != -1)) {
                    answer--;
                    
                    break;
                }
                
                pre = cur;
            }
        }
        
        return answer;
    }
}