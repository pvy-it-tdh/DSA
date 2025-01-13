function BinarySearch(arr, target)
    left = 1
    right = length(arr)
    while left <= right
        mid = left + (right - left) ÷ 2
        if arr[mid] == target
            return mid
        elseif arr[mid] < target
            left = mid + 1
        else
            right = mid - 1
        end
    end
    return -1
end
