#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    
    //OK
    void add(int element) {
        Node* newNode = new Node();
        newNode->data = element;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            count++;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            count++;
        }
    }

    //OK
    void add(int index, int element) {
        Node* newNode = new Node();
        newNode->data = element;
        if(head == NULL){
            if(index == 0){
                head = newNode;
                tail = newNode;
                count++;
            }
            else{
                return;
            }
        }
        else if(index == 0){
            newNode->next = head;
            head = newNode;
            count++;
        }
        else if(index == count){
            add(element);
        }
        else{
            Node* temp = head;
            if(index == 1){
                newNode->next = temp->next;
                temp->next = newNode;
                count++;
            }
            else{
                for(int i = 0; i < index - 1; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                count++;
            }
        }
    }

    //OK
    int removeAt(int index) {
        Node* temp;
        Node* prev;
        prev = temp = head;
        int result;
        if(count == 1){
            if(index == 0){
                head = NULL;
                tail = NULL;
                count--;
                return temp->data;
            }
        }
        if(index == 0){
            head = head->next;
            result = temp->data;
            free(temp);
            count--;
            return result;
        }
        if(index == count - 1){
            result = tail->data;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            free(temp->next);
            tail = temp;
            count--;
            return result;
        }
        for(int i = 0; i < index - 1; i++){
            prev = prev->next;
        }
        temp = prev->next;
        result = temp->data;
        prev->next = temp->next;
        free(temp);
        count--;
        return result;
    }

    //OK
    bool removeItem(int item) {
        for(int i = 0; i < count; i++){
            if(removeAt(i) == item){
                return true;
            }
        }
        return false;
    }

    bool empty() {
        if(count == 0){
            return true;
        }
        return false;
    }

    int size() {
        return count;
    }
    
    //OK
    int get(int index) {
        if(index < 0 || index >= count){
            throw std::out_of_range("Invalid");
        }
    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

    //OK
    void set(int index, int element) {
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        temp->data = element;
    }

    //OK
    int indexOf(int item) {
        Node* temp = head;
        for(int i = 0; i < count; i++){
            if(temp->data == item){
                return i;
            }
            if(i == count - 1){
                break;
            }
            else{
                temp = temp->next;
            }
        }
        return -1;
    }

    bool contains(int item) {
        return indexOf(item) != -1;
    }
    
    void clear() {
        Node* current = head;
        Node* next = NULL;
        while(current != NULL){
            next = current->next;
            free(current);
            current = next;
        }
        head = NULL;
        tail = NULL;
        count = 0;
    }
    
    string toString(){
        Node* temp = head;
        stringstream ss;
        ss << "[";
        for(int i = 0; i < count - 1; i++){
            ss << temp->data;
            ss << ", ";
            temp = temp->next;
        }
        if(temp != NULL){
            ss << temp->data;
            ss << "]" << endl;
        }
        return ss.str();
    }
    ~IntSLinkedList(){
        clear();
    }

public:
    class Node {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) : 
            data(data), next(NULL) {};
    };
};