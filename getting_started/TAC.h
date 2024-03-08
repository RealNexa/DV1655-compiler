#ifndef TAC_H
#define TAC_H

#include <iostream>
#include <string>
#include <list>


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

    void dump(){
        std::cout << result << " := " << lhs << " " << op << " " << rhs;
    }

};

class Expression : public Tac{
    public:
    Expression(std::string _op, std::string _y, std::string _z, std::string _result) : 
    Tac(_op, _y, _z, _result) {}
};

class UnaryExpression : public Tac {
    public:
    UnaryExpression(std::string _op, std::string _y, std::string _result) :
    Tac(_op, _y, "", _result) {}
};

class Copy : public Tac {
    public:
    Copy(std::string _y, std::string _result) :
    Tac("", _y, "", _result) {}
};

class ArrayAccess : public Tac {
    public:
    ArrayAccess(std::string _y, std::string _i, std::string _result) : 
    Tac("", _y, _i, _result) {}
};

class New : public Tac {
    public:
    New(std::string _type, std::string _result) :
    Tac("new", _type, "", _result) {}
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
};

class MethodCall : public Tac {
    public:
    MethodCall(std::string _f, std::string _N, std::string _result) :
    Tac("call", _f, _N, _result) {}
};

class Return : public Tac{
    public:
    Return(std::string _y, std::string _result) : 
    Tac("return", _y, "", _result) {}
};

class UnconditionalJump : public Tac {
    public:
    UnconditionalJump(std::string _L) :
    Tac("goto", "", "", _L) {}
};

class ConditionalJump : public Tac{
    public:
    ConditionalJump(std::string _L, std::string _op, std::string _x) : 
    Tac(_op, _x, "", _L) {}
};

class BBlock {
    private:
    int variable_count = 0;
    public:
    std::string name;
    std::list<Tac> tacInstructions;
    Tac condition;
    BBlock* trueExit;
    BBlock* falseExit;  
    BBlock() : trueExit(nullptr), falseExit(nullptr) {}

    std::string genName() {
        return "_t" + std::to_string(variable_count++);
    }

    std::string get_print_string() {
        std::string ret_string;
        for(auto it = tacInstructions.begin(); it != tacInstructions.end(); it++) {  
            ret_string += it->getResult() + " := " + it->getLhs() + " " + it->getOp() + " " + it->getRhs() + "\n";
        }
        return ret_string;
    }
};


#endif