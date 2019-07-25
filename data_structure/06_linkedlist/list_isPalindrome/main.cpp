#include "LinkList.h"
char array1[] = {'a', 'b', 'c', 'b', 'a'};
bool isPalindrome(LinkList *list, int length);

int main() {
    LinkList *list;

    int length = sizeof(array1) / sizeof(array1[0]);
    InitList(list);
    CreateListTail(list, array1, length); // 尾插法创建一个单链表
    ShowList(list);
    if (isPalindrome(list, length))
        printf("isPalindrome\n");
    else
        printf("isNotPalindrome\n");
    return 0;
}

bool isPalindrome(LinkList *list, int length) {
    int i;
    char buff1[length], buff2[length];
    ElemType e;
    for (i = 1; i <= length; i++) {
        // 遍历获取链表元素并放入数组中
        GetListElem(list, i, e); 
        buff1[i-1] = e; // 正向数组
        buff2[length-i] = e; // 反向数组
    }
    i = 0;
    while (i < length) {
        printf("# %c %c\n", buff1[i], buff2[i]);
        if (buff1[i] == buff2[i]) { // 比较
            i++;
        } else {
            return false;
        }
    }
    return true;
}
