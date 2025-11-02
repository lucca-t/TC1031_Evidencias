/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Vacio o de 1
        if (!head || !head->next) {
            return head;
        }
        // Merge Sort
        // Encontrar la mitad, 
        //cuando el rapido este al final el lento estara en la mitad
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Checar si estamos al final
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Configurar mid y desconectar slow
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Dividar a la mitad cada vez
        // O(log n)
        return merge(left, right);
        // Complejidad final
        // Tiempo: O(n log n)
        // Espacio: O(1)
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        // Recorrer ambas mitades 
        // O(n)

        // Usar tail para combinar ambas mitades
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }
        return dummy.next;
    }
};