#ifndef _STACK_
#define _STACK_
#include <iostream>
#include <string>
using namespace std;

// шаблонный стек, реализованный на основе списка
// функции look_top и pop защищены. в случае неверного вызова (при пустом стеке) бросают исключение типа string
template <typename T>
class Stack {
private:
    struct Cell {
        T data;
        Cell* prev;
        Cell(const T& data, Cell* prev) : data(data), prev(prev) {}
    };
    int size;
    Cell* top;

public:
    Stack() : size(0), top(0) {}
    ~Stack() { clear(); }

    const T& look_top() const {
        if (get_size() == 0) {
            throw exception("Проверьте корректность введённого выражения и перезапустите этап вычислений!");
        }
        else
            return top->data;
    }

    void pop() {
        if (get_size() == 0) {
            throw exception("Извлечение невозможно, стек пуст!");
        }
        else {
            T data = top->data;
            Cell* first = top;
            top = first->prev;
            delete first;
            size--;
        }
    }

    void push(const T& data) {
        size++;
        top = new Cell(data, top);
    }

    int get_size() const {
        return size;
    }

    void clear() {
        while (size > 0)
            pop();
    }
};

#endif //_STACK_