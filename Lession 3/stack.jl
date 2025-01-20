import Base: push!, pop!

mutable struct Stack{T}
    data::Vector{T}
    Stack{T}() where T = new{T}(T[])
end

function push!(s::Stack{T}, x::T) where T
    push!(s.data, x)
end

function pop!(s::Stack{T}) where T
    isempty(s.data) && throw(ArgumentError("Stack is empty"))
    pop!(s.data)
end

function isempty(s::Stack{T}) where T
    isempty(s.data)
end

function peek(s::Stack{T}) where T
    isempty(s.data) && throw(ArgumentError("Stack is empty"))
    s.data[end]
end 
function main()
    s = Stack{Int}()
    push!(s, 1)
    push!(s, 2)
    push!(s, 3)
    println(peek(s))
    println(pop!(s))
    println(peek(s))
    println(pop!(s))
    println(peek(s))
    println(pop!(s))
    println(isempty(s))
end