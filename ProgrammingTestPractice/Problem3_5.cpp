#include <iostream>
#include <vector>
#define INF 20000000;
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    int flag = 1;
    int cnt = 0;
    while(flag){
        for(int i=0; i<N; ++i){
            if(a[i] % 2 == 0) a[i] /= 2;
            else flag = 0;
        }
        if(flag==1) ++cnt;
    }

    cout << cnt << endl;
}