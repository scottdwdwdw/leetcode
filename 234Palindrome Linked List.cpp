/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/
//palindrome是指顺着或逆着都是一样的，如 1->2->1 1->2->2->1;
//我的代码：
/*
*   1.找到中点
*   2.翻转第二个链表
*   3.比较元素是否相等
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
        } //移动到第二个链表处
        second=reverse(second);  //翻转第二个链表
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
    ListNode*reverse(ListNode*head) //翻转链表
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

//递归的方法
