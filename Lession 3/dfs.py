def dfs(graph,start):
    stack = [start]
    visited = []
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            stack.extend(graph[node]-set(visited))
    return visited
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
            'C': set(['A', 'F']),
            'D': set(['B']),
            'E': set(['B', 'F']),
            'F': set(['C', 'E'])}
dfs(graph, 'A')
         