#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void deleteNode(Node **head, int key)
{
    Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 2);
    cout << "Created Linked list is: ";
    printList(head);
    deleteNode(&head, 1);
    cout << "\nLinked List after Deletion of 1: ";
    printList(head);
    return 0;
}
