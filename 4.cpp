//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {

    int number_of_vectors;
    int vector_size;
    cin >> number_of_vectors;
    cin >> vector_size;

    vector<vector<int>> vectors(number_of_vectors, vector<int>(vector_size));

    for (int i = 0; i < number_of_vectors; i++) {
        for (int j = 0; j < vector_size; j++) {
            cin >> vectors[i][j];
        }
    }

    vector<int> target(vector_size);

    for (int j = 0; j < vector_size; j++) {
        cin >> target[j];
    }

    vector<int> current_sum(vector_size, 0);
    bool possible = false;

    vector<vector<int>> subsets = {vector<int>(vector_size, 0)};
    
    for (int i = 0; i < number_of_vectors; i++) {
        int n = subsets.size();

        for (int j = 0; j < n; j++) {
            vector<int> new_subset = subsets[j];
            for (int k = 0; k < vector_size; k++) {
                new_subset[k] += vectors[i][k];
            }
            subsets.push_back(new_subset);
        }
    }

    for (int i = 0; i < subsets.size(); i++) {
        if (subsets[i] == target) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
