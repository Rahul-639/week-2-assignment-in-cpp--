#include <iostream>
using namespace std;

// Node definition
struct Node {
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

// Class to add two polynomial linked lists
class Solution {
public:
    Node* addPolynomial(Node* head1, Node* head2) {
        Node* dummy = new Node(0, 0); // Temporary dummy node
        Node* tail = dummy;

        Node* p1 = head1;
        Node* p2 = head2;

        while (p1 && p2) {
            if (p1->pow == p2->pow) {
                int sum = p1->coeff + p2->coeff;
                if (sum != 0) {
                    tail->next = new Node(sum, p1->pow);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->pow > p2->pow) {
                tail->next = new Node(p1->coeff, p1->pow);
                tail = tail->next;
                p1 = p1->next;
            } else {
                tail->next = new Node(p2->coeff, p2->pow);
                tail = tail->next;
                p2 = p2->next;
            }
        }

        // Attach remaining terms
        while (p1) {
            tail->next = new Node(p1->coeff, p1->pow);
            tail = tail->next;
            p1 = p1->next;
        }

        while (p2) {
            tail->next = new Node(p2->coeff, p2->pow);
            tail = tail->next;
            p2 = p2->next;
        }

        return dummy->next;
    }
};

// Utility function to create a linked list from input
Node* createPolynomial(int terms) {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter " << terms << " terms (coeff power):" << endl;
    for (int i = 0; i < terms; i++) {
        int c, p;
        cin >> c >> p;
        Node* newNode = new Node(c, p);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Function to print the polynomial
void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    int n1, n2;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    Node* poly1 = createPolynomial(n1);

    cout << "Enter number of terms in second polynomial: ";
    cin >> n2;
    Node* poly2 = createPolynomial(n2);

    Solution obj;
    Node* result = obj.addPolynomial(poly1, poly2);

    cout << "Resultant Polynomial after addition: ";
    printPolynomial(result);

    return 0;
}
