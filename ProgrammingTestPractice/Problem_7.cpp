#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A[300009];
int B[300009];
const int INF = 1 << 19;

int main(){
    int N; cin >> N;
    for (int i=1; i<=N; ++i) cin >> A[i];

    int Q; cin >> Q;
    for (int j=1; j<=Q; ++j) cin >> B[j];

    sort(A+1, A+N+1);

    for (int i=1; i<=Q; ++i) {
        int pos1 = lower_bound(A+1, A+N+1, B[i]) - A;
        int Diff1 = INF, Diff2 = INF;
        if (pos1 <= N) Diff1 = abs(B[i] - A[pos1]);
        if (pos1 >= 2) Diff2 = abs(B[i] - A[pos1 - 1]);
        cout << min(Diff1, Diff2) << endl;
    }

    return 0;
}