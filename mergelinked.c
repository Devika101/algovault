#include<stdio.h>
// This code merges two sorted linked lists into one sorted linked list.
// The function takes two pointers to the heads of the linked lists and returns a pointer to the head of the merged list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode l;
    l.next = NULL;
    struct ListNode* tail = &l;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return l.next;
}