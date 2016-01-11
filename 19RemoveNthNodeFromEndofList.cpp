/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

//�ҵĴ��룺
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto len=size(head);
        if(len==0)return head;
        if(n>=len)n=len;
        if(n==len)return head->next;
        auto elem_num=len-n;
        ListNode*cur=head;
        while(--elem_num)
        {
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return head;
    }
private:
    size_t size(ListNode*head) const
    {
        size_t count=0;
        ListNode *tmp=head;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            ++count;
        }
        return count;
    }
};

//ʹ�õݹ�
class Solution {
public:
    int remove(ListNode* head, const int& n)
    {
        if (!head)
            return 0;

        int value = remove(head->next, n);   //ÿ�ε��ã����ص�ǰ�ڵ���ţ�Ȼ���ж��ǲ���������Ҫ�ġ�
        if (value == n)
        {
            head->next = head->next->next;
        }

        return value + 1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (remove(head, n)==n)
            return head->next;

        return head;
    }
};

//ʹ������ָ�룬���õ������������ٶȵĲ�ͬ
//
/*-------------------------------------
  dummy->1->2->3->4->5;
  ^
first(second) 
---------------------------------------/

//���ȣ���frist_node��ǰ�ƶ�n�����룬����2
/*-------------------------------------
  dummy->1->2->3->4->5;
    ^       ^
second   first
---------------------------------------*/
//��ʱ��second��first�Ĳ��Ҳ��2,�����������ƶ�����ָ�뵽����β
/*-------------------------------------
  dummy->1->2->3->4->5->NULL;
               ^     ^
           second   first
---------------------------------------*/
//secondָ���λ�ü�ΪҪ�޸ĵ�λ��

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*first=new ListNode(-1);
        ListNode*second=new ListNode(-1);
        ListNode *release_first=first;
        ListNode *release_second=second;
        second->next=head;
        first->next=head;
        if(!head)return head;
        if(!head->next)return NULL;
        for(int i=0;i<n&&(first->next);++i)
        {
            first=first->next;
        }
        while(first->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        
        delete release_first;
      //  delete release_second;
        return release_second->next;
    }

};

//������һ�����⣬��ν�����й¶�����⣿