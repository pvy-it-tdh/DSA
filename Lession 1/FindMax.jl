function FindMax(A::Vector{Int})
    max = A[1]
    for i in 2:length(A)
        if A[i] > max
            max = A[i]
        end
    end
    return max
end
function main()
    A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    println(FindMax(A))
end

main()

