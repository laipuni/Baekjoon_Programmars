import sys
from queue import PriorityQueue

def dijkstra(start,v,e):
    def relax(weight,next,nextWeight):
        totalWeight = weight + nextWeight
        if distTo[next] > totalWeight:
            distTo[next] = totalWeight
            pq.put((totalWeight, next))
    
    visited = [False for _ in range(v+1)] # 방문하지 않은 정점은 모두 False
    distTo = [float("INF") for _ in range(v + 1)] # 초기 최단거리 설정
    distTo[start] = 0 # 시작점은 거리 0으로 설정
    # 우선 순위 큐 선언
    # (우선순위, 값)의 튜플의 형태로 데이터를 추가하고 제거
    pq = PriorityQueue()
    # (연결된 정점, 가중치)로 저장
    pq.put((0,start)) 

    while pq.qsize() > 0 :
        weight,now = pq.get()
        visited[now] = True
        for next,nextWeight in adj[now]:
            if visited[next] :
                #이미 방문한 정점이면 다음 iteration으로
                continue
            relax(weight,next,nextWeight)
    return distTo

V, E = list(map(int, sys.stdin.readline().rsplit()))
start = int(sys.stdin.readline())

adj = [[] for _ in range(V + 1)]

for i in range(E):
    v,w,weight = map(int, sys.stdin.readline().split())
    adj[v].append((w,weight))

result = dijkstra(start, V, E)
for sp in range(1,V+1):
    if result[sp] == float("inf"):
        print("INF")
    else :
        print(result[sp])