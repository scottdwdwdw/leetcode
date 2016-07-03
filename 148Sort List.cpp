/*
148. Sort List   My Submissions QuestionEditorial Solution
Total Accepted: 70141 Total Submissions: 281839 Difficulty: Medium
Sort a linked list in O(n log n) time using constant space complexity.

Subscribe to see which companies asked this question
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
class Solution {
    //¹é²¢ÅÅÐò
public:
    ListNode*find_mid(ListNode*cur)
    {
        ListNode*p1 = cur;
        ListNode*p2 = cur->next;
        while(p2!=NULL&&p2->next!=NULL)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        
        return p1;
    }
    
   ListNode* MSort(ListNode*first)
    {
        if(first==NULL||first->next==NULL)
        {
            return first;
        }
        else
        {
            ListNode*mid = find_mid(first);
            ListNode*second_part = mid->next;
            mid->next = NULL;
            ListNode*left=  MSort(first);
            ListNode*right= MSort(second_part);
            return Merge(left,right);
        }
    }
    
    ListNode* Merge(ListNode*first,ListNode*second)
    {
       ListNode*temp = new ListNode(-1);
       ListNode* p = temp;
       while(first!=NULL&&second!=NULL)
       {
           if(first->val<=second->val)
           {
               p->next = first;
               first = first->next;
           }
           else
           {
               p->next = second;
               second = second->next;
           }
           p = p->next;
       }
       
       if(first!=NULL)
       {
           p->next = first;
       }
       else
       {
           p->next = second;
       }
       p = temp->next;
       temp->next = NULL;
       
       delete temp;
       return p;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head!=NULL)
        {
           return MSort(head);
        }
        return head;
    }
};