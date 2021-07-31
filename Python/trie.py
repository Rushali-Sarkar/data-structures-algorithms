class node:

    def __init__(self, value = ""):
        self.value = value
        self.children = [None for i in range(26)]


class Trie:

    def __init__(self):
        self.table = node()

    def insert(self, word, table = None):

        if word == "":
            return;

        if table == None:
            table = self.table

        for each in word:
            index = ord(each) - 97
            if table.children[index] == None:
                table.children[index] = node(each)
            self.insert(word[1:], table.children[index])
        return

    def print_table(self, table = None):

        if table == None:
            table = self.table

        for i in range(26):
            if table.children[i] != None:
                print(table.children[i].value, end = "*")
                self.print_table(table.children[i])
        return;
            

x = Trie()
x.insert("apple")
x.print_table()
