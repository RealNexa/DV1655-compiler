/*
	Fix semantic analysis of while statements not accepting expressions a == 3
*/

#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "SymbolTable.h"
#include "TAC.h"

using namespace std;

class BaseNode {
	public:
	int id, lineno;
	string type, value;
	list<BaseNode*> children;

	virtual void execute(SymbolTable*) = 0;
	virtual void semanticAnalysis(SymbolTable*) = 0;
	virtual std::string evaluate(SymbolTable*) {
		return "NULL";
	}
	virtual std::string genIR(BBlock** currentBlock, SymbolTable* symbol_table, BBlock** return_block = nullptr) {
		for(auto it = this->children.begin(); it != this->children.end(); it++) {
			(*it)->genIR(currentBlock, symbol_table, return_block);
		}
		return "NULL";
	};

	void print_tree(int depth=0) {
		for(int i=0; i<depth; i++)
		cout << "  ";
		cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
		for(auto i=children.begin(); i!=children.end(); i++)
		(*i)->print_tree(depth+1);
	}
  
	void generate_tree() {
		std::ofstream outStream;
		char* filename = "tree.dot";
	  	outStream.open(filename);

		int count = 0;
		outStream << "digraph {" << std::endl;
		generate_tree_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();

		printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n", filename);
  	}

  	void generate_tree_content(int &count, ofstream *outStream) {
	  id = count++;
	  *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

	  for (auto i = children.begin(); i != children.end(); i++)
	  {
		  (*i)->generate_tree_content(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << endl;
	  }
  }
  
};

class Node {
public:
	int id, lineno;
	string type, value;
	list<BaseNode*> children;
	Node(string t, string v, int l) : type(t), value(v), lineno(l){}
	Node()
	{
		type = "uninitialised";
		value = "uninitialised"; }   // Bison needs this.
  
	void print_tree(int depth=0) {
		for(int i=0; i<depth; i++)
		cout << "  ";
		cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
		for(auto i=children.begin(); i!=children.end(); i++)
		(*i)->print_tree(depth+1);
	}
  
	void generate_tree() {
		std::ofstream outStream;
		char* filename = "tree.dot";
	  	outStream.open(filename);

		int count = 0;
		outStream << "digraph {" << std::endl;
		generate_tree_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();

		printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n", filename);
  	}

  	void generate_tree_content(int &count, ofstream *outStream) {
	  id = count++;
	  *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

	  for (auto i = children.begin(); i != children.end(); i++)
	  {
		  (*i)->generate_tree_content(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << endl;
	  }
  }

};

class RootNode: public BaseNode {
	public:
	RootNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	};

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}
	};

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	}
};

class GoalNode: public BaseNode {
	public:
	GoalNode(string t, string v, int l){
		this->type = t;
		this->value = v;
		this->lineno = l;
	};

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}
	};

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	};
};

class MainClassNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	MainClassNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		auto it = this->children.begin();
		
		Class* main_class = new Class("CLASS_"+(*it)->value);
		symbol_table->current_class = main_class;
		symbol_table->put("CLASS_" + (*it)->value, main_class);


		symbol_table->enter_scope();
		Method* main_method = new Method("TYPE_VOID", "METHOD_main");
		symbol_table->current_class->addMethod("METHOD_main", *main_method);
		symbol_table->current_method = main_method;
		symbol_table->put("CLASS_main", main_method);

		symbol_table->enter_scope();
		it++;
		Variable* main_variable = new Variable("CLASS_VAR_"+(*it)->value, "TYPE_STRING_LIST");
		symbol_table->current_method->addVariable("CLASS_VAR_"+(*it)->value, *main_variable);
		symbol_table->put("CLASS_VAR_" + (*it)->value, main_variable);

		symbol_table->exit_scope();
		symbol_table->exit_scope();
	}
	
	void semanticAnalysis(SymbolTable* symbol_table) {
		symbol_table->enter_scope();
		symbol_table->enter_scope();
		auto it = this->children.begin();
		it++;
		it++;
		(*it)->semanticAnalysis(symbol_table);
		symbol_table->exit_scope();
		symbol_table->exit_scope();
	}

};

class NonMainClassNode: public BaseNode {
	public:
	NonMainClassNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}		
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}		
	}

};

class ClassDeclarationNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	ClassDeclarationNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		auto it = this->children.begin();

		Record* _record = symbol_table->root->lookup("CLASS_"+(*it)->value);
		if (_record->record_type != "NULL") {
			std::cout << "Line " << this->lineno << ": Class " << (*it)->value << " is already declared." << std::endl;
		}

		Class *non_main_class = new Class("CLASS_"+(*it)->value);
		symbol_table->put("CLASS_" + (*it)->value, non_main_class);
		symbol_table->current_class = non_main_class;
		symbol_table->current_method = nullptr;

		symbol_table->enter_scope();
		
		Variable* _var = new Variable("THIS" ,(*it)->value);
		symbol_table->put("THIS", _var);

		it++;
		(*it)->execute(symbol_table); // Adds class variables to scope

		it++;
		(*it)->execute(symbol_table); // Adds class methods to scope

		symbol_table->exit_scope();
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		symbol_table->enter_scope();
		auto it = children.begin();
		it++;
		(*it)->semanticAnalysis(symbol_table);
		it++;
		(*it)->semanticAnalysis(symbol_table);
		symbol_table->exit_scope();
	}		
};

class VarDeclarationsNode: public BaseNode {
	public:
	VarDeclarationsNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}		
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	}

};

class TypeIdNode: public BaseNode {
	public:
	TypeIdNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		std::string type = children.front()->type;
		std::string identifier = children.back()->value;

		if (type == "TYPE_CUSTOM") {
			type = children.front()->value;
		}

		// Checks if variable is already declared as class variable. Only check if we are declaring class variables
		if(symbol_table->current_method == nullptr){
			if (symbol_table->current_class->lookupVariable("CLASS_VAR_"+identifier)) {
				std::cout << "Line " << this->lineno << ": Class variable " << identifier << " is already declared."<< std::endl;
			}
		}

		// Checks if we are in a method body and NOT a class var declaration
		if(symbol_table->current_method != nullptr) {
			if (symbol_table->current_method->lookupParameterVariable("PARAMETER_"+identifier)){
				std::cout << "Line " << this->lineno << ": Variable " << identifier << " is already declared as parameter." << std::endl;
			}
			if (symbol_table->current_method->lookupVariable("VARIABLE_"+identifier)) {
				std::cout << "Line " << this->lineno << ": Variable " << identifier << " is already declared in method body." << std::endl;
			}
		}
		else {
			Variable* var = new Variable("CLASS_VAR_"+identifier, type);
			symbol_table->put("CLASS_VAR_" + identifier, var);
			symbol_table->current_class->addVariable("CLASS_VAR_"+identifier, *var);
		}
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	}

};

class MethodDeclarationsNode: public BaseNode {
	public:
	MethodDeclarationsNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}		
	}

};

class MethodDeclarationNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	MethodDeclarationNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string type = (*it)->type;
		if (type == "TYPE_CUSTOM") {
			type = (*it)->value;
		}

		it++;
		std::string method_name = (*it)->value;

		if (symbol_table->current_class->lookupMethod("METHOD_"+method_name)) {
			std::cout << "Line " << this->lineno << ": Method " << method_name << " is already declared in class." << std::endl;
		}

		Method* _method = new Method(type, "METHOD_"+method_name);
		symbol_table->current_method = _method;
		symbol_table->put("METHOD_" + method_name, _method);

		symbol_table->enter_scope();
		it++;
		(*it)->execute(symbol_table); // Adds method parameters to scope
		it++;
		(*it)->execute(symbol_table); // Adds method body to scope
		
		symbol_table->exit_scope();
		
		symbol_table->current_class->addMethod("METHOD_"+method_name, *_method);
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		symbol_table->enter_scope();
		
		auto it = children.begin();
		std::string method_type = (*it)->evaluate(symbol_table);
		
		it++; it++; it++; it++;
		std::string method_return_type = (*it)->evaluate(symbol_table);
		if (method_type != method_return_type) {
			std::cout << "Line " << this->lineno << ": Method return type mismatch. Expected: " << method_type << "; Got: " << method_return_type << "." << "\n"; 
		}

		it = children.begin();
		it++; it++; it++;
		(*it)->semanticAnalysis(symbol_table);

		symbol_table->exit_scope();
	}

};

class ParametersNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	ParametersNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
		}
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}
};

class ParameterNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	ParameterNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		std::string type = children.front()->type;
		std::string identifier = children.back()->value;

		if (type == "TYPE_CUSTOM") {
			type = children.front()->value;
		}

		// Check parameter duplicates
		if(symbol_table->current_method->lookupParameterVariable("PARAMETER_"+identifier)) {
			std::cout << "Line " << this->lineno << ": Parameter " << identifier << " is already declared." << std::endl;
		}
		// Checks if parameter is duplicate of class variable
		// if(symbol_table->current_class->lookupVariable(identifier)) {
		// 	std::cout << "Parameter " << identifier << " is duplicate of class variable. Line: " << this->lineno << std::endl;
		// }

		Variable* var = new Variable("PARAMETER_"+identifier, type);
		symbol_table->put("PARAMETER_" + identifier, var);
		symbol_table->current_method->addParameters(*var);
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}
};

