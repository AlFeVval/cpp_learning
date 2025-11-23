#include <cstdint>
#include <iostream>
#include <stdexcept>

class Stack{
  private:
    static const size_t MAX_SIZE = 32;
    uint64_t arr[MAX_SIZE];
    int64_t top;
  public:
    Stack(): top(-1){}

    void push(uint64_t value){
      if(isFull()) throw std::overflow_error("Stack full");
      arr[++top] = value;
    }

    uint64_t pop(){
      if (isEmpty()) throw std::underflow_error("Stack empty");
      return arr[--top];
    }

    uint64_t peek(){
      if (isEmpty()) throw std::underflow_error("Stack empty");
      return arr[top];
    }

    bool isEmpty() const { return top == -1; };
    bool isFull() const { return top == MAX_SIZE-1; };
    size_t isFull() const { return top+1; };
};
