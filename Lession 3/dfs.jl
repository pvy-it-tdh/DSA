function dfs(graph, start)
    visited = Dict()
    for node in keys(graph)
        visited[node] = false
    end
    dfs_helper(graph, start, visited)
end
function main()
    graph = Dict()
    graph["A"] = ["B", "C"]
    graph["B"] = ["A", "D", "E"]
    graph["C"] = ["A", "F"]
    graph["D"] = ["B"]
    graph["E"] = ["B", "F"]
    graph["F"] = ["C", "E"]
    dfs(graph, "A")
end