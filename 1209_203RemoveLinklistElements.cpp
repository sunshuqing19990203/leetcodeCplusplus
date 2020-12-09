// 1209 孙书情
// 203 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        
        //删除头结点
        while(head != NULL && head->val == val){
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            
        }
        // 删除非头结点
        ListNode *curr = head;
        while(curr && curr->next){
            if(curr->next->val != val){
                curr = curr->next;
            }
            else{
                ListNode *tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }
        }
        return head;
    }
};