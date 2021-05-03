def solution(people, limit):
    answer = 0
    people.sort()
    idx = 0
    k = len(people) - 1
    
    while idx <= k:
        answer += 1
        
        if people[idx] + people[k] <= limit:
            idx += 1
        
        k -= 1
        
    return answer