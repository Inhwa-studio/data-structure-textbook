#include <iostream>
#include "./include/stack.hpp"

int main() {
    Stack<int> intStack(2);

    std::cout << "int Stack is_empty: " << intStack.is_empty() << std::endl;  

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);  
    intStack.push(40);  
    intStack.push(50);  
    intStack.push(60);  

    std::cout << "int Stack peek: " << intStack.peek() << std::endl;  
    
    intStack.pop();  

    std::cout << "int Stack peek: " << intStack.peek() << std::endl;  

    Stack<double> doubleStack(3);
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    std::cout << "double Stack peek: " << doubleStack.peek() << std::endl;  

    Stack<std::string> stringStack(2);
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "string Stack peek: " << stringStack.peek() << std::endl;  

    return 0;
}
