import collections
# BFS
def cloneGraph1(self, node):
    if not node:
        return 
    nodeCopy = UndirectedGraphNode(node.label)
    dic = {node: nodeCopy}
    queue = collections.deque([node])
    while queue:
        node = queue.popleft()
        for neighbor in node.neighbors:
            if neighbor not in dic: # neighbor is not visited
                neighborCopy = UndirectedGraphNode(neighbor.label)
                dic[neighbor] = neighborCopy
                dic[node].neighbors.append(neighborCopy)
                queue.append(neighbor)
            else:
                dic[node].neighbors.append(dic[neighbor])
    return nodeCopy

# DFS iteratively
def cloneGraph2(self, node):
    if not node:
        return 
    nodeCopy = UndirectedGraphNode(node.label)
    dic = {node: nodeCopy}
    stack = [node]
    while stack:
        node = stack.pop()
        for neighbor in node.neighbors:
            if neighbor not in dic:
                neighborCopy = UndirectedGraphNode(neighbor.label)
                dic[neighbor] = neighborCopy
                dic[node].neighbors.append(neighborCopy)
                stack.append(neighbor)
            else:
                dic[node].neighbors.append(dic[neighbor])
    return nodeCopy

# DFS recursively
def cloneGraph(self, node):
    if not node:
        return 
    nodeCopy = UndirectedGraphNode(node.label)
    dic = {node: nodeCopy}
    self.dfs(node, dic)
    return nodeCopy

def dfs(self, node, dic):
    for neighbor in node.neighbors:
        if neighbor not in dic:
            neighborCopy = UndirectedGraphNode(neighbor.label)
            dic[neighbor] = neighborCopy
            dic[node].neighbors.append(neighborCopy)
            self.dfs(neighbor, dic)
        else:
            dic[node].neighbors.append(dic[neighbor])