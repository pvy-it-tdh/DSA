from itertools import product

def generate_loc_phat(N):
    result = []
    
    # Tạo tất cả số có từ 1 đến N chữ số chỉ gồm '6' và '8'
    for length in range(1, N + 1):
        for num in product("68", repeat=length):
            result.append("".join(num))
    
    # Sắp xếp theo thứ tự giảm dần
    result.sort(reverse=True)
    
    # In ra kết quả
    print(len(result))
    print(" ".join(result))

# Đọc số lượng test case
T = int(input().strip())

for _ in range(T):
    N = int(input().strip())
    generate_loc_phat(N)
