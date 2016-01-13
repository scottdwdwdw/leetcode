/*
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/
//������Ҫ�ж���û�л���Ȼ�����ҳ�����λ��
//(�Ƶ�����)[http://fisherlei.blogspot.jp/2013/11/leetcode-linked-list-cycle-ii-solution.html]

//����:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)break;
        }
        if(fast==NULL||fast->next==NULL)return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

//����˼·
//������Ŀ����ⵥ�������Ƿ���ڻ���

/*���Ա�����������������Ľڵ���ΪDone�������Ŀǰ׼�������Ľڵ�ΪDone��ʱ����ô���ڻ�������׼�����Ľڵ�ΪNullʱ��������ɣ������ڻ���

����������ÿ���ڵ���ֻ���ģ�������������أ�

�������⿪��һ�����飬ÿ�α�����һ���ڵ�󣬱�������ڵ��Ψһ��ַ�����飬���Ҫ�����Ľڵ����������У���ô���ڻ���Ҫ��ȡ��Null��û���ظ�����ô���ǲ������ˣ���Ȼ������������Hash��

����������ֻ�������⿪�ٳ����ռ��أ�(ʱ�临�Ӷ�Ϊo��N^2��);

����ʹ�ÿ���ָ�룬Ȼ��ֱ�ÿ��Aָ������ƶ�1����Bָ������ƶ�2�������A��Bָ����ͬһ���ڵ���ô���ڻ��������һ��ָ����Null,��ô�����ڻ���

*/