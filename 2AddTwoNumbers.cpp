/*
*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

//我的代码，思路比较复杂，算法复杂度在o(n)；
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *before_head1= new ListNode(-1);
        ListNode *before_head2= new ListNode(-1);
        before_head1->next=l1;before_head2->next=l2;
        size_t n1=size(l1);
        size_t n2=size(l2);
        ListNode *res=(n1>=n2)?l1:l2; 
        ListNode *res_save=res;
        int carr=0;
        while((before_head1->next)&&(before_head2->next))
        {
            
            int temp=(before_head1->next->val+before_head2->next->val+carr)%10;
            carr=(before_head1->next->val+before_head2->next->val+carr)/10;
            res->val=temp;
            res=res->next;
            before_head1=before_head1->next;
            before_head2=before_head2->next;
        }
        if(carr!=0&&res==NULL)
        {
            ListNode *tail=new ListNode(carr);
            res=(n1>=n2)?before_head1:before_head2;
            res->next=tail;
            return res_save;
        }
        while(res!=NULL && res->next!=NULL &&carr!=0)
         {
            int temp=(carr+res->val)%10;
            carr=(carr+res->val)/10;
            res->val=temp;
            res=res->next;
                
           
         }
         if(carr!=0)
         {
            int temp=(carr+res->val)%10;
            carr=(carr+res->val)/10;
            res->val=temp;
            if(carr!=0)
            {
              ListNode *tail=new ListNode(carr);
              res->next=tail;
            }
          }
        
           //delete before_head1;
           //delete before_head2;
           return res_save;
        }
private:
    size_t size(ListNode*head)
    {
        size_t n=0;
        while(head)
        {
            head=head->next;
            ++n;
        }
        return n;
    }

    
};

//思路2
//构建一个新的链表

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *dummy = new ListNode(0), *cur;
    cur = dummy;
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        cur->next = new ListNode(carry%10);
        cur = cur->next;
        carry /= 10;
    }
    return dummy->next;   //有内存泄露的问题
}