import collections
from collections import deque

arr = [10, 1, 2, 4, 7, 2]

ma = collections.deque([10])
mi = collections.deque([10])


for i in range(1, 6):

    while len(ma) != 0:
         
        if arr[i] < ma[-1]:
            ma.append(arr[i])
            break
        ma.pop()

    if len(ma) == 0:
        ma.append(arr[i])

    while len(mi) != 0:

        if arr[i] > mi[-1]:
            mi.append(arr[i])
            break
        mi.pop()

    if len(mi) == 0:
        mi.append(arr[i])


print(ma)
print(mi)
