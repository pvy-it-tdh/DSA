import re

def count_words_from_file(file_path):
    word_count = {}  # Dictionary để lưu số lần xuất hiện của từ
    with open(file_path, "r", encoding="utf-8") as file:
        for line in file:  # Đọc từng dòng trong file
            words = re.findall(r"\b\w+\b", line.lower())  # Tách từ, bỏ dấu câu và chuẩn hóa chữ thường
            for word in words:
                word_count[word] = word_count.get(word, 0) + 1  # Cập nhật số lần xuất hiện
    return word_count

# Ví dụ sử dụng
file_path = "./Exam/P1_data.txt"  # Đảm bảo tệp tồn tại
print(count_words_from_file(file_path))
