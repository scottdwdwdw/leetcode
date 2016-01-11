/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
//�ҵĴ��룬ͬ���������ڴ�й¶
//����shared_ptr?
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

//��������ָ�룺���ٶ�Ҫ������δʹ������ָ��Ҫ�죬Ϊʲô����
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

//�����ö���Ľڵ�
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