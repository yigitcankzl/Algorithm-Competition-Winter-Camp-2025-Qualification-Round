//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int M;
    int N;
    cin >> M >> N;

    int firstColXOR = 0;
    vector<int> firstRow(N);
    for (int i = 0; i < N; i++){
        cin >> firstRow[i];
        firstColXOR = firstRow[i] ^ firstColXOR;
    }


    int firstRowXOR =0;
    vector<int> firstCol(M);
    for (int i = 0; i < M; i++){
        cin >> firstCol[i];
        firstRowXOR = firstCol[i] ^ firstRowXOR;
    }


 

    vector<vector<int>> sifreli(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sifreli[i][j];
        }
    }


    vector<vector<int>> original(M, vector<int>(N));
    for (int j = 0; j < N; j++){ 
        original[0][j] = firstRow[j];
    }

    for (int i = 0; i < M; i++){    
        original[i][0] = firstCol[i];
    }   




    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {         
            
            int row_xor = sifreli[i][0] ^ firstRowXOR ^ original[i][0];

            
            int col_xor = sifreli[0][j] ^ firstColXOR ^ original[0][j];


            original[i][j] = sifreli[i][j] ^ row_xor ^ col_xor;
        }
    }





    //yazdir
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << original[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << endl;
    }
}
