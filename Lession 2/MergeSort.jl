function MergeSort(arr)
    if length(arr) <= 1
        return arr
    end
    mid = length(arr) ÷ 2
    left = MergeSort(arr[1:mid])
    right = MergeSort(arr[mid+1:end])
    return Merge(left, right)
end
function Merge(left, right)
    result = []
    i = 1
    j = 1
    while i <= length(left) && j <= length(right)
        if left[i] < right[j]
            push!(result, left[i])
            i += 1
        else
            push!(result, right[j])
            j += 1
        end
    end
    while i <= length(left)
        push!(result, left[i])
        i += 1
    end
    while j <= length(right)
        push!(result, right[j])
        j += 1
    end
    return result
end