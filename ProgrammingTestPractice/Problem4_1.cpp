#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 20000000000

int tribo(int N) {
    if (N==0) return 0;
    else if(N==1) return 0;
    else if(N==2) return 1;

    return tribo(N-1) + tribo(N-2) + tribo(N-3);
}


int main(){
    // int N; cin >> N;
    // cout << tribo(N) << endl;
    vector<long long> T(50);
    T[0] = 0; T[1] = 0; T[2] = 1;
    for (int i=3; i<50; ++i){
        T[i] = T[i-1] + T[i-2] + T[i-3];
    }

    for (int i=0; i<50; ++i) cout << T[i] << endl;
}