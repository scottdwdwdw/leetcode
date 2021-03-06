/*
328. Odd Even Linked List   My Submissions QuestionEditorial Solution
Total Accepted: 29450 Total Submissions: 77604 Difficulty: Medium
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*p1 = head;
        ListNode*p2 = head->next;
        ListNode*head_even = p2;
        while(p1!=NULL&&p2!=NULL&&p2->next!=NULL)
        {
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = head_even;
        
        
        return head;
    }
};