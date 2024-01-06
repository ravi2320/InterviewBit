/*
Add Two Numbers as Lists
Programming
Linked Lists
Medium
53.0% Success

261

6

Bookmark
Asked In:
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int carry = 0, sum = 0;
    ListNode* head = NULL;
    ListNode* curr = NULL;
    while(A != NULL || B != NULL || carry)
    {
        sum = carry;
        if(A != NULL)
        {
            sum += A->val;
            A = A->next;
        }
        if(B != NULL)
        {
            
            sum += B->val;
            B = B->next;
        }
        if(head == NULL)
        {
            head = new ListNode(sum % 10);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        carry = sum / 10;
    }
    return head;
}
