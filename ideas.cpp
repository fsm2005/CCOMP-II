#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo* next;
    nodo(T v, nodo<T>* n = nullptr) : valor(v), next(n) {}
};

template <class T>
class LEC {
    nodo<T>* head;

public:
    LEC() : head(nullptr) {}

    void ADD(T valor) {
        nodo<T>* newNode = new nodo<T>(valor);
        if (!head) { 
            head = newNode;
            head->next = head;
        } else {
            nodo<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

void DEL(T valor) {
    nodo<T>* node = nullptr;
    nodo<T>* prev = nullptr;
    if (!find(valor, node, prev)) return; 
    if (node == head) {
        if (head->next == head) {  
            delete head;
            head = nullptr;
        } else {
            nodo<T>* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            delete node;
        }
    } else {
        prev->next = node->next;
        delete node;
    }
}

void PRINT() {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }
    nodo<T>* temp = head;
    cout << "HEAD -> "; 
    do {
        cout << temp->valor << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;  
}

    bool find(T valor, nodo<T>* &pos) {
        if (!head) return false;
        nodo<T>* temp = head;
        do {
            if (temp->valor == valor) {
                pos = temp;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        pos = nullptr;
        return false;
    }
};
int main() {
    LEC<int> lista;
    lista.ADD(1);
    lista.ADD(2);
    lista.ADD(3);
    lista.ADD(4);
    lista.ADD(5);

    cout << "Lista1:" << endl;
    lista.PRINT();

    lista.DEL(3);
    cout << "Lista2:" << endl;
    lista.PRINT();


}
