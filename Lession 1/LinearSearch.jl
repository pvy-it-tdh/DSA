function LinearSearch(arr, x)
    for i in 1:length(arr)
        if arr[i] == x
            return i
        end
    end
    return -1
end
function main()
    arr = [1, 2, 3, 4, 5]
    x = 3
    println(LinearSearch(arr, x))
end
main()