"""
adjacency 
list representation of the graph 
"""
class AdjNode:
    def __init__(self,data):
        self.vertex = data
        self.next = None

class Graph:
    def __init__(self,vertices):
        self.V = vertices
        self.graph = [None] * self.V
    
    def add_edge(self,src,dest):
        node = AdjNode(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        node = AdjNode(src)
        node.next = self.graph[dest]
        self.graph[dest] = node

    def print_graph(self):
        for i in range(self.V):
            temp = self.graph[i]

            while temp:
                print(temp.vertex)
                temp = temp.next

graph = Graph(10)
graph.add_edge(0,1)
graph.add_edge(4,6)
graph.print_graph()