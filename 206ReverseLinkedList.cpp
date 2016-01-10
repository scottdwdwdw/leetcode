/*
206. Reverse Linked List
Reverse a singly linked list.
*/
//�ҵĴ��룺
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head==NULL)||(head->next==NULL))return head;
        ListNode*pre=NULL;
        ListNode*cur=head;
        ListNode*nextN=cur->next;
        while(cur->next !=NULL)
        {
            cur->next=pre;
            pre=cur;
            cur=nextN;
            nextN=nextN->next;
        }
        cur->next=pre;
        return cur;
    }
};

//�ݹ鷨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
           if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* root = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return root;
    }
};