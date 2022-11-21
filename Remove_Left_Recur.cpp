#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter no. of productions" << endl;
    cin >> n;
    vector<string> productions;
    cout << "Enter the productions" << endl;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        productions.push_back(s);
    }
    for(int i = 0; i < n; i++){
        char start_symbol = productions[i][0];
        cout << "Grammar " << productions[i];
        if(productions[i][3] == start_symbol){
            cout << " is left recursive" << endl;
            int index = productions[i].find('|');
            if(productions[i].find('|') != string::npos){  
                string alpha = productions[i].substr(4, index - 4);
                string beta = productions[i].substr(index + 1);
                cout << start_symbol << "->" << beta << start_symbol << "'" << endl;
                cout << start_symbol << "'->" << alpha << start_symbol << "'|e" << endl;
            }
            else cout << "can't be reduced" << endl;
        }
        else cout << " is not left recursive" << endl;
    }
    return 0;
}
// 3
// E->E+T|T
// T->T*F|F
// F->(E)|id