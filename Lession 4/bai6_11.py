from collections import deque

# Các hướng di chuyển trong không gian 3D (trên, dưới, trái, phải, trước, sau)
directions = [
    (1, 0, 0), (-1, 0, 0),  # Trên, Dưới
    (0, 1, 0), (0, -1, 0),  # Phải, Trái
    (0, 0, 1), (0, 0, -1)   # Trước, Sau
]

def bfs_3d(A, B, C, box, start):
    queue = deque([(start[0], start[1], start[2], 0)])  # (x, y, z, steps)
    visited = set([start])

    while queue:
        x, y, z, steps = queue.popleft()

        # Nếu tìm thấy điểm đích
        if box[x][y][z] == 'E':
            return steps

        for dx, dy, dz in directions:
            nx, ny, nz = x + dx, y + dy, z + dz

            # Kiểm tra biên
            if 0 <= nx < A and 0 <= ny < B and 0 <= nz < C:
                if (nx, ny, nz) not in visited and box[nx][ny][nz] in {'.', 'E'}:
                    queue.append((nx, ny, nz, steps + 1))
                    visited.add((nx, ny, nz))

    return -1  # Không tìm được đường đi

# Đọc dữ liệu
T = int(input())  # Số test case
for _ in range(T):
    A, B, C = map(int, input().split())

    box = []
    start = None

    for i in range(A):
        layer = []
        for j in range(B):
            row = list(input().strip())
            if 'S' in row:
                start = (i, j, row.index('S'))  # Lưu vị trí 'S'
            layer.append(row)
        box.append(layer)
        if i < A - 1:
            input()  # Bỏ qua dòng trống giữa các khối

    # Gọi BFS để tìm đường đi ngắn nhất
    print(bfs_3d(A, B, C, box, start))
