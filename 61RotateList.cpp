/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

//ÎÒµÄ´úÂë£º
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto n=size(head); 
        if(n==0)return head;
        if((k=k%n)==0)return head;
        
        auto first_part=n-k;
        ListNode*first=head;
        while((--first_part)>0)
        {
            first=first->next;
        }
        ListNode*second=first->next;
        ListNode*second_tmp=second;
        first->next=NULL;
        while((--k)>0)
        {
            second_tmp=second_tmp->next;
        }
        second_tmp->next=head;
        head=second;
        return head;
    }
private:
   std::size_t size(ListNode*head) const
   {
       std::size_t n=0;
       ListNode*cur=head;
       while(cur!=NULL)
       {
           cur=cur->next;
           ++n;
       }
       return n;
   }
};