//1209 孙书情   
//leetcode 反转链表

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
    ListNode* reverseList(ListNode* head) {
        //       1 --->  2--------------> 3------->4------->5
        // first<-second tmp(next second)
        // 如上图所示，改变节点的next的指向即可
        ListNode *first = NULL; // 初始化为NULL
        ListNode *second = head; // 初始化为第一个节点
        ListNode *tmp;
        while(second){
            // 翻转指针并更新指针
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        return first;
  }
};