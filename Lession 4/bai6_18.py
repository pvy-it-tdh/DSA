from collections import deque

def rotate_left(state):
    """Xoay ô bên trái"""
    a1, a2, a3, b1, b2, b3 = state
    return (b1, a1, a3, b2, a2, b3)

def rotate_right(state):
    """Xoay ô bên phải"""
    a1, a2, a3, b1, b2, b3 = state
    return (a1, b1, a2, b2, b3, a3)

def min_steps_to_target(start, target):
    """Tìm số bước ít nhất để chuyển start -> target"""
    if start == target:
        return 0

    queue = deque([(start, 0)])  # (trạng thái hiện tại, số bước)
    visited = set()
    visited.add(start)

    while queue:
        state, steps = queue.popleft()

        # Thử xoay trái
        new_state = rotate_left(state)
        if new_state == target:
            return steps + 1
        if new_state not in visited:
            visited.add(new_state)
            queue.append((new_state, steps + 1))

        # Thử xoay phải
        new_state = rotate_right(state)
        if new_state == target:
            return steps + 1
        if new_state not in visited:
            visited.add(new_state)
            queue.append((new_state, steps + 1))

    return -1  # Không thể chuyển đổi

# Xử lý input
def main():
    T = int(input().strip())  # Số bộ test
    for _ in range(T):
        start = tuple(map(int, input().strip().split()))
        target = tuple(map(int, input().strip().split()))
        print(min_steps_to_target(start, target))

# Chạy chương trình
if __name__ == "__main__":
    main()
