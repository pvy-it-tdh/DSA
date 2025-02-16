from collections import deque

def min_steps_to_end(matrix, M, N):
    # Hàng đợi BFS (dòng, cột, số bước)
    queue = deque([(0, 0, 0)])  
    visited = set()
    visited.add((0, 0))  

    while queue:
        i, j, steps = queue.popleft()
        
        # Nếu đến được vị trí đích, trả về số bước
        if i == M - 1 and j == N - 1:
            return steps
        
        jump = matrix[i][j]

        # Các bước di chuyển hợp lệ
        for ni, nj in [(i, j + jump), (i + jump, j)]:
            if 0 <= ni < M and 0 <= nj < N and (ni, nj) not in visited:
                queue.append((ni, nj, steps + 1))
                visited.add((ni, nj))

    return -1  # Không tìm được đường đi

# Xử lý input
def main():
    T = int(input().strip())  # Số lượng test case
    for _ in range(T):
        M, N = map(int, input().strip().split())  # Kích thước ma trận
        matrix = [list(map(int, input().strip().split())) for _ in range(M)]
        print(min_steps_to_end(matrix, M, N))

# Chạy chương trình
if __name__ == "__main__":
    main()
