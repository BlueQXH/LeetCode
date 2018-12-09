/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1
{
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        ListNode *head = nullptr;
        if (l1->val < l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode *head = nullptr;
        for (ListNode *pNode : lists)
        {
            head = mergeTwoLists(head, pNode);
        }
        return head;
    }
};

class Solution2
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {       
        ListNode *head = nullptr;
        if (!lists.empty())
        {
            priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
            for (ListNode *pNode  : lists)
            {
                if (pNode != nullptr)
                {
                    pq.push(pNode);
                }
            }
            if (!pq.empty())
            {
                head = pq.top();
                pq.pop();
                ListNode *tail = head;
                if (tail->next != nullptr)
                {
                    pq.push(tail->next);
                }
                while (!pq.empty())
                {
                    tail->next = pq.top();
                    tail = tail->next;
                    pq.pop();
                    if (tail->next != nullptr)
                    {
                        pq.push(tail->next);
                    }
                }
            }
        }
        return head;
    }
private:
    struct Comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
};