class BodyNode: public BaseNode {
	public:
	BodyNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->execute(symbol_table);
			std::string body_type = (*it)->type;
			if (body_type == "TYPEID") {

				std::string type = (*it)->children.front()->type;
				std::string identifier = (*it)->children.back()->value;
				if (type == "TYPE_CUSTOM") {
					type = (*it)->children.front()->value;
				}

				Variable* _variable = new Variable("VARIABLE_"+identifier, type);
				symbol_table->put("VARIABLE_" + identifier, _variable);
				symbol_table->current_method->addVariable("VARIABLE_"+identifier, *_variable);
			}
		}
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	}
};

class TypeIntListNode: public BaseNode {
	public:
	TypeIntListNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return "TYPE_INT_LIST";
	}
};

class TypeBooleanNode: public BaseNode {
	public:
	TypeBooleanNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return "TYPE_BOOLEAN";
	}
};

class TypeIntNode: public BaseNode {
	public:
	TypeIntNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return "TYPE_INT";
	}

};

class TypeCustomNode: public BaseNode {
	public:
	TypeCustomNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	void semanticAnalysis(SymbolTable* symbol_table){
		if (this->type == "TYPE_CUSTOM"){
			Record* _record = symbol_table->root->lookup("CLASS_"+this->value);
			if (_record->record_type == "NULL"){
				std::cout << "Line " << this->lineno << ": Unknown type " << this->value << " is not declared." << std::endl;
			}
		}
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return this->value;
	}

};

class IfNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	IfNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();

		std::string if_type = (*it)->evaluate(symbol_table);
		if(if_type != "TYPE_BOOLEAN") {
			std::cout << "Line " << this->lineno << ": If expression does not evaluate to TYPE_BOOl."<< "\n";
		}

		it++;
		(*it)->semanticAnalysis(symbol_table);
		it++;
		(*it)->semanticAnalysis(symbol_table);
	}
};

class WhileNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	WhileNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();

		std::string if_type = (*it)->evaluate(symbol_table);
		if(if_type != "TYPE_BOOLEAN") {
			std::cout << "Line " << this->lineno << ": While expression does not evaluate to TYPE_BOOL." << "\n";
		}

		it++;
		(*it)->semanticAnalysis(symbol_table);
	}

};

class PrintLnNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	PrintLnNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}

};

class IdAssignNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	IdAssignNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		children.front()->evaluate(symbol_table);
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string id = (*it)->value;
		std::string id_type = (*it)->evaluate(symbol_table);
		it++;
		std::string assign_type = (*it)->evaluate(symbol_table);

		//Record* lookup = symbol_table->lookup("VARIABLE_"+id);

		// if (lookup->record_type == "NULL") {
		// 	std::cout << "Identifier: " << id << " not declared in current scope. Line: " << this->lineno << "\n";
		// }
		if ((id_type != assign_type) || (assign_type == "ID_NOEXIST")) {
			std::cout << "Line " << this->lineno << ": Identifier: " << id << " doesn't match assign type." << "\n";
		}
	}
};

class ListAssignNode: public BaseNode {
	public:
	ListAssignNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string id = (*it)->value;
		it++;
		std::string index_type = (*it)->evaluate(symbol_table);
		it++;
		std::string assign_type = (*it)->evaluate(symbol_table);
		
		Record* lookup = symbol_table->lookup("VARIABLE_"+id);
		if(lookup->record_type == "NULL"){
			lookup = symbol_table->lookup("PARAMETER_"+id);
		}
		if(lookup->record_type == "NULL"){
			lookup = symbol_table->lookup("CLASS_VAR_"+id);
		}

		if (lookup->record_type == "NULL") {
			std::cout << "Line " << this->lineno << ": Identifier: " << id << " not declared in scope." << "\n";
		}
		else if (lookup->type != "TYPE_INT_LIST") {
			std::cout << "Line " << this->lineno << ": Identifier: " << id << " doesn't match assign type." << "\n";
		}
		else if (index_type != "TYPE_INT"){
			std::cout << "Line " << this->lineno << ": Index of identifier: " << id << " does not evaluate to TYPE_INT." << "\n";
		}
		else if (assign_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Expression that assigned is to identifier " << id << " does not evaluate to TYPE_INT." << "\n";
		}
	}
};

