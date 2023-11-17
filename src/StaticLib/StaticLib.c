#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


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
void push_front(list* l, node* p)
{
	if (l == NULL || p == NULL) return;

	p->pNext = l->header;
	if (l->header) {
		l->header->pPrev = p;
	}
	else {
		l->footer = p;
	}
	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l == NULL || p == NULL) return;

	p->pPrev = l->footer;
	if (l->footer) {
		l->footer->pNext = p;
	}
	else {
		l->header = p;
	}
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (l == NULL || p == NULL) return;
	
	if (p->pNext) {
		p->pNext->pPrev = p->pPrev;
	}
	else {
		l->footer = p->pPrev;
	}

	if (p->pPrev)
	{
		p->pPrev->pNext = p->pNext;
	}
	else {
		l->header = p->pNext;
	}

	p->pNext = p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (l == NULL || p == NULL || p->pNext == NULL) return;

	node* x = p->pNext;
	if (x->pNext) {
		x->pNext->pPrev = p;
	}
	else {
		l->footer = p;
	}
	p->pNext = x->pNext;
	x->pNext = x->pPrev = NULL;
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (l == NULL || p == NULL || p->pPrev == NULL) return;

	node* x = p->pPrev;
	if (x->pPrev) {
		x->pPrev->pNext = p;
	}
	else {
		l->header = p;
	}
	p->pPrev = x->pPrev;
	x->pPrev = x->pNext = NULL;
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
