#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    Node *next; // 自己参照構造体
    string name;

    Node(string name_ = "") : next(NULL), name(name_) {}
};

Node* nil;

// 初期化
void init() {
    nil = new Node();
    nil->next = nil; // 初期状態ではnilがnilを指す
}

// 連結リストの出力
void printList(){
    Node* cur = nil->next;
    for(; cur!=nil; cur=cur->next){
        cout << cur->name << "->";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil){
    v->next = p->next;
    p->next = v;
}

int main(){
    init();

    vector<string> names = {"yamamoto",
                            "watanabe",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "sato"};
    
    // 各ノードを生成し、連結リストの先頭に挿入
    for(int i=0; i<(int)names.size(); ++i){
        Node* node = new Node(names[i]);

        insert(node);

        cout << "step" << i << ":";
        printList();
    }
}