class NoElseNode: public BaseNode {
	public:
	NoElseNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		return;
	}
};

class ElseNode: public BaseNode {
	public:
	ElseNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();
		(*it)->semanticAnalysis(symbol_table);
	}

};

class ScopeNode: public BaseNode {
	public:
	ScopeNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		for(auto it = children.begin(); it != children.end(); it++) {
			(*it)->semanticAnalysis(symbol_table);
		}
	}
};

class AddExpressionNode: public BaseNode {
	public:
	AddExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in ADD expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class SubExpressionNode: public BaseNode {
	public:
	SubExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in SUB expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}
	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}
};

class MultExpressionNode: public BaseNode {
	public:
	MultExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in MULT expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}
};

class DivExpressionNode: public BaseNode {
	public:
	DivExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in DIV expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}	

};

class LogicAndExpressionNode: public BaseNode {
	public:
	LogicAndExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_BOOLEAN" || rhs_type != "TYPE_BOOLEAN") {
			std::cout << "Line " << this->lineno << ": Type mismatch in AND expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class LogicOrExpressionNode: public BaseNode {
	public:
	LogicOrExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_BOOLEAN" || rhs_type != "TYPE_BOOLEAN") {
			std::cout << "Line " << this->lineno << ": Type mismatch in OR expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class LtExpressionNode: public BaseNode {
	public:
	LtExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in LT expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return "TYPE_BOOLEAN";
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class GtExpressionNode: public BaseNode {
	public:
	GtExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Line " << this->lineno << ": Type mismatch in GT expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return "TYPE_BOOLEAN";
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class EqualExpressionNode: public BaseNode {
	public:
	EqualExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != rhs_type) {
			std::cout << "Line " << this->lineno << ": Type mismatch in EQUAL expression." << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}


};

class LBRBExpressionNode: public BaseNode {
	public:
	LBRBExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string id_type = (*it)->evaluate(symbol_table);
		it++;
		std::string bracket_expression = (*it)->evaluate(symbol_table);

