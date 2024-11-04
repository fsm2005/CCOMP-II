using namespace std;
#include <iostream>

template <class T>
struct nodo {
    T valor;
    nodo* next;
    nodo(T v, nodo<T>* n = nullptr) {
        valor = v;
        next = n;
    }
};

template <class T>
void ArraytoLe(int* Being, int* End, nodo<T>*& head) {
    head = nullptr;
    for (int* p = End; p >= Being; p--) {
        head = new nodo<T>(*p, head);
    }
}

template <class T>
void Print(nodo<T>* head) {
    cout << "HEAD->";
    for (nodo<T>* p = head; p; p = p->next)
        cout << p->valor << "-->";
    cout << "null" << endl;
}

template <class T>
void merge(nodo<T>* A, nodo<T>* B) {
    nodo<T>* mergedHead = nullptr;  
    nodo<T>* mergedTail = nullptr; 

    if (A->valor < B->valor) {
        mergedHead = A;
        A = A->next;
    }
    else {
        mergedHead = B;
        B = B->next;
    }
    mergedTail = mergedHead;

    while (A != nullptr && B != nullptr) {
        if (A->valor < B->valor) {
            mergedTail->next = A;
            A = A->next;
        }
        else {
            mergedTail->next = B;
            B = B->next;
        }
        mergedTail = mergedTail->next;
    }

    if (A != nullptr) {
        mergedTail->next = A;
    }
    else {
        mergedTail->next = B;
    }

    A = mergedHead;

}

int main() {
    int A[] = { 1,2,3,5,6 };
    int B[] = { 12,13,20};
    nodo<int>* LEA;
    nodo<int>* LEB;
    ArraytoLe(A, A + (sizeof(A) / sizeof(A[0]) - 1), LEA);
    ArraytoLe(B, B + (sizeof(B) / sizeof(B[0]) - 1), LEB);
    Print(LEA);
    Print(LEB);
    merge(LEA, LEB);
    Print(LEA);
}
