#include "IntSLinkedList.h"

int main(){
    // Test: Adding with add(index:size(), item)
    // IntSLinkedList list;
    // int size = 10;
    // for (int index = 0; index < size; index++) {
    //     list.add(list.size(), index);
    // }
    // cout << list.toString();

    IntSLinkedList list;
    int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
    int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
    for (int idx = 0; idx < 8; idx++){
        list.add(index[idx], values[idx]);
    }
    cout << list.toString();
    cout << list.removeAt(2) << endl;
    cout << list.toString();
    cout << list.get(3) << endl;
    cout << list.toString();
    list.set(2, 100);
    cout << list.toString();
    cout << list.indexOf(3) << endl;
    cout << list.toString();


    // IntSLinkedList list;
    // int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    // int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    // for (int idx = 0; idx < 8; idx++){
    //     list.add(index[idx], values[idx]);
    // }
    // cout << list.get(2) << endl;

    // try {
    //     cout << list.get(11);
    // }
    // catch (std::out_of_range e) {
    //     cout << "Out of range";
    // }
}