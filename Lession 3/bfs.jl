function bfs(graph, start)
    visited = Dict{Int, Bool}()
    for node in keys(graph)
        visited[node] = false
    end
    queue = [start]
    visited[start] = true
    while length(queue) > 0
        node = popfirst!(queue)
        println(node)
        for neighbor in graph[node]
            if !visited[neighbor]
                push!(queue, neighbor)
                visited[neighbor] = true
            end
        end
    end
end
function main()
    graph = Dict{Int, Vector{Int}}()
    graph[1] = [2, 3]
    graph[2] = [4]
    graph[3] = [5]
    graph[4] = [6]
    graph[5] = [6]
    graph[6] = []
    bfs(graph, 1)
end