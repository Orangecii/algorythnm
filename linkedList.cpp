#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};

typedef struct Node* node;


// tao node moi voi kieu du lieu la so nguyen x
node createNode(int x) {
    node tmp = new Node();
    tmp ->data = x;
    tmp ->next = NULL;
    return tmp;
}

// kiem tra rong
bool empty(node a){
    return a == NULL;
}

// dem so phan tu cua linked-list
int Size(node a){
    int cnt = 0;
    while( a != NULL ){
        ++cnt;
        a = a->next;
    }
    return cnt;
}

// them phan tu vao dau danh sach lien ket
void insertFirst(node &a, int x){
    node tmp = createNode(x);
    if (a == NULL){
        a = tmp;
    }
    else {
        tmp -> next = a;
        a = tmp;
    }   
}

// them 1 phan tu vao cuoi danh sach lien ket
void insertLast(node &a, int x){
    node tmp = createNode(x);
    if (a == NULL){
        a = tmp;
    }
    else {
        node p = a;
        // dung node khac de duyet vi neu dung node dau tien duyet thi no' lam mat cac node trc no' khi chay
        while (p -> next != NULL) {
            p = p->next;
        }
        p -> next = tmp;
    }
}

// them phan tu vao giua
void insertMiddle(node &a, int x, int pos){
    node tmp = createNode(x);
    int n = Size(a);
    if ( pos < 1 || pos > n+1 ) {
        cout << "invalid insert index!\n";
    }
    if ( n == 1) {
        insertFirst(a, x);
        return;
    }
    if ( n == pos + 1 ){
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 0; i < pos - 1; i++ ){
        p = p->next;
    }
    // neu p -> next = tmp len trc thi se mat dau cac phan tu dang sau
    tmp->next = p->next;
    p->next = tmp;
}

// xoa phan tu dau 
void deleteFirst(node &a){
    if ( a == NULL) return;
    a = a->next;
}

//xoa phan tu o cuoi
void deleteLast(node &a){
    if ( a == NULL) return;
    node p = a;
    while( p->next->next != NULL ){
        p = p->next;
    }
    delete p->next; // xoa phan tu cuoi
    p->next = NULL; // cap nhat con tro next
}

// xoa phan tu o giua
void deleteMiddle(node &a, int pos){
    int n = Size(a);
    if ( pos < 1 || pos > n) {
        cout << "invalid delete index!\n";
        return;
    }
    if ( n == 1) {
        deleteFirst(a);
        return;
    }
    if ( n == pos ){
        deleteLast(a);
        return;
    }
    cout<< pos;

    node p = a;
    for(int i = 0; i < pos - 1; i++ ){
        p = p->next;
    }
    node temp = p->next;
    p->next = p->next->next;
    delete temp; // giai phong bo nho cho node temp
}

// duyet linked-list
void browseLinkedList(node a){
    cout << "---------------------------\n";
    while (a!=NULL){
        cout<<a->data<< " ";
        a = a->next;
    }
    cout << "---------------------------\n";
}

int main(){
    cout << sizeof(Node)<< endl;
    // khoi tao node dau tien trong linked-list
    node head = NULL;
    cout << empty(head) << endl;
    while (1) {
        cout << "-------menu-------\n";
        cout << "1.insert first\n";
        cout << "2.insert last\n";
        cout << "3.insert middle\n";
        cout << "4.delete first\n";
        cout << "5.delete last\n";
        cout << "6.delete middle\n";
        cout << "7.browse the list\n";
        cout << "-------------------\n";
        int option; cin>>option;
        if(option == 1){
            int x; cout<< "insert value: "; cin >> x;
            insertFirst(head,x);
        }
        if(option == 2){
            int x; cout<< "insert value: "; cin >> x;
            insertLast(head,x);
        }
        if(option == 3){
            int x; cout<< "insert value: "; cin >> x;
            int pos; cout<< "insert index value: "; cin >> pos;
            insertMiddle(head,x,pos);
        }
        if(option == 4){
            deleteFirst(head);
        }
        if(option == 5){
            deleteLast(head);
        }
        if(option == 6){
            int pos; cout<< "delete index value: "; cin >> pos;
            deleteMiddle(head,pos);
        }
        if(option == 7){
            browseLinkedList(head);
        }
    }
    return 0;
}