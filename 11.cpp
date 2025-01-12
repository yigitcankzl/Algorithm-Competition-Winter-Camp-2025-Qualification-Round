#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

unordered_set<int> theta_nodes, omega_nodes;

bool same_molecule(int u, int v) {
    return (theta_nodes.count(u) && theta_nodes.count(v)) || 
           (omega_nodes.count(u) && omega_nodes.count(v));
}

vector<long long> dijkstra(int start, int N) {
    vector<long long> distances(N + 1, LLONG_MAX); // sonsuz
    distances[start] = 0; // olduğu yer 0

    auto cmp = [](const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first > b.first;
    };

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)> pq(cmp);
    pq.push({0, start});
    
    while (!pq.empty()) { // kuyruk boş olana kadar devam
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > distances[u]) continue; // hesaplanmışsa geç
        
        for (const auto& [v, w] : graph[u]) {  
            if (same_molecule(u, v)) continue; // aynı moleküldeki kenarlardan geçme
            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({distances[v], v});
            }
        }
    }
    
    return distances;
}

long long find_max_shortest_path(int N) {
    long long max_shortest = -1; // bulunumazsa en kısa yok -1 
    
    for (int omega : omega_nodes) { // bütün omegalardan thetalara
        vector<long long> distances = dijkstra(omega, N);
        long long min_to_theta = LLONG_MAX;
        
        for (int theta : theta_nodes) {
            if (distances[theta] != LLONG_MAX) {
                min_to_theta = min(min_to_theta, distances[theta]); // en kısa yolu al
            }
        }
        
        if (min_to_theta != LLONG_MAX) {
            max_shortest = max(max_shortest, min_to_theta); // en uzun en kısa
        }
    }
    
    return max_shortest;
}

int main() {
    
    int N, E;
    cin >> N >> E;
    
    graph.resize(N + 1);
    
    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        
        graph[a].push_back({b, w});  // a,b arası w weight'inde 
        graph[b].push_back({a, w}); // tersine doğru
    }
    
    int Ti;
    cin >> Ti;
    for (int i = 0; i < Ti; i++) {
        int node;
        cin >> node;
        theta_nodes.insert(node);
    }
    
    int Oi;
    cin >> Oi;
    for (int i = 0; i < Oi; i++) {
        int node;
        cin >> node;
        omega_nodes.insert(node);
    }
    
    cout << find_max_shortest_path(N) << "\n";
    
    return 0;
}
