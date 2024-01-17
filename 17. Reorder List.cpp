/*
Reorder List
Programming
Linked Lists
Hard
56.0% Success

307

9

Bookmark
Asked In:
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if (A == NULL || A->next == NULL) {
            return A;
        }
        ListNode* slow = A;
        ListNode* fast = A->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = list2;
        ListNode* forword = NULL;
        while(curr != NULL){
            forword = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forword;
        }
        ListNode* temp = new ListNode(-1);
        ListNode* it = temp;
        while(A != NULL && prev != NULL){
            ListNode* forw1 = A->next;
            it->next = A;
            A = forw1;
            it = it->next;

            ListNode* forw2 = prev->next;
            it->next = prev;
            prev = forw2;
            it = it->next;
        }
        if (A != NULL) {
            it->next = A;
            it = it->next;
        }
        return temp->next;
}
