#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Dlist.h"

// 链表初始化
void dlist_init(stDlistHead *dlist) { 
    dlist->size = 0;
    dlist->head = NULL;
    dlist->tail = NULL;
    
    return;
}

// 删除链表
void dlist_destory(stDlistHead *dlist) {
    stDlistNode *pNode = NULL;

    while (dlist->size > 0) {
        pNode = dlist->head;
        dlist->head = dlist->head->next;
        free(pNode);
        dlist->size--;
    }
    memset(dlist, 0, sizeof(stDlistHead));
    
    return;
}

// 插入头结点，操作的链表，节点，数据
int dlist_insert_head(stDlistHead *dlist, stDlistNode *pNode, int data) {
    // 当只传一个数据时
    if (pNode == NULL) {
        pNode = (stDlistNode *)malloc(sizeof(stDlistNode));
        if (pNode == NULL) {
            return -1;
        }
    }

    pNode->data = data;
    pNode->prev = NULL;
    pNode->next = NULL;
    
    if (dlist->size == 0) { // 如果链表长度为0，即链表当前无节点
        dlist->head = pNode;
        dlist->tail = pNode;
    } else {                // 如果链表已有节点，则令新插入节点为头结点
        pNode->next = dlist->head;
        dlist->head->prev = pNode;
        dlist->head = pNode;
    }

    dlist->size++;          // 每成功调用一次，链表长度+1
    
    return 0;
}

// 删除尾部节点，并返回删除节点
stDlistNode *dlist_remove_tail(stDlistHead *dlist) {
    stDlistNode *pNode = NULL;

    if (dlist->size == 0) {
        return NULL;
    }

    pNode = dlist->tail;
    if (dlist->size > 1) {
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;
    } else {
        dlist->head = NULL;
        dlist->tail = NULL;
    }
    dlist->size--;

    return pNode;
}

// 删除指定节点
void dlist_remove_node(stDlistHead *dlist, stDlistNode *pNode) {
    if ((dlist == NULL) || (pNode == NULL)) {
        return;
    }

    if (dlist->head == pNode) {
        dlist->head = dlist->head->next;
    } else if (dlist->tail == pNode) {
        dlist->tail = pNode->prev;
        dlist->tail->next = NULL;
    } else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }

    dlist->size--;
    pNode->prev = NULL;
    pNode->next = NULL;

    if (dlist->size == 0) {
        // 将dlist 占用内存块的所有值置为0，也就是清空head,tail指针内容
        memset(dlist, 0, sizeof(stDlistHead));
    }

    return;
}

stDlistNode *dlist_search(stDlistHead *dlist, int data) {
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        if (pNode->data == data) {
            return pNode;
        }
        pNode = pNode->next;
    }

    return NULL;
}

// 显示链表中的数据
void dlist_dump(stDlistHead *dlist) {
    int no = 0;
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        printf("\r\n [%d] = %d", no++, pNode->data);
        pNode = pNode->next; // 将pNode的下一个节点赋值给pNode,推进循环
    }

    return;
}

// LRU（最近最少使用）缓存淘汰算法
void Lru_dlist(stDlistHead *dlist, int data) {
    stDlistNode *pNode = NULL;

    pNode = dlist_search(dlist, data);
    if (pNode != NULL) { // 如果在链表中找到这个值，则删除存储这个值的节点，之后把这个节点放在头部；
        dlist_remove_node(dlist, pNode);
    } else if (dlist->size >= 4) { // 没在链表中找到，且链表长度大于4，则从链表中删除尾部节点，将新数据放在头部
        pNode = dlist_remove_tail(dlist);
    }

    dlist_insert_head(dlist, pNode, data);
    
    return;
}
int main() {
    stDlistHead dlist = {0};
    stDlistNode *pNode = NULL;

    dlist_init(&dlist);

    printf("\r\n inset 1,2,3");
    dlist_insert_head(&dlist, NULL, 1);
    dlist_insert_head(&dlist, NULL, 2);
    dlist_insert_head(&dlist, NULL, 3);

    dlist_dump(&dlist);

    pNode = dlist_remove_tail(&dlist);
    if (pNode != NULL) {
        printf("\r\n remove %d", pNode->data);
    }
    dlist_insert_head(&dlist, pNode, 4);
    dlist_dump(&dlist);

    Lru_dlist(&dlist, 5);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 6);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 7);
    dlist_dump(&dlist);
    Lru_dlist(&dlist, 5);
    dlist_dump(&dlist);

    while (dlist.size > 0) {
        pNode = dlist_remove_tail(&dlist);
        if (pNode != NULL) {
            printf("\r\n remove %d", pNode->data);
            free(pNode);
        }
    }

    return 0;
}

