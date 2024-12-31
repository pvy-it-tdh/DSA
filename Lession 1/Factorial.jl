function Factorial(n)
    if n == 0
        return 1
    else
        return n * Factorial(n-1)
    end
end

function main()
    input = readline()
    println(Factorial(parse(Int64, input)))
end