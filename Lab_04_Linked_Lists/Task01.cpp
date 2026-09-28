#include<iostream>
using namespace std;

struct Node
{
    int rollNumber;
    Node* next;
};

void addStudent(Node*& head, int roll)
{
    Node* newNode = new Node;
    newNode->rollNumber = roll;
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

void displayStudents(Node* head)
{
    Node* temp = head;

    cout << "Registered Students: ";

    while (temp != NULL)
    {
        cout << temp->rollNumber;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

void searchStudent(Node* head, int roll)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main()
{
    Node* head = NULL;

    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    displayStudents(head);

    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    searchStudent(head, roll);

    return 0;
}