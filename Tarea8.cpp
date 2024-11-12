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

    bool find(T valor, nodo<T>*& pos) {
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

    void ADD(T valor) {
        nodo<T>* newNode = new nodo<T>(valor);
        if (!head) { 
            head = newNode;
            head->next = head;
        }
        else {
            nodo<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void DEL(T valor) {
        nodo<T>* pos = nullptr;
        if (find(valor, pos)) {
            nodo<T>* temp = head;
            while (temp->next != pos) {
                temp = temp->next;
            }
            temp->next = pos->next;
            delete pos;
        }
    }

    void PRINT() {
        if (!head) {
            cout << "Lista vacía" << endl;
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
};

int main() {
    LEC<int> lista;
    lista.ADD(1);
    lista.ADD(2);
    lista.ADD(3);
    lista.ADD(4);
    lista.ADD(5);

    cout << "Lista " << endl;
    lista.PRINT();

    lista.DEL(3);
    cout << "Lista 2" << endl;
    lista.PRINT();

    lista.ADD(6);
    cout << "Lista 3" << endl;
    lista.PRINT();
}
