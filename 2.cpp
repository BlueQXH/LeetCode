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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(-1);
        ListNode *l3 = result;
        int carry = 0;
        while (true) {
            int sum = carry;
            if (l1 == nullptr && l2 == nullptr)
                break;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode *p = new ListNode(sum % 10);
            l3->next = p;
            l3 = p;
        }
        if (carry > 0) {
            ListNode *p = new ListNode(carry);
            l3->next = p;
        }
        l3 = nullptr;
        ListNode *tmp = result;
        result = result->next;
        tmp->next = nullptr;
        delete tmp;
        return result;
    }
};
