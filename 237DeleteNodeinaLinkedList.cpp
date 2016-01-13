/*
*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

//由于题目并没有给出头结点，所以只能移动元素
//我的代码
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next)
        {
            node->val=node->next->val;
            node=node->next;
        }
         node->val=node->next->val;
         node->next=NULL;
    }
};
