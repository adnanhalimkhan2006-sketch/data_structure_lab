#include <iostream>
using namespace std;

struct Node
{
    string productID;
    Node* next;
};

void addProduct(Node*& head, string id)
{
    Node* newNode = new Node;
    newNode->productID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void displayCart(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->productID;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

void removeProduct(Node*& head, string id)
{
    if (head == NULL)
    {
        cout << "Shopping Cart is empty." << endl;
        return;
    }

    if (head->productID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->productID == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return;
        }

        temp = temp->next;
    }

    cout << "Product Not Found." << endl;
}

int main()
{
    Node* head = NULL;

    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    cout << "Shopping Cart:" << endl;
    displayCart(head);

    string id;
    cout << "Remove Product: ";
    cin >> id;

    removeProduct(head, id);

    cout << "Updated Cart:" << endl;
    displayCart(head);

    return 0;
}