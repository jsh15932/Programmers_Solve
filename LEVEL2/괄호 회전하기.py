def solve(s):
    st = []
    for i in s:
        if len(st) == 0: 
            st.append(i)
        else:
            if i == ")" and st[-1] == "(":
                st.pop()
            elif i == "]" and st[-1] == "[":
                st.pop()
            elif i == "}" and st[-1] == "{":
                st.pop()
            else: st.append(i)
    
    if len(st) == 0:
        return 1
    else:
        return 0

def solution(s):
    answer = 0
    
    for i in range(len(s)):
        if solve(s):
            answer += 1
        
        s = s[1:] + s[:1]
    
    return answer