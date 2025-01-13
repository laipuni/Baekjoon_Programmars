import sys
N, K = list(map(int, sys.stdin.readline().rsplit()))
A = list(map(int, sys.stdin.readline().rsplit()))

def insertion_sort(lst, K):
    cnt = 0
    for i in range(1, len(lst)):
        loc = i - 1
        newItem = lst[i]

        while (0 <= loc and newItem < lst[loc]):
            cnt += 1
            lst[loc+1] = lst[loc]
            loc -= 1
            if cnt == K:
                print(lst[loc+1])
                return
        if (loc + 1 != i):
            cnt += 1
            lst[loc + 1] = newItem            
            if cnt == K:
                print(lst[loc+1])
                return 
    print(-1)
    return 
insertion_sort(A,K)
