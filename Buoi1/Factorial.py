def Factorial(n):
    if n == 0:
        return 1
    return n * Factorial(n - 1)

def main():
    n = int(input("Enter a number: "))  # Chuyển đổi input thành số nguyên
    print(Factorial(n))

if __name__ == "__main__":
    main()
