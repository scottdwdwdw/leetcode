/*
*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*
*/

//�ҵĴ���
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*pre1=new ListNode(-1);
        ListNode*before_head=pre1;
     //   pre1->next=l1;      ��Щ���Բ���Ҫ
     //   ListNode*cur1=l1;
     //   ListNode*cur2=l2;
        while(cur1!=NULL&&cur2!=NULL)  //����l1��l2���Ͳ��������ӱ����ˡ�
        {
           if((cur1->val)>(cur2->val)) //��cur2��Ԫ�ز��뵽cur1��
           {
              // pre1->next=cur2;
              // ListNode*tmp=cur2;
              // cur2=cur2->next;
              // tmp->next=cur1;
              // pre1=pre1->next;
			  
               
           }
           else
           {
               cur1=cur1->next;
               pre1=pre1->next;
           } 
        }
        if(cur1==NULL&&cur2!=NULL)
        {
            pre1->next=cur2;
            return before_head->next;
        }
        else
        {
            return before_head->next;
        }
    }
};

//�ҵĴ���д��̫���ˣ���������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) 
        cur->next = l1;
    else
        cur->next = l2;
    ListNode *tmp = dummy->next;
    delete dummy;
    return tmp;
}

//����һ��˼·�������ӣ�Ȼ������
