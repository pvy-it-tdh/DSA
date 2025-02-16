from collections import deque

def generate_loc_phat_numbers(N):
    queue = deque(["8", "6"])  # Số lớn nhất có 1 chữ số trước
    result = []

    while queue:
        num = queue.popleft()
        if len(num) > N:
            break
        result.append(num)
        queue.append(num + "8")
        queue.append(num + "6")

    return result

# Đọc số lượng test case
T = int(input().strip())

for _ in range(T):
    N = int(input().strip())
    result = generate_loc_phat_numbers(N)
    print(" ".join(result))
