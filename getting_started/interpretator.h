#ifndef INTERPRETATOR_H
#define INTREPRETATOR_H

#include <stack>
#include <string>
#include <map>
#include <vector>
#include <iostream>

#define DEBUG false

struct Method {
    int pc = 0;
    std::string method_name;
    std::map<std::string, int> variables = {};
};


class Instruction {
    public:
    std::string byte_code;
    std::string value;
    virtual void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) = 0;
    Instruction(std::string byte_code, std::string value) {
        this->byte_code = byte_code;
        this->value = value;
    }
};

class label: public Instruction {
    public:
    label(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        return;
    }
};

class iload: public Instruction {
    public:
    iload(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int var_val = activation_stack->top().variables.at(value);
        data_stack->push(var_val);
    }
};

class iconst: public Instruction {
    public:
    iconst(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number = std::stoi(value);
        data_stack->push(number);
    }
};

class istore: public Instruction {
    public:
    istore(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number = data_stack->top();
        data_stack->pop();
        activation_stack->top().variables[value] = number;
    }
};

class iadd: public Instruction {
    public:
    iadd(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        int sum = number2 + number1;
        data_stack->push(sum);
    }
};

class isub: public Instruction {
    public:
    isub(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        int diff = number2 - number1;
        data_stack->push(diff);
    }
};

class imul: public Instruction {
    public:
    imul(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        int prod = number1 * number2;
        data_stack->push(prod);
    }
};

class idiv: public Instruction {
    public:
    idiv(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        int quotient = number2 / number1;
        data_stack->push(quotient);
    }
};

class ilt: public Instruction {
    public:
    ilt(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        if(number2 < number1){
            data_stack->push(1);
        }
        else {
            data_stack->push(0);
        }
    }
};

class iand: public Instruction {
    public:
    iand(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        if((number2 * number1) == 0){
            data_stack->push(0);
        }
        else {
            data_stack->push(1);
        }
    }
};

class ior: public Instruction {
    public:
    ior(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number1 = data_stack->top();
        data_stack->pop();
        int number2 = data_stack->top();
        data_stack->pop();
        if((number2 + number1) == 0){
            data_stack->push(0);
        }
        else {
            data_stack->push(1);
        }
    }
};

class inot: public Instruction {
    public:
    inot(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number = data_stack->top();
        data_stack->pop();

        if(number == 0){
            data_stack->push(1);
        }
        else {
            data_stack->push(0);
        }
    }
};

class goto_i: public Instruction {
    public:
    goto_i(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int offset = offsets->at(value);
        activation_stack->top().pc = offset;
    }
};

class iffalse_goto_i: public Instruction {
    public:
    iffalse_goto_i(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number = data_stack->top(); 
        data_stack->pop();
        if(number == 0) {
            int offset = offsets->at(value);
            activation_stack->top().pc = offset;   
        }
    }
};

class invoke_virtual: public Instruction {
    public:
    invoke_virtual(std::string byte_code, std::string value) :
    Instruction(byte_code, value) {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        Method method;
        method.method_name = value;
        method.pc = offsets->at(value);
        activation_stack->push(method);
    }
};

class ireturn: public Instruction {
    public:
    ireturn(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        activation_stack->pop();
    }
};

class print: public Instruction {
    public:
    print(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        int number = data_stack->top();
        data_stack->pop();
        std::cout << number << std::endl;
    }
};

class stop: public Instruction {
    public:
    stop(std::string byte_code) :
    Instruction(byte_code, "") {};
    void execute(std::stack<int>* data_stack, std::stack<Method>* activation_stack, std::map<std::string, int>* offsets) {
        activation_stack->pop();
    }
};

class StackMachine {
    public:
    StackMachine() = default;
    std::stack<int> data_stack;
    std::stack<Method> activation_stack;
    std::map<std::string, int> offsets;
    std::vector<Instruction*> instructions;

    void load_program(char* filename);
    void interpret(std::string instruction);

    void program_dump();
    void start();

    private:
    void print_data_stack();
    void print_local_variables();

};




#endif