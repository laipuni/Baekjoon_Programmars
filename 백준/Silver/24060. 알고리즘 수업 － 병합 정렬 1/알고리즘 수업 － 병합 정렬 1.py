import sys

# 백준은 최대 재귀 깊이가 1000으로 설정되어 있어 변경 10^6으로
sys.setrecursionlimit(10**6)

def mergeSort(list,tmpList, lo, hi) :
    if lo >= hi : return
    mid = (lo + hi) // 2
    mergeSort(list,tmpList,lo,mid)
    mergeSort(list,tmpList,mid+1,hi)
    merge(list,tmpList,lo,mid,hi)

def merge(list,tmpList,lo,mid,hi):
    global cnt,result
    for i in range(lo,hi+1):
        tmpList[i] = list[i]
    
    i, j = lo,mid+1
    for idx in range(lo,hi+1):
        if i > mid : 
            list[idx], j = tmpList[j], j + 1
        elif j > hi :
            list[idx], i = tmpList[i], i + 1
        elif tmpList[j] <= tmpList[i] :
            list[idx], j = tmpList[j], j + 1
        else :
            list[idx], i = tmpList[i], i + 1
        cnt += 1
        if cnt == k:
                result = list[idx]

result = -1
cnt = 0
n, k = list(map(int, sys.stdin.readline().rsplit()))
unorederedList = list(map(int, sys.stdin.readline().rsplit()))
tmpList = [None for _ in range(n)]
mergeSort(unorederedList,tmpList,0,n - 1)
print(result)
