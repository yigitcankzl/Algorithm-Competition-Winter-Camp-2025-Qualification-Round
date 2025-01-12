#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int N, M, Q;
char grid[MAXN][MAXN];
int dist[205][MAXN][MAXN];
bool vis[MAXN][MAXN];
int startX[205], startY[205];
//4yon
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//inline optimizayon
// gezielcek her hucreyi gez ve hangisin gezdiyse labella
inline void bfs(int id) {
    memset(vis, 0, sizeof(vis)); //unvisiited ladik
    queue<pair<int, int>> q;
    
    if(grid[startX[id]][startY[id]] == '#') return;//#atla
    
    //ilk noktayi qya ekle
    q.push({startX[id], startY[id]});
    dist[id][startX[id]][startY[id]] = 0;
    vis[startX[id]][startY[id]] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //4 yeri gez
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && 
               grid[nx][ny] != '#' && !vis[nx][ny]) {
                dist[id][nx][ny] = dist[id][x][y] + 1;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

inline void process_query(int x, int y) {
    int first_id = -1, last_id = -1;
    int min_dist = INF, max_dist = -1;
    
    for(int i = 0; i < M; ++i) {
        if(dist[i][x][y] != INF) {  //sonsuz olmassa
            //en kisa
            if(dist[i][x][y] < min_dist || 
               (dist[i][x][y] == min_dist && i + 1 < first_id)) {
                min_dist = dist[i][x][y];
                first_id = i + 1;
            } 
            //en uzun
            if(dist[i][x][y] > max_dist) {
                max_dist = dist[i][x][y];
                last_id = i + 1;
            }
        }
    }
    
    cout << first_id << ' ' << last_id << '\n';
}

int main() {
    //opimzayson icn 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // sonsuz baslat
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            fill(dist[i][j], dist[i][j] + N, INF);
        }
    }
    //mtanesi icn
    for(int i = 0; i < M; ++i) {
        cin >> startX[i] >> startY[i];
        bfs(i);
    }
    
    cin >> Q;
    int x, y;
    
    while(Q--) {
        cin >> x >> y;
        process_query(x, y);
    }
    
    return 0;
}