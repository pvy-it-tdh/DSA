def InsertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr
def main():
    arr = [12, 11, 13, 5, 6]
    print(InsertionSort(arr))
if __name__ == "__main__":
    main()
    