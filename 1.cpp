#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    // matematiskel olarka 3 olmali her deger
    for(int n = 1; n <= N; n++) {
        cout << fixed << setprecision(6) << 3.0;
        if(n < N) cout << " ";
    }
    
    return 0;
}
