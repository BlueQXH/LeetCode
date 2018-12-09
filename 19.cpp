/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode *head, int n)
    {
        if (head != nullptr && n > 0)
        {
            ListNode *fast = head, *slow = head;
            int i = 0;
            while (fast != nullptr && i < n)
            {
                fast = fast->next;
                ++i;
            }
            if (i == n)
            {
                ListNode *del = nullptr;
                if (fast == nullptr)
                {
                    del = head;
                    head = head->next;
                }
                else
                {
                    while (fast->next != nullptr)
                    {
                        fast = fast->next;
                        slow = slow->next;
                    }
                    del = slow->next;
                    slow->next = del->next;
                }
                delete del;
            }
        }
        return head;
    }
};
