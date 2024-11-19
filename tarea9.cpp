
template<class T>
struct ASC {
    bool operator()(T a, T b) {
        return a > b;
    }
};

template<class T>
struct DESC {
    bool operator()(T a, T b) {
        return a < b;
    }
};
#include <iostream>
template<class T, class O>
class Pivot {
public:
    
    operator()() {

    }
};

int main()
{
    int A[] = {1,13,3,5,8,15,28,30};

    Pivot<ASC>inst(15)
}

