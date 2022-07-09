def breadthFirstSearch (graph: {str: [str]}, source: str) -> [str]:

        breadth_queue = [source]
        visited = set([])
        breadth_first_tree = []

        while len(breadth_queue) != 0:

                current_node = breadth_queue[0]
                breadth_queue.pop(0)
                visited.add (current_node)
                breadth_first_tree.append (current_node)

                for each in graph[current_node]:
                        if each not in visited:
                                breadth_queue.append(each)

        return breadth_first_tree


def printArr(arr: [str]) -> None:

        for each in arr:
                print (each, end = " ")
        print ()
        return None


if __name__ == "__main__":
        
        source = 'a'
        graph = {'a': ['b', 'c'], 'b': ['d'], 'c': ['e'], 'd': ['f'], 'e': [], 'f': []}
        breadth_first_tree = breadthFirstSearch (graph, source)
        printArr (breadth_first_tree)

