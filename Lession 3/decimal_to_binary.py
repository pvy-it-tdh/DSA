def decimail_to_binary(n):
    if n == 0:
        return 0
    else:
        return n % 2 + 10 * decimail_to_binary(n // 2)
    
print(decimail_to_binary(10))
