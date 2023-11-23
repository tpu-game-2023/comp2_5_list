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
	if (!p)
		return NULL;

	if (l->footer == NULL)
		l->footer = p;
	
	else {
		p->pNext = l->header;
		l->header->pPrev = p;
	}

	p->pPrev = NULL;
	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (!p)
		return NULL;

	if (l->header == NULL)
		l->header = p;
	
	else {
		p->pPrev = l->footer;
		l->footer->pNext = p;
	}

	p->pNext = NULL;
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (!p)
		return NULL;

	if (l->header != p)
		get_prev(l, p)->pNext = p->pNext;
	else
		l->header = p->pNext;

	if (l->footer != p)
		get_next(l, p)->pPrev = p->pPrev;
	else
		l->footer = p->pPrev;
	initialize_node(p, p->data);
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	p = p->pNext;
	remove_node(l, p);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	p = p->pPrev;
	remove_node(l, p);
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