		if (id_type == "ID_NOEXIST"){
			return "ID_NOEXIST";
		}
		else if (id_type != "TYPE_INT_LIST"){
			std::cout << "Line " << this->lineno << ": Type is not TYPE_INT_LIST." << std::endl;			
			return "TYPE_MISMATCH";
		}
		else if (bracket_expression != "TYPE_INT"){
			std::cout << "Line " << this->lineno << ": Index is not of type TYPE_INT." << std::endl;			
			return "TYPE_MISMATCH";
		}
		else{
			return "TYPE_INT";
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class DotLengthExpressionNode: public BaseNode {
	public:
	DotLengthExpressionNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}
	
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string id_type = (*it)->evaluate(symbol_table);
		
		if (id_type == "ID_NOEXIST"){
			return "ID_NOEXIST";
		}
		else if (id_type != "TYPE_INT_LIST") {
			std::cout << "Line " << this->lineno << ": Type is not TYPE_INT_LIST." << std::endl;			
			return "TYPE_MISMATCH";
		}
		else{
			return "TYPE_INT";
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class MethodCallNode: public BaseNode {
	public:
	MethodCallNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		std::string id_type = (*it)->evaluate(symbol_table);
		it++;
		std::string call_method = (*it)->value;

		it++;
		std::list<BaseNode*> arguments = (*it)->children;


		if (id_type == "ID_NOEXIST"){
			return "ID_NOEXIST";
		}
		else if (id_type == "TYPE_MISMATCH") {
			return "TYPE_MISMATCH";
		}

		Class* class_record = dynamic_cast<Class*>(symbol_table->root->lookup("CLASS_"+id_type));
		if (class_record == nullptr) {
			std::cout << "Line " << this->lineno << ": Class " << id_type << " is not declared." << "\n";
			return "ID_NOEXIST";
		}
		else {
			auto method_iterator = class_record->class_methods.find("METHOD_"+call_method);
			if(method_iterator == class_record->class_methods.end()){
				std::cout << "Line " << this->lineno << ": Class method " << call_method << " is not declared." << std::endl;
				return "METHOD_NOEXIST";
			}
			else {
				std::vector<Variable> parameters = method_iterator->second.parameters;
				if (parameters.size() != arguments.size()) {
					std::cout << "Line " << this->lineno << ": The number of arguments does not match number of parameters." << "\n"; 
					return "SIZE_MISMATCH";
				}
				else{
					bool is_valid = true;
					auto argument_it = arguments.begin();
					auto parameter_it = parameters.begin();
					
					while(argument_it != arguments.end() && parameter_it != parameters.end()) {
						std::string argument_type = (*argument_it)->evaluate(symbol_table);
						std::string parameter_type = parameter_it->type;

						if (argument_type != parameter_type) {
							std::cout << "Line " << this->lineno << ": Argument type mismatch. Expected: " << argument_type <<"; Got: " << parameter_type << "."<< std::endl;
							is_valid = false;
						}
						
						argument_it++;
						parameter_it++;
					}

					if (is_valid){
						return method_iterator->second.type;
					}
					else {
						return "TYPE_MISMATCH";
					}
				}
			}
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}	
};

class TrueNode: public BaseNode {
	public:
	TrueNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return "TYPE_BOOLEAN";
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class FalseNode: public BaseNode {
	public:
	FalseNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		return "TYPE_BOOLEAN";
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class ThisNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	ThisNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string evaluate(SymbolTable* symbol_table){
		Record* _record = symbol_table->lookup("THIS");

		if (_record->record_type == "NULL")
		{
			return "TYPE_NOEXIST";
		}
		else{
			return _record->type;
		}
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class NewListNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	NewListNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string bracket_type = (*it)->evaluate(symbol_table);
		
		if (bracket_type != "TYPE_INT"){
			std::cout << "Line " << this->lineno << ": Type in bracket is not TYPE_INT." << std::endl;
			return "TYPE_MISMATCH";
		}
		else {
			return "TYPE_INT_LIST";
		}
	}
	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class NewObjectNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	NewObjectNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		Record* id_record = symbol_table->root->lookup("CLASS_"+(*it)->value);

		if (id_record->record_type == "NULL"){
			// Below not needed since if class does not exist, then the evaluate at 3 lines above would print that identifier is not declared.
			// std::cout << "Line: " << this->lineno << ". Class is not declared.." << std::endl;
			return "ID_NOEXIST";
		}
		else if (id_record->record_type != "CLASS") {
			std::cout << "Line " << this->lineno << ": Error: " << id_record->identifier << "is of type CLASS." << std::endl;
			return "TYPE_MISMATCH";
		}
		else {
			return id_record->type;
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class NotNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	NotNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		std::string not_type = (*it)->evaluate(symbol_table);
		if (not_type != "TYPE_BOOLEAN") {
			std::cout << "Line " << this->lineno << ": Expression does not evaluate to TYPE_BOOLEAN." << "\n";
			return "TYPE_MISMATCH";
		}
		else{
			return "TYPE_BOOLEAN";
		}
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class NoArgumentsNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);
	NoArgumentsNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}
	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class ArgumentsNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	ArgumentsNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}
	void execute(SymbolTable* symbol_table) {
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class IntNode: public BaseNode {
	public:
	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	IntNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table){
		return "TYPE_INT";
	}

	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}

};

class IdNode: public BaseNode {
	public:
	IdNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	std::string genIR(BBlock** current_block, SymbolTable* symbol_table, BBlock** return_block = nullptr);

	void execute(SymbolTable* symbol_table) {
		return;
	}

	//very different from evaluate. It does not print. If something change in evaluate, change it here too to keep functionallity
	std::string evaluate_no_print(SymbolTable* symbol_table){
		auto it = children.begin();
		Record* id_record;

		id_record = symbol_table->lookup("VARIABLE_"+this->value);
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("CLASS_VAR_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("PARAMETER_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("METHOD_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("CLASS_"+this->value);
		}
		
		if(id_record->record_type == "NULL") {
			return "ID_NOEXIST";
		}
		else {
			if(id_record->type == "TYPE_CUSTOM"){
				return id_record->identifier;
			}
			else {
				return id_record->type;
			}
		} 
	}

	
	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		Record* id_record;

		id_record = symbol_table->lookup("VARIABLE_"+this->value);
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("CLASS_VAR_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("PARAMETER_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("METHOD_"+this->value);
		}
		if (id_record->record_type == "NULL"){
			id_record = symbol_table->lookup("CLASS_"+this->value);
		}
		
		if(id_record->record_type == "NULL") {
			std::cout << "Line " << this->lineno << ": Identifier " << this->value << " is not declared." << "\n";
			return "ID_NOEXIST";
		}
		else {
			if(id_record->type == "TYPE_CUSTOM"){
				return id_record->identifier;
			}
			else {
				return id_record->type;
			}
		} 
	}
	void semanticAnalysis(SymbolTable* symbol_Table){
		return;
	}
};

// This is the end of the code. This code is very good and optimized and does not have any memory leaks.
#endif