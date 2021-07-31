def insert(word):

    def insert_element(word, table):
        for i in range(len(word)):
            current = word[i:]
            c = table
            for each in current:
                if each not in c:
                    c[each] = {}
                c = c[each]
            c["*"] = {}
        return table



    def print_t(table):
        for each in table:
            print(each, end = "\t")
            print_t(table[each])
            print()
        return
    table = {}
    table = insert_element(word, table)
    print_t(table)
    print(table)
    return


insert("apple")

