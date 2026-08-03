#include<iostream>
using namespace std;

// ================= NODE CLASS =================
class Node {
public:
    string name;
    int quantity;
    int expMonth;
    int expYear;

    Node* next;
    Node* prev;

    Node(string n, int q, int m, int y) {
        name = n;
        quantity = q;
        expMonth = m;
        expYear = y;

        next = NULL;
        prev = NULL;
    }
};

// =============== DOUBLY LINKED LIST CLASS ===============
class Pharmacy {
public:
    Node* head;

    Pharmacy() {
        head = NULL;
    }

    // ================= ADD MEDICINE =================
    void addMedicine(string n, int q, int m, int y) {

        Node* newNode = new Node(n, q, m, y);

        // if list empty
        if(head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        cout << "\nMedicine Added Successfully!\n";
    }

    // ================= DISPLAY =================
    void displayMedicines() {

        if(head == NULL) {
            cout << "\nNo Medicines Available!\n";
            return;
        }

        Node* temp = head;

        cout << "\n===== MEDICINE RECORD =====\n";

        while(temp != NULL) {

            cout << "Name: " << temp->name << endl;
            cout << "Quantity: " << temp->quantity << endl;
            cout << "Expiry: "
                 << temp->expMonth << "/"
                 << temp->expYear << endl;

            // out of stock check
            if(temp->quantity == 0) {
                cout << "Status: OUT OF STOCK\n";
            }

            cout << "--------------------------\n";

            temp = temp->next;
        }
    }

    // ================= SEARCH =================
    void searchMedicine(string key) {

        Node* temp = head;

        while(temp != NULL) {

            if(temp->name == key) {

                cout << "\nMedicine Found!\n";

                cout << "Name: " << temp->name << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Expiry: "
                     << temp->expMonth << "/"
                     << temp->expYear << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nMedicine Not Found!\n";
    }

    // ================= CHECK EXPIRED =================
    void checkExpiredMedicines(int currentMonth, int currentYear) {

        Node* temp = head;

        int found = 0;

        cout << "\n===== EXPIRED MEDICINES =====\n";

        while(temp != NULL) {

            // expiry logic
            if(temp->expYear < currentYear ||
              (temp->expYear == currentYear &&
               temp->expMonth < currentMonth)) {

                cout << temp->name << " is EXPIRED!\n";
                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0) {
            cout << "No Expired Medicines Found!\n";
        }
    }

    // ================= DELETE MEDICINE =================
    void deleteMedicine(string key) {

        if(head == NULL) {
            cout << "\nList is Empty!\n";
            return;
        }

        Node* temp = head;

        // find node
        while(temp != NULL && temp->name != key) {
            temp = temp->next;
        }

        // not found
        if(temp == NULL) {
            cout << "\nMedicine Not Found!\n";
            return;
        }

        // deleting first node
        if(temp == head) {

            head = head->next;

            if(head != NULL) {
                head->prev = NULL;
            }
        }
        else {

            temp->prev->next = temp->next;

            if(temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
        }

        delete temp;

        cout << "\nMedicine Deleted Successfully!\n";
    }

    // ================= UPDATE STOCK =================
    void updateStock(string key, int newQuantity) {

        Node* temp = head;

        while(temp != NULL) {

            if(temp->name == key) {

                temp->quantity = newQuantity;

                cout << "\nStock Updated Successfully!\n";

                return;
            }

            temp = temp->next;
        }

        cout << "\nMedicine Not Found!\n";
    }
};

// ================= MAIN FUNCTION =================
int main() {

    Pharmacy p;

    int choice;

    string name;
    int quantity;
    int month;
    int year;

    do {

        cout << "\n========== PHARMACY SYSTEM ==========\n";

        cout << "1. Add Medicine\n";
        cout << "2. Display Medicines\n";
        cout << "3. Search Medicine\n";
        cout << "4. Check Expired Medicines\n";
        cout << "5. Delete Medicine\n";
        cout << "6. Update Stock\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "\nEnter Medicine Name: ";
            cin >> name;

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Expiry Month: ";
            cin >> month;

            cout << "Enter Expiry Year: ";
            cin >> year;

            p.addMedicine(name, quantity, month, year);

            break;

        case 2:

            p.displayMedicines();

            break;

        case 3:

            cout << "\nEnter Medicine Name to Search: ";
            cin >> name;

            p.searchMedicine(name);

            break;

        case 4:

            p.checkExpiredMedicines(7, 2026);

            break;

        case 5:

            cout << "\nEnter Medicine Name to Delete: ";
            cin >> name;

            p.deleteMedicine(name);

            break;

        case 6:

            cout << "\nEnter Medicine Name: ";
            cin >> name;

            cout << "Enter New Quantity: ";
            cin >> quantity;

            p.updateStock(name, quantity);

            break;

        case 7:

            cout << "\nProgram Ended!\n";

            break;

        default:

            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
