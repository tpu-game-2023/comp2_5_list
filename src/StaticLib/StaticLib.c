#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <stdlib.h>

// ノードを初期化
void initialize_node(node* p, int val)
{
    p->pNext = NULL;
    p->pPrev = NULL;
    p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
    l->header = NULL;
    l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p) {
    if (l == NULL || p == NULL) {
        return; // エラー処理
    }
    p->pNext = l->header;
    if (l->header) {
        l->header->pPrev = p;
    }
    else {
        l->footer = p;
    }
    l->header = p;
}

// リストの末尾にノードを追加
void push_back(list* l, node* p) {
    if (l == NULL || p == NULL) {
        return; // エラー処理
    }
    p->pPrev = l->footer;
    if (l->footer) {
        l->footer->pNext = p;
    }
    else {
        l->header= p;
    }
    l->footer = p;
}

// pのノードを削除
// ノードをリストから削除
void remove_node(list* l, node* p) {
    if (l == NULL || p == NULL ) {
        return;
    }
    if (p->pNext) {//ノードを条件分岐に使用する(ノードの要素が存在している場合のみ置き換えを行う)
        p->pNext->pPrev = p->pPrev;
}
    else {
        l->footer = p->pPrev;
    }
    if (p->pPrev) {
        p->pPrev->pNext = p->pNext;
    }
    else {
        l->header = p->pNext;
    }
    p->pNext = p->pPrev = NULL;//消すのはリストじゃない

}
// pの次のノードを削除
void remove_next(list* l, node* p)
{
    if (p == NULL || p->pNext == NULL || l == NULL ) {
      
        return;
    }

    node* nextNode = p->pNext;
    p->pNext = NULL; // NULL 代入
    remove_node(l, nextNode);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
    if (p == NULL || p->pPrev == NULL || l == NULL ) {
        return;
    }

    node* prevNode = p->pPrev;
    p->pPrev = NULL; // NULL 代入
    remove_node(l, prevNode);
}

// pの次のノードを取得
node* get_next(list* l, node* p)
{
    if (!p) return NULL;
    return p->pNext;

    return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
    if (!p) return NULL;
    return p->pPrev;

    return NULL;
}
