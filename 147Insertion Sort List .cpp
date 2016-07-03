/*
147. Insertion Sort List  
Total Accepted: 70192 Total Submissions: 238592 Difficulty: Medium
Sort a linked list using insertion sort.
*/
链表的插入排序


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode*sort(ListNode*head)
    { 
        ListNode*temp = new ListNode(-1);  //新建一个临时链表，用于排序存储，避免单链表交换的麻烦
        ListNode*p = temp;
        ListNode*cur = head;
       
        while(cur->next!=NULL)
        {
            if(cur->val>cur->next->val)
            {
                ListNode*curTemp = head;
                while(curTemp!=cur->next)
                {
                  if(curTemp->val<=cur->next->val)
                  {
                      p->next = curTemp;
                      curTemp = curTemp->next;
                  }
                  else
                  {
                      p->next = cur->next;
                      p = p->next;
                     break;  //找到了插入位置，交换了元素,退出循环，已经有序了
                  }
                  p = p->next;
                }
                cur->next = cur->next->next;  //修改cur指向的数据
                p->next = curTemp;
               
                
                head = temp->next;   //恢复temp和p
                temp->next = NULL;
                p = temp;
            }
            else
            {
               cur = cur->next;
            }
            
        }
        
        temp->next = NULL;
        delete temp;
        return head;
     
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        
        return sort(head);
    }
};


/*比较清晰的解法*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        if(head && head->next)
        {
            ListNode* pre = head;
            ListNode* p = head->next;
            while(p)
            {
                if(p->val < pre->val)               //inserting only if necessary
                {
                    ListNode* pp = &dummy;          //locate where to insert
                    while((pp->next->val < p->val)) //pp won't exceed pre, so no valid check
                        pp = pp->next;

                    //inserting
                    pre->next = p->next;
                    p->next = pp->next;
                    pp->next = p;
                }
                else
                    pre = p;                        //no inserting, keep moving

                p = pre->next;
            }
        }
        return dummy.next;
    }
};