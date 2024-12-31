function InsertionSort(A::Vector{Int})
    for i in 2:length(A)
        key = A[i]
        j = i - 1
        while j > 0 && A[j] > key
            A[j + 1] = A[j]
            j = j - 1
        end
        A[j + 1] = key
    end
end

function main()
    A = [5, 2, 4, 6, 1, 3]
    InsertionSort(A)
    println(A)
end

main()