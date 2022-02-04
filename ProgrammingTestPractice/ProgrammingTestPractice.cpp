// ProgrammingTestPractice.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    // 偶数を求めるプログラム
    // 計算量は O(N)
    //int N;
    //cin >> N;
    //for (int i = 2; i <= N; i += 2) {
    //    cout << i << endl;
    //}

    // 最近点対問題
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        cin >> y[i];
    }

    double minimum_dist = 100000000.0;

    /* 探索開始 */
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

            /* 暫定の最小値 minimum_dist と dist_i_j を比べる */
            if (dist_i_j < minimum_dist) {
                minimum_dist = dist_i_j;
            }
        }
    }

    cout << minimum_dist << endl;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
