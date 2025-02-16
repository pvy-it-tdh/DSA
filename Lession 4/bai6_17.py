from collections import deque

# Các bước di chuyển hợp lệ của quân mã
moves = [
    (-2, -1), (-2, 1), (2, -1), (2, 1),
    (-1, -2), (-1, 2), (1, -2), (1, 2)
]

def knight_min_steps(start, end):
    # Chuyển đổi ký tự thành tọa độ số (0-7)
    sx, sy = ord(start[0]) - ord('a'), int(start[1]) - 1
    ex, ey = ord(end[0]) - ord('a'), int(end[1]) - 1

    # Nếu đã ở đích, không cần di chuyển
    if (sx, sy) == (ex, ey):
        return 0

    # BFS tìm đường ngắn nhất
    queue = deque([(sx, sy, 0)])  # (x, y, bước đi)
    visited = set()
    visited.add((sx, sy))

    while queue:
        x, y, steps = queue.popleft()

        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 8 and 0 <= ny < 8 and (nx, ny) not in visited:
                if (nx, ny) == (ex, ey):
                    return steps + 1
                queue.append((nx, ny, steps + 1))
                visited.add((nx, ny))

    return -1  # Không tìm thấy đường đi

# Xử lý input
def main():
    T = int(input().strip())  # Số test
    for _ in range(T):
        start, end = input().strip().split()
        print(knight_min_steps(start, end))

# Chạy chương trình
if __name__ == "__main__":
    main()
