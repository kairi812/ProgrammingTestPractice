#include <iostream>
#include <vector>
#define INF 20000000;
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    int min_value = INF;
    int max_value = 0;
    for(int i=0; i<N; ++i){
        if(a[i] < min_value) min_value = a[i];

        if(a[i] > max_value) max_value = a[i];

    }
    int max_difference = max_value - min_value;
    cout << max_difference << endl;
}