/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

//我的代码：
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto len=size(head);
        if(len==0)return head;
        if(n>=len)n=len;
        if(n==len)return head->next;
        auto elem_num=len-n;
        ListNode*cur=head;
        while(--elem_num)
        {
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return head;
    }
private:
    size_t size(ListNode*head) const
    {
        size_t count=0;
        ListNode *tmp=head;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            ++count;
        }
        return count;
    }
};

//使用递归
class Solution {
public:
    int remove(ListNode* head, const int& n)
    {
        if (!head)
            return 0;

        int value = remove(head->next, n);   //每次调用，返回当前节点序号，然后判断是不是我们需要的。
        if (value == n)
        {
            head->next = head->next->next;
        }

        return value + 1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (remove(head, n)==n)
            return head->next;

        return head;
    }
};

//使用两个指针，利用的是他们增长速度的不同
//
/*-------------------------------------
  dummy->1->2->3->4->5;
  ^
first(second) 
---------------------------------------/

//首先，让frist_node向前移动n个距离，比如2
/*-------------------------------------
  dummy->1->2->3->4->5;
    ^       ^
second   first
---------------------------------------*/
//此时，second与first的差距也是2,接下来就是移动两个指针到链表尾
/*-------------------------------------
  dummy->1->2->3->4->5->NULL;
               ^     ^
           second   first
---------------------------------------*/
//second指向的位置即为要修改的位置

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*first=new ListNode(-1);
        ListNode*second=new ListNode(-1);
        ListNode *release_first=first;
        ListNode *release_second=second;
        second->next=head;
        first->next=head;
        if(!head)return head;
        if(!head->next)return NULL;
        for(int i=0;i<n&&(first->next);++i)
        {
            first=first->next;
        }
        while(first->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        
        delete release_first;
      //  delete release_second;
        return release_second->next;
    }

};

//这里有一个问题，如何解决类存泄露的问题？