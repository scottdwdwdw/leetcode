/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
//我的代码，同样，代码内存泄露
//改用shared_ptr?
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*before_head=new ListNode(-1);
        ListNode*pre=before_head;
        before_head->next=head;
        while(head)
        {
            if(head->val==val)
            {
                pre->next=head->next;
                head=pre->next;
            }
            else
            {
                pre=pre->next;
                head=head->next;
            }
        }
        return before_head->next;
    }
};

//采用智能指针：（速度要比上面未使用智能指针要快，为什么？）
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       // ListNode*before_head=new ListNode(-1);
       std::shared_ptr<ListNode>before_head=make_shared<ListNode>(-1);
       ListNode*pre=before_head.get();
        before_head.get()->next=head;
        while(head)
        {
            if(head->val==val)
            {
                pre->next=head->next;
                head=pre->next;
            }
            else
            {
                pre=pre->next;
                head=head->next;
            }
        }
        return before_head.get()->next;
    }
};

//不适用额外的节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode * tmp = head;
        ListNode * prevTmp = NULL;
        while(tmp)
        {
            if(tmp->val == val)
            {
                if(prevTmp)
                {
                    prevTmp->next = tmp->next;
                    tmp = tmp->next;
                }
                else
                {
                    head = tmp->next;
                    tmp = tmp->next;
                }
            }
            else
            {
                prevTmp = tmp;
                tmp = tmp->next;
            }
        }

        return head;
    }
};