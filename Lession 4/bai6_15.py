from collections import deque

# Hàm kiểm tra số nguyên tố
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Tiền xử lý danh sách số nguyên tố có 4 chữ số
def generate_primes():
    primes = set()
    for num in range(1000, 10000):
        if is_prime(num):
            primes.add(num)
    return primes

# Hàm tìm số bước ít nhất để biến S thành T
def min_steps(S, T, primes):
    if S == T:
        return 0

    queue = deque([(S, 0)])  # (số hiện tại, số bước)
    visited = set()
    visited.add(S)

    while queue:
        num, steps = queue.popleft()
        num_str = str(num)

        # Thay đổi từng chữ số một
        for i in range(4):
            for d in "0123456789":
                if num_str[i] == d:  # Không thay đổi chữ số cũ
                    continue
                
                new_num = int(num_str[:i] + d + num_str[i+1:])
                if new_num in primes and new_num not in visited:
                    if new_num == T:
                        return steps + 1
                    queue.append((new_num, steps + 1))
                    visited.add(new_num)

    return -1  # Không thể biến đổi từ S thành T

# Đọc input và xử lý từng test case
def main():
    primes = generate_primes()  # Tiền xử lý các số nguyên tố 4 chữ số
    T = int(input().strip())  # Số lượng test case
    
    for _ in range(T):
        S, T = map(int, input().strip().split())
        print(min_steps(S, T, primes))

# Chạy chương trình
if __name__ == "__main__":
    main()
