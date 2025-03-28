#ifndef TAC_H
#define TAC_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>

struct ProgramData {
    std::map<std::string, int> method_index;
    std::map<std::string, int> variable_index;
    std::map<std::string, int> goto_index;
    int current_row;

    // ProgramData() {
    //     method_index = {};
    //     variable_index = {};
    //     goto_index = {};
    // }  
};

class Tac {

    std::string op;
    std::string lhs;
    std::string rhs;
    std::string result;

    public:
    Tac(std::string _op, std::string _lhs, std::string _rhs, std::string _result):
    op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}

    Tac() = default;

    std::string getOp() {
        return op;
    }
    std::string getLhs() {
        return lhs;
    }
    std::string getRhs() {
        return rhs;
    }
    std::string getResult() {
        return result;
    }
    void setOp(std::string value) {
        op = value;
    }
    void setLhs(std::string value) {
        lhs = value;
    }    
    void setRhs(std::string value) {
        rhs = value;
    }    
    void setResult(std::string value) {
        result = value;
    }

    virtual std::string get_string() {
        return result + " := " + lhs + " " + op + " " + rhs;
    }

    virtual void genByteCode(std::ofstream* outStream, ProgramData* program_data){
        return;
    }

};

class Expression : public Tac{
    public:
    Expression(std::string _op, std::string _y, std::string _z, std::string _result) : 
    Tac(_op, _y, _z, _result) {}
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        
        if (std::isdigit(getLhs().c_str()[0]) != 0) {
            *outStream << "iconst " + (getOp()==">" ? getRhs() : getLhs())<< std::endl;
        }
        else {
            *outStream << "iload " + (getOp()==">" ? getRhs() : getLhs())<< std::endl;
        }        

        *outStream << std::to_string(program_data->current_row++) + " ";
        if (std::isdigit(getRhs().c_str()[0]) != 0) {
            *outStream << "iconst " + (getOp()==">" ? getLhs() : getRhs())<< std::endl;
        }
        else {
            *outStream << "iload " + (getOp()==">" ? getLhs() : getRhs())<< std::endl;
        }
        
        // + - * / && || < > == 
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(getOp() == "+") {

            *outStream << "iadd" << std::endl;
        }
        else if(getOp() == "-"){
            *outStream << "isub" << std::endl;
        }
        else if(getOp() == "*"){
            *outStream << "imul" << std::endl;
        }
        else if(getOp() == "/"){
            *outStream << "idiv" << std::endl;
        }
        else if(getOp() == "&&"){
            *outStream << "iand" << std::endl;
        }
        else if(getOp() == "||"){
            *outStream << "ior" << std::endl;
        }
        else if(getOp() == "<" || getOp() == ">"){
            *outStream << "ilt" << std::endl;
        }
        else if(getOp() == "=="){
            *outStream << "isub" << std::endl;
            *outStream << std::to_string(program_data->current_row++) + " ";
            *outStream << "inot" << std::endl;
        }

        *outStream << std::to_string(program_data->current_row++) + " ";
        
        *outStream << "istore " << getResult() << std::endl;
    }
};

class UnaryExpression : public Tac {
    public:
    UnaryExpression(std::string _op, std::string _y, std::string _result) :
    Tac(_op, _y, "", _result) {}
    std::string get_string() {
        return getResult() + " := " + getOp() + getLhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        
        if (std::isdigit(getLhs().c_str()[0]) != 0) {
            *outStream << "iconst " + getLhs() << std::endl;
        }
        else{
            *outStream << "iload " + getLhs() << std::endl;
        }

        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "inot" << std::endl;

        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "istore " << getResult() << std::endl;
    }
};

class Copy : public Tac {
    public:
    Copy(std::string _y, std::string _result) :
    Tac("", _y, "", _result) {}
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(std::isdigit(getLhs().c_str()[0]) != 0){
            *outStream << "iconst " << getLhs() <<std::endl;
        }
        else {
            *outStream << "iload " << getLhs() <<std::endl;
        }
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "istore " << getResult() << std::endl;
    }
};

class ArrayAccess : public Tac {
    public:
    ArrayAccess(std::string _y, std::string _i, std::string _result) : 
    Tac("", _y, _i, _result) {}
    std::string get_string() {
        return getResult() + " := " + getLhs() + "[" + getRhs() + "]";
    }

};

