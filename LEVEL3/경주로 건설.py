from collections import deque

def solution(board):
    answer = 0
    maxN = len(board) - 1

    def bfs(start):
        q = deque([])
        q.append((0, 0, start, 0))
        check = {(0, 0): 0}
        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        while q:
            x, y, d, c = q.popleft()
            for i in range(4):
                nextX = x + dx[i]
                nextY = y + dy[i]
                if nextX >= 0 and nextY >= 0 and nextX <= maxN and nextY <= maxN and board[nextX][nextY] != 1:
                    if d == i:
                        nextC = c + 100
                    else:
                        nextC = c + 600
                    if (nextX, nextY) not in check or nextC <= check[(nextX, nextY)]:
                        check[(nextX, nextY)] = nextC
                        q.append((nextX, nextY, i, nextC))
                        
        return check[(maxN, maxN)]

    answer = min(bfs(2), bfs(3))

    return answer