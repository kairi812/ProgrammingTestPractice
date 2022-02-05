#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long fibo(int N){
    if (N==0) return 0;
    else if (N==1) return 1;

    if (memo[N] != -1) return memo[N];

    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main(){
    // メモ化用の配列を-1で初期化
    memo.assign(50, -1);

    fibo(49);

    // memo[0]...memo[49]に答えが格納されている
    for(int N=2; N<50; ++N){
        cout << N << "項目" << memo[N] << endl;
    }
}