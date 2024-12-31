def LinearSearch(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1
def main():
    arr = [12, 11, 13, 5, 6]
    x = 13
    print(LinearSearch(arr, x))
if __name__ == "__main__":
    main()