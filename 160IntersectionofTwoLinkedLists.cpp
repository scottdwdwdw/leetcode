/*
*
*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
//我的代码：
//双指针法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //双指针法
        ListNode*cura=headA;ListNode*curb=headB;
        size_t countA=0,countB=0;
        while(cura!=NULL){cura=cura->next;++countA;}
        while(curb!=NULL){curb=curb->next;++countB;}
        cura=headA,curb=headB;
        int diff=countA-countB;
        if(diff>0)
        {
            while(diff--)cura=cura->next;
        }
        else if(diff<0)
        {
            while(diff++)curb=curb->next;
        }
        while(cura!=curb)
        {
            cura=cura->next;
            curb=curb->next;
        }
        return cura;
    }
};

//还有暴力法，遍历两个链表，哈希表法