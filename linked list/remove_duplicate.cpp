#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* newnode(int k)
{
    ListNode* tmp = (struct ListNode*) malloc(sizeof(ListNode));
    tmp->val = k;
    tmp->next = NULL;

    return tmp;
}

ListNode* deleteDuplicates(ListNode* A) {
    
    ListNode* h1 = A;
    ListNode* h2 = A;
    
    if (h1 == NULL)
        return NULL;
        
    while (h2->next != NULL)
    {
        
        if (h1->val == h2->next->val)
        {
            h2 = h2->next;
            continue;
        }
        
        cout << "Rubee = " << h2->val << endl;
        h1->next = h2->next;
        h2 = h1;
    }
    
    return A;
}

void print_list(ListNode* A)
{
    ListNode* curr = A;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}
int main()
{
    ListNode* head = newnode(1);
    head->next = newnode(1);
    head->next->next = newnode(2);

    print_list(head);
    head = deleteDuplicates(head);
    print_list(head);
    return 0;
}