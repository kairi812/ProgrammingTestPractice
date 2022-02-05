#include <iostream>
#include <vector>
#define INF 20000000;
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    int min_value = INF;
    int second_min_value = INF;
    int not_min_value = 0;
    for(int i=0; i<N; ++i){
        if(a[i] < min_value) {
            not_min_value = min_value;
            min_value = a[i];
        }
        else not_min_value = a[i];

        if (not_min_value < second_min_value){
            second_min_value = not_min_value;
        }

    }
    cout << second_min_value << endl;
}