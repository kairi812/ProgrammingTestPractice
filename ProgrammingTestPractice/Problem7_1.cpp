#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N; cin >> N;

    vector<int> a(N), b(N);
    for (int i=0; i<N; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    for (int j=0; j<N; ++j) {
        if (a[i] < b[j]) ++i;
    }

    cout << i << endl;
}