#include "list.h"
using namespace std;

void show_menu() {
    std::cout << "> List of operations:" << std::endl;
    cout << "1) Build the list - build(list)" << endl;
    cout << "2) Insert to the beginning - push_front(list)" << endl;
    cout << "3) Insert in the tail - push_back(list)" << endl;  // +
    cout << "4) Insert up to the specified element - push_before(beforeId)" << endl;
    cout << "5) Insert after the specified element - push_after(afterId)" << endl;
    cout << "6) Delete the first item - pop_front(list)" << endl;
    cout << "7) Delete the last item - pop_back(list)" << endl;
    cout << "8) Delete the element - erase(id)" << endl;
    cout << "9) Print the list - print(list)" << endl;
    cout << "10) Individual - filter(list)" << endl;
    cout << "11) Exit" << endl;
}

int main() {
    list l;
    int operation_code;
    bool is_exit = false;
    do {
        show_menu();
        cin >> operation_code;

        int newId;
        int beforeId, afterId;
        int deletedId;
        switch (operation_code) {
            case 1:
                cout << "> Enter the size of the list that will be filled random numbers: ";
                size_t size;
                cin >> size;
                build(&l, size);
                break;
            case 2:
                cout << "> Input new id: ";
                cin >> newId;
                push_front(&l, newId);
                break;
            case 3:
                cout << "> Input new id: ";
                cin >> newId;
                push_back(&l, newId);
                break;
            case 4:
                print(&l);
                cout << endl;
                cout << "> Input before id: ";
                cin >> beforeId;
                cout << "> Input new id: ";
                cin >> newId;
                push_before(&l, beforeId, newId);
                break;
            case 5:
                print(&l);
                cout << endl;
                cout << "> Input after id: ";
                cin >> afterId;
                cout << "> Input new id: ";
                cin >> newId;
                push_after(&l, afterId, newId);
                break;
            case 6:
                cout << "> You have deleted: " << pop_front(&l) << " from the list's beginning" << endl;
                break;
            case 7:
                cout << "> You have deleted: " << pop_back(&l) << " from the list's tail" << endl;
                break;
            case 8:
                print(&l);
                cout << endl << "> Input id to delete: ";
                cin >> deletedId;
                erase(&l, deletedId);
                break;
            case 9:
                // Nothing
                break;
            case 10:
                filter(&l);
                break;
            case 11:
                is_exit = true;
                cout << "> Exiting..." << endl;
                break;
        }

        if (!is_exit) {
            cout << "> Current status of the list: ";
            print(&l);
            cout << endl;
        }
    } while (!is_exit);

    return 0;
}
