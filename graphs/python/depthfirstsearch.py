def depthFirstSearch (graph: {str: [str]}, source: str) -> [str]:

        depth_stack = [source]
        visited = set([])
        depth_first_traversal = []

        while len(depth_stack) != 0:
                current_node = depth_stack[-1]
                depth_stack.pop()
                visited.add(current_node)
                depth_first_traversal.append(current_node)
                for each in graph[current_node]:
                        if each not in visited:
                                depth_stack.append(each)

        return depth_first_traversal


def printArray (arr: [str]) -> None:
        for each in arr:
                print (each, end = " ")
        print ()


if __name__ == "__main__":

        source = 'a'
        graph = {'a': ['b', 'c'], 'b': ['d'], 'c': ['e'], 'd': ['f'], 'e': [], 'f': []}
        depth_first_traversal = depthFirstSearch (graph, source)
        printArray (depth_first_traversal)

