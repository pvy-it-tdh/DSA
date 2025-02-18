def levenshtein_distance(source, target):
    m = len(source) + 1  
    n = len(target) + 1  

    D = [[0] * n for _ in range(m)]

    for i in range(m):
        D[i][0] = i  # Chi phí xoá
    for j in range(n):
        D[0][j] = j  # Chi phí thêm

    for i in range(1, m):
        for j in range(1, n):
            del_cost = D[i - 1][j] + 1  # Chi phí xoá
            ins_cost = D[i][j - 1] + 1  # Chi phí thêm
            sub_cost = D[i - 1][j - 1] + (0 if source[i - 1] == target[j - 1] else 1)  # Chi phí thay thế

            # Giá trị tại D[i][j] là chi phí nhỏ nhất của 3 phép biến đổi
            D[i][j] = min(del_cost, ins_cost, sub_cost)
    return D[m - 1][n - 1]


# Ví dụ sử dụng
source = "kitten"
target = "sitting"
distance = levenshtein_distance(source, target)
print(f"Khoang cach Levenshtein giua '{source}' va '{target}' la: {distance}")
