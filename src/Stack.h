//
// Created by Vadim Sukach on 19.04.2018.
//

#ifndef MARKETINGSERVICES_STACK_H
#define MARKETINGSERVICES_STACK_H

#include <cassert> // для assert
#include <iostream>

#include <iomanip> // для setw


using namespace std;

template<typename T>
class Stack {
private:
    T *stackPtr;
    const int size;
    int top;
public:
    Stack(int = 10);
    Stack(const Stack<T> &);
    ~Stack();
    class findElementEx {
    };
    inline void push(const T &);
    inline T pop();
    inline void printStack();
    inline const T &getElementFromTop(int) const;
    inline int getStackSize() const;
    inline T *getPointerForStack() const;
    inline int getCurrentElement() const;
    inline T *findAccount(string);
    inline bool hasAccount(string);
};

template<typename T>
Stack<T>::Stack(int maxSize) :
        size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &otherStack) :
        size(otherStack.getStackSize()) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под новый стек
    top = otherStack.getCurrentElement();

    for (int i = 0; i < top; i++)
        stackPtr[i] = otherStack.getPointerForStack()[i];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stackPtr; // удаляем стек
}

template<typename T>
inline void Stack<T>::push(const T &value) {
    // проверяем размер стека
    assert(top < size); // номер текущего элемента должен быть меньше размера стека

    stackPtr[top++] = value; // помещаем элемент в стек
}

template<typename T>
inline T Stack<T>::pop() {
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0

    stackPtr[--top]; // удаляем элемент из стека
}


template<class T>
inline const T &Stack<T>::getElementFromTop(int nom) const {
    //
    assert(nom <= top);

    return stackPtr[top - nom]; // вернуть n-й элемент стека
}

template<typename T>
inline void Stack<T>::printStack() {
    for (int ix = top - 1; ix >= 0; ix--)
        cout << stackPtr[ix] << endl;
}

template<typename T>
inline T *Stack<T>::findAccount(string login) {
    for (int ix = top - 1; ix >= 0; ix--) {
        if (stackPtr[ix].getLogin() == login) {
            return &stackPtr[ix];
        }
    }
}

template<typename T>
inline bool Stack<T>::hasAccount(string login) {
    for (int ix = top - 1; ix >= 0; ix--) {
        if (stackPtr[ix].getLogin() == login) {
            return true;
        }
    }
    return false;

}

// вернуть размер стека
template<typename T>
inline int Stack<T>::getStackSize() const {
    return size;
}

template<typename T>
inline T *Stack<T>::getPointerForStack() const {
    return stackPtr;
}

template<typename T>
inline int Stack<T>::getCurrentElement() const {
    return top;
}

#endif //MARKETINGSERVICES_STACK_H
