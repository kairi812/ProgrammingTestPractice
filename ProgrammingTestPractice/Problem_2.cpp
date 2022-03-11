#include <iostream>
#include <iostream>
using namespace std;

bool hantai(string S) {
    int dep = 0;
    for (int i=0; i<S.size(); ++i) {
        if (S[i] == '(') dep += 1;
        if (S[i] == ')') dep -= 1;
    }
    if (dep==0) return true;
    return false;
}

int main() {
    int N; cin >> N;
    // 全探索
    // ((( : 000
    // (() : 001 ...
    // 上記のように二進数で考える
    for (int i=0; i<N; ++i) {
        string Candidate = "";
        for (int j=N-1; j>=0; j--) {
            // iのjビット目が0であるための条件
            if ((i & (1<<j)) == 0) {
                Candidate += "(";
            } else {
                Candidate += ")";
            }
        }
        // '(' と ')' が同じ数か
        // 全てのiについて、左からi文字目までの時点で
        // '(' の数が ')' の数以上であるか
        bool I = hantai(Candidate);
        if (I == true) cout << Candidate << endl;
    }
    return 0;
}