from collections import deque

def solution(prices):
    answer = []
    que = deque(prices)
    
    while que:
        que1 = que.popleft()
        cnt = 0
        
        for i in que:
            cnt += 1
            
            if i < que1:
                break
        
        answer.append(cnt)
    
    return answer