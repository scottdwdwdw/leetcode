/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/
//palindrome��ָ˳�Ż����Ŷ���һ���ģ��� 1->2->1 1->2->2->1;
//�ҵĴ��룺
/*
*   1.�ҵ��е�
*   2.��ת�ڶ�������
*   3.�Ƚ�Ԫ���Ƿ����
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode*second=head;
        auto count=size(head);
        auto mid= (count/2)-1;
        auto mid_second=(count%2)?(mid+2):(mid+1);
        for(int i=0;i<mid_second;++i)
        {
            second=second->next;
        } //�ƶ����ڶ�������
        second=reverse(second);  //��ת�ڶ�������
        while(second)
        {
            if((head->val)!=(second->val))return false;
            else
            {
                head=head->next;
                second=second->next;
            }
        }
        return true;
        
    }
private:
    ListNode*reverse(ListNode*head) //��ת����
    {
        ListNode*node=NULL;
        while(head)
        {
            ListNode*nxt=head->next;
            head->next=node;
            node=head;
            head=nxt;
        }
        return node;
    }
    size_t size(ListNode*head) const
    {
        size_t count=0;
        while(head)
        {
            head=head->next;
            ++count;
        }
        return count;
    }
};

//�ݹ�ķ���
