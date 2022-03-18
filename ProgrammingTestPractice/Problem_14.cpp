#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N; cin >> N;
    long long A[10000];
    long long B[10000];
    for (int i=0; i<N; ++i) cin >> A[i];
    for (int j=0; j<N; ++j) cin >> B[j];

    sort(A+1, A+N+1);
    sort(B+1, B+N+1);

    long long Answer = 0;
    for (int i=0; i<N; ++i) Answer += abs(A[i] - B[i]);
    cout << Answer << endl;
    return 0;
}