class New : public Tac {
    public:
    New(std::string _type, std::string _result) :
    Tac("new", _type, "", _result) {}
    std::string get_string() {
        return getResult() + " := " + "new " + getLhs();
    }
};

class NewArray : public Tac {
    public:
    NewArray(std::string _N, std::string _result) :
    Tac("new", "TYPE_INT_LIST", _N, _result) {}
};

class Length : public Tac {
    public:
    Length(std::string _lhs, std::string _result) :
    Tac("length", _lhs, "", _result) {}
};

class Parameter : public Tac{
    public:
    Parameter(std::string _y) : 
    Tac("param", _y, "", "") {}
    std::string get_string() {
        return "param " + getLhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(std::isdigit(getLhs().c_str()[0]) != 0){
            *outStream << "iconst " << getLhs() <<std::endl;
        }
        else {
            *outStream << "iload " << getLhs() <<std::endl;
        }
    }
};

class MethodCall : public Tac {
    public:
    MethodCall(std::string _f, std::string _N, std::string _result) :
    Tac("call", _f, _N, _result) {}
    std::string get_string() {
        return getResult() + " := call " + getLhs() + " " + getRhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "invokevirtual " << getLhs() <<std::endl;
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "istore " << getResult() <<std::endl;
    }
};

class Return : public Tac{
    public:
    Return(std::string _y) : 
    Tac("return", _y, "", "") {}
    std::string get_string() {
        return "return " + getLhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(std::isdigit(getLhs().c_str()[0]) != 0){
            *outStream << "iconst " << getLhs() <<std::endl;
        }
        else {
            *outStream << "iload " << getLhs() <<std::endl;
        }
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "ireturn" << std::endl;
    }
};

class UnconditionalJump : public Tac {
    public:
    UnconditionalJump(std::string _L) :
    Tac("goto", "", "", _L) {}
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "goto " << getResult() <<std::endl;
    }
};

class ConditionalJump : public Tac{
    public:
    ConditionalJump(std::string _L, std::string _op, std::string _x) : 
    Tac(_op, _x, "", _L) {}
    std::string get_string(){
        return getOp() + " " + getLhs() + " goto " +  getResult();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(std::isdigit(getLhs().c_str()[0]) != 0){
            *outStream << "iconst " << getLhs() <<std::endl;
        }
        else {
            *outStream << "iload " << getLhs() <<std::endl;
        }
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << getOp() << " goto " << getResult() << std::endl;
    }
};

class PrintLn : public Tac {
    public:
    PrintLn(std::string _x) : 
    Tac("println", _x, "", "") {}
    std::string get_string(){
        return getOp() + " " + getLhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        if(std::isdigit(getLhs().c_str()[0]) != 0){
            *outStream << "iconst " << getLhs() <<std::endl;
        }
        else {
            *outStream << "iload " << getLhs() <<std::endl;
        }
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "print" << std::endl;
    }
};

class Argument : public Tac {
    public:
    Argument(std::string _x):
    Tac("argument", _x, "", "") {}
    std::string get_string() {
        return getOp() + " " + getLhs();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << "istore " << getLhs() <<std::endl;
    }
};

class Stop : public Tac {
    public:
    Stop():
    Tac("stop", "", "", "") {}
    std::string get_string() {
        return getOp();
    }
    void genByteCode(std::ofstream *outStream, ProgramData* program_data){
        *outStream << std::to_string(program_data->current_row++) + " ";
        *outStream << getOp() << std::endl;
    }
};

class BBlock {
    private:
    int variable_count = 0;
    public:
    static std::string current_class_name;
    static std::list<BBlock*> method_blocks;
    static int block_count;
    std::string name;
    std::list<Tac*> tacInstructions;
    Tac* condition;
    BBlock* trueExit;
    BBlock* falseExit;  
    BBlock() : trueExit(nullptr), falseExit(nullptr) {
        this->name = "block_" + std::to_string(BBlock::block_count);
        block_count++;
    }

    std::string genName() {
        return "_t" + std::to_string(variable_count++);
    }

    std::string get_print_string() {
        std::string ret_string;
        for(auto it = tacInstructions.begin(); it != tacInstructions.end(); it++) {  
            ret_string += (*it)->get_string() + "\n";
        }
        return ret_string;
    }
};
inline int BBlock::block_count = 0;     // cuz C++
inline std::list<BBlock*> BBlock::method_blocks = {};
inline std::string BBlock::current_class_name = "";

#endif