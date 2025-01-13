function SelectionSort(arr)
    n = length(arr)
    for i in 1:n
        minIndex = i
        for j in i+1:n
            if arr[j] < arr[minIndex]
                minIndex = j
            end
        end
        arr[i], arr[minIndex] = arr[minIndex], arr[i]
    end
    return arr
end

arr = [64, 25, 12, 22, 11]
println(SelectionSort(arr))
