#include <iostream>
using namespace std;

template <typename T>
class List{
    private:
        struct Node{
            T dato;
            Node* next;
            Node(T d){
                dato = d;
                next = nullptr;
            }
        };
        Node* head = nullptr;;
    public:
        List();
        ~List();
        void push_front(T dato);
        T front();
        int size();
        bool empty();
        void print();
};

template <typename T>
List<T>::List(){
    head = nullptr;
}

template <typename T>
List<T>::~List(){
    Node* temp = head;
    while(temp!=nullptr){
        Node* nextNode = temp -> next;
        delete temp;
        temp=nextNode;
    }
}

template <typename T>
void List<T>::push_front(T dato){
    Node* newNode = new Node(dato);
    newNode -> next = head;
    head = newNode;
}

template <typename T>
T List<T>::front(){
    if(head==nullptr) throw runtime_error("List is empty");
    return head->dato;
}

template <typename T>
int List<T>::size(){
    int cont=0;
    Node* temp = head;
    while(temp!=nullptr){
        cont++;
        temp=temp->next;
    }
    return cont;
}

template <typename T>
bool List<T>::empty(){
    if(head==nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void List<T>::print(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->dato<<"->";
        temp=temp->next;
    }
    cout<<endl;
}