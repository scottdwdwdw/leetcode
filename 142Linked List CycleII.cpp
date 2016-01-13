/*
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/
//首先是要判断有没有环，然后再找出环的位置
//(推到过程)[http://fisherlei.blogspot.jp/2013/11/leetcode-linked-list-cycle-ii-solution.html]

//代码:
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

//其他思路
//给出题目：检测单链表中是否存在环。

/*可以遍历这个链表，遍历过的节点标记为Done，如果当目前准备遍历的节点为Done的时候，那么存在环，否则准备检测的节点为Null时，遍历完成，不存在环。

附加条件：每个节点是只读的，不可以做标记呢？

可以另外开辟一个数组，每次遍历完一个节点后，保存这个节点的唯一地址到数组，如果要遍历的节点已在数组中，那么存在环，要是取到Null还没有重复，那么就是不存在了，当然这个数组可以是Hash表。

附加条件：只可以另外开辟常数空间呢？(时间复杂度为o（N^2）);

可以使用快慢指针，然后分别每次A指针向后移动1步，B指针向后移动2步，如果A和B指向了同一个节点那么存在环，如果有一个指向了Null,那么不存在环。

*/