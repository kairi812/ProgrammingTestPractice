#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> a(N), b(N), c(N);
    for(int i=0; i<N; ++i) cin >> a[i] >> b[i] >> c[i];
    // 各整数列をソート
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 
    sort(c.begin(), c.end());

    long long res = 0;
    for (int j=0; j<N; ++j) {
        long long Aj = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
        long long Cj = N - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());
        res += Aj * Cj;
    }
    cout << res << endl;
}