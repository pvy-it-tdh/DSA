function BubbleSort(arr)
    n = length(arr)
    for i in 1:n
        for j in 1:n-i
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
    end
    return arr
end