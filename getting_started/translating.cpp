#include "Node.h"
#include "TAC.h"


std::string GoalNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    for(auto it = this->children.begin(); it != this->children.end(); it++) {
        (*it)->genIR(current_block, symbol_table);
    }
    return "NULL";
}

std::string AddExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("+", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string SubExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("-", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string MultExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("*", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string DivExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("/", lhs_name, rhs_name, name);
   (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string LogicAndExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("&&", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string LogicOrExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("||", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string LtExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("<", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name; 
}

std::string GtExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression(">", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string EqualExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    Expression* in = new Expression("==", lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string LBRBExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = (*current_block)->genName();
    std::string lhs_name = children.front()->genIR(current_block, symbol_table);
    std::string rhs_name = children.back()->genIR(current_block, symbol_table);

    ArrayAccess* in = new ArrayAccess(lhs_name, rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string DotLengthExpressionNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = (*current_block)->genName();
    std::string rhs_name = children.front()->genIR(current_block, symbol_table);

    Length* in = new Length(rhs_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string MethodCallNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = (*current_block)->genName();
    
    auto it = children.begin();
    std::string callee_class = "";

    if ((*it)->type == "NEW_OBJECT"){
        callee_class = (*it)->children.front()->value;
    }
    else if ((*it)->type == "THIS"){
        Record* lookup = symbol_table->lookup("THIS");
        callee_class = lookup->type;
    }
    else if ((*it)->type == "ID"){
        Record* lookup = symbol_table->lookup("VARIABLE_" + (*it)->value);
        if(lookup->record_type == "NULL") {
            lookup = symbol_table->lookup("PARAMETER_"+ (*it)->value);
        }
        if(lookup->record_type == "NULL") {
            lookup = symbol_table->lookup("CLASS_VAR_"+ (*it)->value);
        }

        callee_class = lookup->type;
    }

    it++;
    std::string function_name = callee_class + "." + (*it)->genIR(current_block, symbol_table);
    it++;
    std::string n_arguments = std::to_string((*it)->children.size()); // +1 for the callee class as parameter
    (*it)->genIR(current_block, symbol_table); // Adds parameters to current block

    MethodCall* in = new MethodCall(function_name, n_arguments, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string ArgumentsNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    
    for(auto it = children.begin(); it != children.end(); it++) {
        std::string parameter = (*it)->genIR(current_block, symbol_table);

        Parameter* in = new Parameter(parameter);
        (*current_block)->tacInstructions.push_back(in);
    }
    return "NULL";
}

std::string NewListNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = (*current_block)->genName();
    std::string index = children.front()->genIR(current_block, symbol_table);
    NewArray* in = new NewArray(index, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string NewObjectNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = (*current_block)->genName();
    std::string object_type = children.front()->genIR(current_block, symbol_table);
    New* in = new New(object_type, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string NotNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = (*current_block)->genName();
    std::string unary_name = children.front()->genIR(current_block, symbol_table);
    UnaryExpression* in = new UnaryExpression("!", unary_name, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string IdAssignNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    std::string name = children.front()->genIR(current_block, symbol_table);
    std::string assign_value = children.back()->genIR(current_block, symbol_table);
    Copy* in = new Copy(assign_value, name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string NoArgumentsNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return "NULL";
}

std::string TrueNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return "1";
}

std::string FalseNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return "0";
}

std::string IdNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return this->value;
}

std::string IntNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return this->value;
}

std::string ThisNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    return BBlock::current_class_name;
}

std::string IfNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    auto it = children.begin();  
    
    std::string name = (*it)->genIR(current_block, symbol_table);
    it++;
    
    BBlock* tBlock = new BBlock();
    (*current_block)->trueExit = tBlock;
    (*it)->genIR(&tBlock, symbol_table);
    it++;

    BBlock* fBlock = new BBlock();
    (*current_block)->falseExit = fBlock;
    (*it)->genIR(&fBlock, symbol_table);
    ConditionalJump* in = new ConditionalJump(fBlock->name, "iffalse", name);
    (*current_block)->tacInstructions.push_back(in);
    
    BBlock* jBlock = new BBlock();
    tBlock->trueExit = jBlock;
    fBlock->trueExit = jBlock;

    if (return_block != nullptr){
        jBlock->trueExit = *return_block;
    }

    *current_block = jBlock;

    return name;    
}

std::string WhileNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {

    BBlock* hBlock = new BBlock();
    (*current_block)->trueExit = hBlock;
    std::string name = children.front()->genIR(&hBlock, symbol_table);


    BBlock* bBlock = new BBlock();
    BBlock* jBlock = new BBlock();
    
    ConditionalJump* in = new ConditionalJump(jBlock->name, "iffalse", name);
    hBlock->tacInstructions.push_back(in);

    hBlock->trueExit = bBlock;
    hBlock->falseExit = jBlock;
    bBlock->trueExit = hBlock;
    
    children.back()->genIR(&bBlock, symbol_table, &hBlock);

    if (return_block != nullptr){
        jBlock->trueExit = *return_block;
    }

    *current_block = jBlock;
    
    return name;
}

std::string MethodDeclarationNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block){
    auto it = children.begin();
    symbol_table->enter_scope();
    BBlock* mBlock = new BBlock();
    BBlock::method_blocks.push_back(mBlock);
    it++;
    mBlock->name = BBlock::current_class_name + "." + (*it)->value; // Get name of method
    
    it++;
    (*it)->genIR(&mBlock, symbol_table);

    it++;
    (*it)->genIR(&mBlock, symbol_table); // Populate method block.
    
    it++;
    std::string name =  (*it)->genIR(&mBlock, symbol_table); // Add return statement
    Return* in = new Return(name);
    mBlock->tacInstructions.push_back(in);
    symbol_table->exit_scope();

    return name;
}

std::string MainClassNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    auto it = children.begin();
    symbol_table->enter_scope();
    BBlock::current_class_name = (*it)->value;

    it++;
    (*it)->genIR(current_block, symbol_table, return_block);
    symbol_table->enter_scope();
    it++;
    (*it)->genIR(current_block, symbol_table, return_block);

    symbol_table->exit_scope();
    symbol_table->exit_scope();

    Stop* in = new Stop();
    (*current_block)->tacInstructions.push_back(in);

    return "NULL";
}

std::string ClassDeclarationNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    auto it = children.begin();
    BBlock::current_class_name = (*it)->value;
    symbol_table->enter_scope();
    it++;
    (*it)->genIR(current_block, symbol_table, return_block);
    it++;
    (*it)->genIR(current_block, symbol_table, return_block);

    symbol_table->exit_scope();
    return "NULL";

}

std::string PrintLnNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = children.front()->genIR(current_block, symbol_table);
    PrintLn* in = new PrintLn(name);
    (*current_block)->tacInstructions.push_back(in);
    return name;
}

std::string ParameterNode::genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block) {
    std::string name = children.back()->genIR(current_block, symbol_table);
    Argument* arg = new Argument(name);
    (*current_block)->tacInstructions.push_back(arg);

    return name;
}

std::string ParametersNode::genIR(BBlock** currentBlock, SymbolTable* symbol_table, BBlock** return_block) {
    for(auto it = this->children.rbegin(); it != this->children.rend(); it++) {
        (*it)->genIR(currentBlock, symbol_table, return_block);
    }
    return "NULL";
};
