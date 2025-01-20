function decimal_to_binary(n)
    if n == 0
        return 0
    end
    binary = ""
    while n > 0
        binary = string(n % 2) * binary
        n = div(n, 2)
    end
    return binary
end
function main()
    println(decimal_to_binary(0))
    println(decimal_to_binary(1))
    println(decimal_to_binary(2))
    println(decimal_to_binary(3))
    println(decimal_to_binary(4))
    println(decimal_to_binary(5))
    println(decimal_to_binary(6))
    println(decimal_to_binary(7))
    println(decimal_to_binary(8))
    println(decimal_to_binary(9))
    println(decimal_to_binary(10))
end