#include "Node.h"
#include "TAC.h"


std::string GoalNode::genIR(BBlock* current_block) {
    for(auto it = this->children.begin(); it != this->children.end(); it++) {
        (*it)->genIR(current_block);
    }
    return "NULL";
}

std::string AddExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("+", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string SubExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("-", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string MultExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("*", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string DivExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("/", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string LogicAndExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("&&", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string LogicOrExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("||", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string LtExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("<", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string GtExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression(">", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string EqualExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = Expression("==", lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string LBRBExpressionNode::genIR(BBlock* current_block) {
    std::string name = current_block->genName();
    std::string lhs_name = children.front()->genIR(current_block);
    std::string rhs_name = children.back()->genIR(current_block);

    Tac in = ArrayAccess(lhs_name, rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string DotLengthExpressionNode::genIR(BBlock* current_block){
    std::string name = current_block->genName();
    std::string rhs_name = children.front()->genIR(current_block);

    Tac in = Length(rhs_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string MethodCallNode::genIR(BBlock* current_block){
    std::string name = current_block->genName();
    
    auto it = children.begin();
    it++;
    std::string function_name = (*it)->genIR(current_block);
    it++;
    std::string n_arguments = std::to_string(this->children.size()); 
    (*it)->genIR(current_block);

    Tac in = MethodCall(function_name, n_arguments, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string ArgumentsNode::genIR(BBlock* current_block){
    
    for(auto it = children.begin(); it != children.end(); it++) {
        std::string parameter = (*it)->genIR(current_block);

        Tac in = Parameter(parameter);
        current_block->tacInstructions.push_back(in);
    }
    return "NULL";
}

std::string NewListNode::genIR(BBlock* current_block){
    std::string name = current_block->genName();
    std::string index = children.front()->genIR(current_block);
    Tac in = NewArray(index, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string NewObjectNode::genIR(BBlock* current_block){
    std::string name = current_block->genName();
    std::string object_type = children.front()->genIR(current_block);
    Tac in = New(object_type, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string NotNode::genIR(BBlock* current_block){
    std::string name = current_block->genName();
    std::string unary_name = children.front()->genIR(current_block);
    Tac in = UnaryExpression("!", unary_name, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string IdAssignNode::genIR(BBlock* current_block){
    std::string name = children.front()->genIR(current_block);
    std::string assign_value = children.back()->genIR(current_block);
    Tac in = Copy(assign_value, name);
    current_block->tacInstructions.push_back(in);
    return name;
}

std::string NoArgumentsNode::genIR(BBlock* current_block){
    return "NULL";
}

std::string TrueNode::genIR(BBlock* current_block){
    return this->value;
}

std::string FalseNode::genIR(BBlock* current_block){
    return this->value;
}

std::string IdNode::genIR(BBlock* current_block){
    return this->value;
}

std::string IntNode::genIR(BBlock* current_block){
    return this->value;
}

