import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n,m,r=map(int, input().split())
arr=[[]for _ in range(n+1)]
visited=[0]*(n+1) #방문배열
ans=[0]*(n+1) #정답
cnt=1 #횟수

for _ in range(m):
    u,v=map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

for i in range(1, n + 1):
    arr[i].sort(reverse=True)

def dfs(s):
    global cnt
    visited[s]=True
    ans[s]=cnt
    for i in arr[s]:
        if not visited[i]:
            cnt+=1
            dfs(i)
dfs(r)

for j in ans[1:]:
    print(j)