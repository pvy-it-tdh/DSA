from collections import deque

def min_days_to_grow(R, C, grid):
    queue = deque()
    days = -1
    total_seeds = 0  # Đếm tổng số hạt giống cần nảy mầm

    # Bước 1: Tìm các cây non ban đầu và đếm số hạt giống cần nảy mầm
    for i in range(R):
        for j in range(C):
            if grid[i][j] == 2:
                queue.append((i, j, 0))  # Lưu tọa độ cây non kèm số ngày = 0
            elif grid[i][j] == 1:
                total_seeds += 1

    # Nếu không có hạt giống nào thì thời gian cần thiết là 0 ngày
    if total_seeds == 0:
        return 0

    # Định nghĩa 4 hướng di chuyển (trái, phải, trên, dưới)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # Bước 2: BFS để lan truyền chất dinh dưỡng
    while queue:
        x, y, day = queue.popleft()
        days = max(days, day)

        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            # Kiểm tra xem ô mới có hợp lệ không
            if 0 <= nx < R and 0 <= ny < C and grid[nx][ny] == 1:
                grid[nx][ny] = 2  # Biến thành cây non
                queue.append((nx, ny, day + 1))
                total_seeds -= 1  # Giảm số hạt giống chưa nảy mầm

    # Nếu còn hạt giống nào chưa nảy mầm, trả về -1
    return days if total_seeds == 0 else -1

# Đọc dữ liệu đầu vào
T = int(input())  # Số test case
for _ in range(T):
    R, C = map(int, input().split())  # Kích thước lưới
    grid = [list(map(int, input().split())) for _ in range(R)]
    
    # Gọi hàm xử lý và in kết quả
    print(min_days_to_grow(R, C, grid))
