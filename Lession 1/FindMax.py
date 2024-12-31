def FindMax(A):
    max = A[0]
    for i in range(1, len(A)):
        if A[i] > max:
            max = A[i]
    return max
def main():
    A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(FindMax(A))
if __name__ == "__main__":
    main()