#include <iostream>
using namespace std;

int main() {
    int a[100], n, choice, pos, value, key, i, found;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];

    do {
        cout << "\n\n1. Insertion";
        cout << "\n2. Deletion";
        cout << "\n3. Traversal";
        cout << "\n4. Search";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;

                for(i = n; i >= pos; i--)
                    a[i] = a[i - 1];

                a[pos - 1] = value;
                n++;

                cout << "Element inserted";
                break;

            case 2:
                cout << "Enter position: ";
                cin >> pos;

                for(i = pos - 1; i < n - 1; i++)
                    a[i] = a[i + 1];

                n--;

                cout << "Element deleted";
                break;

            case 3:
                cout << "Array elements: ";
                for(i = 0; i < n; i++)
                    cout << a[i] << " ";
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> key;

                found = 0;

                for(i = 0; i < n; i++) {
                    if(a[i] == key) {
                        cout << "Element found at position " << i + 1;
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    cout << "Element not found";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}
