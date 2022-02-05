#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    vector<int> a(N);

    for(int i=0; i<N; ++i) cin >> a[i];

    // bit による部分集合の全探索
    bool exist = false;
    // << はシフト演算子。1をNだけずらすので、二進法になる。
    // Nは集合のサイズで、2^N個分探索できる
    for(int bit=0; bit<(1<<N); ++bit){
        int sum = 0;
        for(int i=0; i<N; ++i){
            if(bit & (1<<i)){
                sum += a[i];
            }
        }
        if(sum == W) exist = true;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}