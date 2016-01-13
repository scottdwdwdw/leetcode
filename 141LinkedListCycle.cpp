/*
*
*   Given a linked list, determine if it has a cycle in it.
*/

//ʹ������ָ�룬����һ��ָ���ƶ��ÿ죬��һ��ָ���ƶ������������ѭ������
//��ô����ָ����ĳһʱ�̱ض����
//����:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*first=head;
        ListNode*second=head;
        while(first!=NULL&&first->next!=NULL)
        {
            first=first->next->next;
            second=second->next;
            if(first==second)return true;
        }
        
        return false;
    }
};