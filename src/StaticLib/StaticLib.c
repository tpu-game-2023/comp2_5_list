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
void push_front(list* l, node* newNode) {
    if (l == NULL || newNode == NULL) {
        return; // エラー処理
    }

    if (l->header == NULL) {
        // リストが空の場合
        l->header = newNode;
        l->footer = newNode;
    }
    else {
        // リストが空でない場合
        newNode->pNext = l->header;
        l->header->pPrev = newNode;
        l->header = newNode;
    }
}

// リストの末尾にノードを追加
void push_back(list* l, node* newNode) {
    if (l == NULL || newNode == NULL) {
        return; // エラー処理
    }

    if (l->footer == NULL) {
        // リストが空の場合
        l->header = newNode;
        l->footer = newNode;
    }
    else {
        // リストが空でない場合
        newNode->pPrev = l->footer;
        l->footer->pNext = newNode;
        l->footer = newNode;
    }
}

// pのノードを削除
// ノードをリストから削除
void remove_node(list* l, node* p) {
    if (l == NULL || p == NULL || l->header == NULL) {
        // エラー処理またはデバッグログの出力
        return;
    }

    // ノードが先頭の場合
    if (p == l->header) {
        l->header = p->pNext;
        if (l->header != NULL) {
            l->header->pPrev = NULL;
        }
    }
    else {
        // ノードが先頭でない場合
        if (p->pPrev != NULL) {
            p->pPrev->pNext = p->pNext;
        }
    }

    // ノードが末尾の場合
    if (p == l->footer) {
        l->footer = p->pPrev;
        if (l->footer != NULL) {
            l->footer->pNext = NULL;
        }
    }
    else {
        // ノードが末尾でない場合
        if (p->pNext != NULL) {
            p->pNext->pPrev = p->pPrev;
        }
    }

    // ポインタが NULL でないことを確認してから解放
    free(p);
}




// pの次のノードを削除
void remove_next(list* l, node* p)
{
    if (p == NULL || p->pNext == NULL || l == NULL || l->footer == NULL) {
        // エラー処理またはデバッグログの出力
        return;
    }

    node* nextNode = p->pNext;
    p->pNext = NULL; // NULL 代入
    remove_node(l, nextNode);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
    if (p == NULL || p->pPrev == NULL || l == NULL || l->header == NULL) {
        // エラー処理またはデバッグログの出力
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
