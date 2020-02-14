// Ruben Navarro
// 02/14/2020
// Two linked lists with digits stored in reverse order, each of their nodes contain a single digit. Adds two numbers and returns it as a linked list.

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// displays list
void displayList(ListNode* head) {

    if (head == nullptr) {
        std::cout << "head is NULL\n";
        return;
    }
    std::cout << "[";
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr)
            std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}
    int main() {

    // list 1 construction
    ListNode * l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = nullptr;

    // list 2 construction
    ListNode * l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = nullptr;


    // variable to hold carry over amount
    int carry = 0;
    // list to store results
    ListNode *newList = new ListNode(0);
    ListNode* temp = newList;

    // variable to hold sum results
    int sum = 0;

    // traverses through both lists and ensures that the carry is above 0
    // adds numbers contained in both lists and stores result in new list
    while (l1 != NULL || l2 != NULL || carry > 0) {

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        sum = 0;
        temp = temp->next;
    }

    // displays new list containing results
    displayList(newList->next);
    return 0;
}
