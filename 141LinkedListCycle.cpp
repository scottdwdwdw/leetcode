/*
*
*   Given a linked list, determine if it has a cycle in it.
*/

//使用两个指针，其中一个指针移动得快，另一个指针移动得慢，如果有循环链表，
//那么两个指针在某一时刻必定相等
//代码:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*first=head;
        ListNode*second=head;
        while(first!=NULL&&first->next!=NULL)
        {
            first=first->next->next;
            second=second->next;
            if(first==second)return true;
        }
        
        return false;
    }
};