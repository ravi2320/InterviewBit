/*
Remove Duplicates from Sorted List II
Programming
Linked Lists
Medium
37.1% Success

280

5

Bookmark
Asked In:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int, int> mp;
    while(A != NULL){
        mp[A->val]++;
        A = A->next;
    }
    ListNode* head = NULL;
    ListNode* curr = NULL;
    for(auto itr : mp)
    {
        if(itr.second > 1) continue;
        else
        {
            if(head == NULL)
            {
                head = new ListNode(itr.first);
                curr = head;
            }
            else
            {
                curr->next = new ListNode(itr.first);
                curr = curr->next;
            }
        }
    }
    return head;
}
