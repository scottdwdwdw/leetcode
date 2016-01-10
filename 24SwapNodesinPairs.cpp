/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
//我的代码：
 ListNode* swapPairs(ListNode* head) {
        //if()return head;
        if((head==NULL)||(head->next==NULL))return head;
        ListNode*current=head;
        ListNode*next_node=head->next->next;
        ListNode*swap_pre=NULL;
        ListNode*swap_current=swap_pre;
        swap_current=swapHelper(current,current->next); 
        head=swap_current;
        while(next_node!=NULL)
        {
           if(next_node->next==NULL)
           {
               swap_pre=swap_current;
               swap_pre->next->next=next_node;
               next_node=next_node->next;
           }
           else
           {
               swap_pre=swap_current;
               current=next_node;
               next_node=next_node->next->next;
               swap_current=swapHelper(current,current->next);  
               swap_pre->next->next=swap_current;
               
               
           }
        }
        return head;
    }
private:
    ListNode*swapHelper(ListNode*first,ListNode*second)
    {
        second->next=first;
        first->next=NULL;
        return second;
    }

//比较好的代码：
 ListNode* swapPairs(ListNode* head) {
         ListNode *cur=head;
         if(cur&&cur->next)
         {
            cur=cur->next;
            head->next=swapPairs(cur->next);
            cur->next=head;
         }
         return cur;