#include "interpretator.h"
#include <fstream>
#include <iostream>


int main(int argc, char* argv[]) {
    
    StackMachine stack_machine;
    stack_machine.load_program(argv[1]);
    //stack_machine.program_dump();
    stack_machine.start();
    
}

void StackMachine::start(){
    Method entry;
    entry.method_name = instructions.at(0)->byte_code;
    activation_stack.push(entry);
    
    while (true) {

        if(activation_stack.size() == 0) {
            std::cout << "Program terminated" << std::endl; 
            break;
        }
        int program_pc = activation_stack.top().pc++;
        // int current_offset = offsets.at(activation_stack.top().method_name);
        // int program_pc = local_pc + current_offset;


        if(DEBUG){
            std::cout << "Variables: " << std::endl;
            print_local_variables();
            std::cout << std::endl;
            std::cout << "PC: " << program_pc << std::endl;
            std::cout << "Instruction: " << instructions.at(program_pc)->byte_code << " " << instructions.at(program_pc)->value << std::endl; 
            std::cin.ignore();
        }

        instructions.at(program_pc)->execute(&data_stack, &activation_stack, &offsets);

    }
}

void StackMachine::program_dump(){

    std::cout << "Labels:" << std::endl;
    for(auto it = offsets.begin(); it != offsets.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Instructions:" << std::endl;  
    int row = 0;
    for(auto it = instructions.begin(); it != instructions.end(); it++) {
        std::cout << std::to_string(row) << " " << (*it)->byte_code << " " << (*it)->value << std::endl;
        row++;
    }
}

void StackMachine::load_program(char* filename) {
    std::ifstream byte_file;
    byte_file.open(filename);
    
    int row_count = 0;
    std::string row;
    while(getline(byte_file, row)){
        if(std::isdigit(row[0]) == 0){
            offsets.insert(std::pair<std::string, int>(row, row_count));
        }
        interpret(row);
        row_count++;
    }
    byte_file.close();
}

void StackMachine::interpret(std::string instruction) {
    int instruction_start = instruction.find(' ');
    if(instruction_start == std::string::npos){
        label* l = new label(instruction);
        instructions.push_back(l);
        return;
    }
    
    int instruction_end = instruction.find(' ', instruction_start+1);
    if(instruction_end == std::string::npos){
        std::string operation = instruction.substr(instruction_start+1);
        if(operation == "iadd"){
            iadd* op = new iadd("iadd");
            instructions.push_back(op);
        }
        else if(operation == "isub"){
            isub* op = new isub("isub");
            instructions.push_back(op);
        }
        else if(operation == "imul"){
            imul* op = new imul("imul");
            instructions.push_back(op);
        }
        else if(operation == "idiv"){
            idiv* op = new idiv("idiv");
            instructions.push_back(op);
        }
        else if(operation == "ilt"){
            ilt* op = new ilt("ilt");
            instructions.push_back(op);
        }
        else if(operation == "iand"){
            iand* op = new iand("iand");
            instructions.push_back(op);
        }
        else if(operation == "ior"){
            ior* op = new ior("ior");
            instructions.push_back(op);
        }
        else if(operation == "inot"){
            inot* op = new inot("inot");
            instructions.push_back(op);
        }
        else if(operation == "ireturn"){
            ireturn* op = new ireturn("ireturn");
            instructions.push_back(op);
        }
        else if(operation == "print"){
            print* op = new print("print");
            instructions.push_back(op);
        }
        else if(operation == "stop"){
            stop* op = new stop("stop");
            instructions.push_back(op);
        }
        return;
    }
    std::string operation = instruction.substr(instruction_start+1, instruction_end-instruction_start-1);
    std::string value = instruction.substr(instruction_end+1, std::string::npos);

    if(operation == "iload"){
        iload* op = new iload("iload", value);
        instructions.push_back(op);
    }
    else if(operation == "iconst"){
        iconst* op = new iconst("iconst", value);
        instructions.push_back(op);
    }
    else if(operation == "istore"){
        istore* op = new istore("istore", value);
        instructions.push_back(op);
    }
    else if (operation == "goto") {
        goto_i * op = new goto_i("goto", value);
        instructions.push_back(op);
    }
    else if(operation == "iffalse") {
        int label_start = value.find(" ") + 1;
        std::string label = value.substr(label_start, std::string::npos);
        iffalse_goto_i* op = new iffalse_goto_i("iffalse goto", label);
        instructions.push_back(op);
    }
    else if(operation == "invokevirtual"){
        invoke_virtual* op = new invoke_virtual("invokevirtual", value);
        instructions.push_back(op);
    }
    
    return;
}


void StackMachine::print_local_variables() {

    for (auto it = activation_stack.top().variables.begin(); it != activation_stack.top().variables.end(); it ++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}