//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    long long k; // toplam
    cin >> n >> k;
    
    vector<int> v(n); 
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    const int MOD = 1e9 + 7; 
    vector<vector<int>> ways(n + 1, vector<int>(4, 0)); 
    
    ways[0][0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 3; j++) {
            ways[i + 1][j] = ways[i][j];
        }
        
        long long sum = 0; 
        for(int start = i; start >= 0; start--) {
            sum += v[start];
            if(sum > k) break; // daha büyükse çık
            if(sum == k) {
                // j segmentten oluşan her bir önceki geçerli durum için
                for(int j = 0; j < 3; j++) {
                    ways[i + 1][j + 1] = (ways[i + 1][j + 1] + ways[start][j]) % MOD;
                }
            }
        }
    }
    
    cout << ways[n][3] << "\n"; // 3 segment oluşturmanın toplam yollarını yazdır
    return 0;
}
