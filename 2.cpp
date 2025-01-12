//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {

    int person;
    int jump;
    cin >> person;
    cin >> jump;

    queue<string> q;

    for(int i = 0; i < person; i++){
        string name;
        cin >> name;
        q.push(name);
        
    }

    int count = 0;
    while(!q.empty()){
        string current = q.front();
        q.pop();

        if (count==jump) {
            q.push(current);
            count=0;
            continue;
        } else {
            cout << current + "\n";

        }
        count++;    

    }
    
}
