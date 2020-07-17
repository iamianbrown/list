#include <climits>
/*
 * Create a Linked List
 * Ian Brown
 * July 2 2020
 */
#include <iostream>

using namespace std;

class list_elem{
public:
    list_elem(int n = 0, list_elem* ptr = nullptr):d(n), next(ptr){}
    int d;
    list_elem* next;
};
class list{
public:
    list():head(nullptr), cursor(nullptr){}
    //list(const list& l);
    void append(int n);
    void prepend(int n);
    int getElement(){
        return cursor->d;
    }
    list_elem* getNext(){
        return cursor->next;
    }
    void advance(){
        cursor = cursor -> next;
    }
    // moves cursor to beginning of list
    void resetCursor(){
        cursor = head;
    }
    void print();

private:
    list_elem* head;
    list_elem* cursor{};
};

void list::prepend(int n) {
    if (head == nullptr){
        cursor = head = new list_elem(n, head);
    } else{
        head = new list_elem(n,head);
    }
}
void list::append(int n){
    list_elem* crnt;
    list_elem* node = new list_elem;
    node->d = n;
    node->next = nullptr;
    if(head == nullptr){
        head = node;
    }
    else{
        crnt = head;
        while(crnt->next != nullptr){
            crnt = crnt->next;
        }
        crnt->next = node;
    }
}
void list::print() {
    list_elem* h = head;
    while(h != nullptr){
        cout << h->d;
        h = h->next;
    }
    cout << "###" << endl;
}
ostream& operator<< (ostream& out, list& l){
    l.resetCursor();
    while(l.getNext() != nullptr) {
        out << l.getElement();
        l.advance();
    }
    out << l.getElement() << "###";
    return out;
}

list::list(const list& l):head(nullptr)
{
    list_elem* node;
    cursor = head = node = l.head;
    while(node != nullptr){
        append(node->d);
        node = node->next;
    }

}
int main(){
    list l;
    for(int i = 0; i < 10; ++i){
        l.append(i);
    }
    //list li = l;
    l.print();
    //cout << l << endl;
    //cout << li;
    return 0;
}