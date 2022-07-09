def depthFirstSearch (visited: set([]), graph: {str: [str]}, source_node: str) -> None:

        print (source_node, end = " ")
        visited.add (source_node)
        for each in graph[source_node]:
                if each not in visited:
                        depthFirstSearch (visited, graph, each)
        return None


if __name__ == "__main__":

        source_node = 'a'
        graph = {'a': ['b', 'c'], 'b': ['d'], 'c': ['e'], 'd': ['f'], 'e': [], 'f': []}
        visited = set([])
        depthFirstSearch (visited, graph, source_node)
        print()
