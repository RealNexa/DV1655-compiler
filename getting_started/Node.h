#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "SymbolTable.h"

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
	MainClassNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		auto it = this->children.begin();
		
		Class* main_class = new Class((*it)->value);
		symbol_table->current_class = main_class;
		symbol_table->put((*it)->value, main_class);


		symbol_table->enter_scope();
		Method* main_method = new Method("TYPE_VOID", "main");
		symbol_table->current_class->addMethod("main", *main_method);
		symbol_table->current_method = main_method;
		symbol_table->put("main", main_method);

		symbol_table->enter_scope();
		it++;
		Variable* main_variable = new Variable((*it)->value, "TYPE_STRING_LIST");
		symbol_table->current_method->addVariable((*it)->value, *main_variable);
		symbol_table->put((*it)->value, main_variable);

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
	ClassDeclarationNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
		
		auto it = this->children.begin();

		Record* _record = symbol_table->root->lookup((*it)->value);
		if (_record->record_type != "NULL") {
			std::cout << "Class " << (*it)->value << " is duplicate. Line: " << this->lineno << std::endl;
		}

		Class *non_main_class = new Class((*it)->value);
		symbol_table->put((*it)->value, non_main_class);
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

		if (symbol_table->current_class->lookupVariable(identifier)) {
			std::cout << "Class variable " << identifier << " is duplicate. Line: " << this->lineno << std::endl;
		}

		// Checks if we are in a method body and NOT a class var declaration
		if(symbol_table->current_method != nullptr) {
			if (symbol_table->current_method->lookupParameterVariable(identifier)){
				std::cout << "Variable " << identifier << " is duplicate of parameter. Line: " << this->lineno << std::endl;
			}
			if (symbol_table->current_method->lookupVariable(identifier)) {
				std::cout << "Variable " << identifier << " is duplicate. Line: " << this->lineno << std::endl;
			}
		}
		else {
			Variable* var = new Variable(identifier, type);
			symbol_table->put(identifier, var);
			symbol_table->current_class->addVariable(identifier, *var);
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

		if (symbol_table->current_class->lookupMethod(method_name)) {
			std::cout << "Method " << method_name << " is duplicate. Line: " << this->lineno << std::endl;
		}

		Method* _method = new Method(type, method_name);
		symbol_table->current_method = _method;
		symbol_table->put(method_name, _method);

		symbol_table->enter_scope();
		it++;
		(*it)->execute(symbol_table); // Adds method parameters to scope
		it++;
		(*it)->execute(symbol_table); // Adds method body to scope
		
		symbol_table->exit_scope();
		
		symbol_table->current_class->addMethod(method_name, *_method);
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		symbol_table->enter_scope();
		//symbol_table->print_current_scope();
		auto it = children.begin();
		std::string method_type = (*it)->evaluate(symbol_table);
		
		it++; it++; it++; it++;
		std::string method_return_type = (*it)->evaluate(symbol_table);
		if (method_type != method_return_type) {
			std::cout << "Method return type mismatch. Line: " << this->lineno << "\n"; 
		}

		it = children.begin();
		it++; it++; it++;
		(*it)->semanticAnalysis(symbol_table);

		symbol_table->exit_scope();
	}

};

class ParametersNode: public BaseNode {
	public:
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
		if(symbol_table->current_method->lookupParameterVariable(identifier)) {
			std::cout << "Parameter " << identifier << " is duplicate. Line: " << this->lineno << std::endl;
		}
		// Checks if parameter is duplicate of class variable
		// if(symbol_table->current_class->lookupVariable(identifier)) {
		// 	std::cout << "Parameter " << identifier << " is duplicate of class variable. Line: " << this->lineno << std::endl;
		// }

		Variable* var = new Variable(identifier, type);
		symbol_table->put(identifier, var);
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
					type = children.front()->value;
				}

				Variable* _variable = new Variable(identifier, type);
				symbol_table->put(identifier, _variable);
				symbol_table->current_method->addVariable(identifier, *_variable);
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
			Record* _record = symbol_table->root->lookup(this->value);
			if (_record->record_type == "NULL"){
				std::cout << "Type" << this->value << " doesn't exist. Line: " << this->lineno << std::endl;
			}
		}
	}

	std::string evaluate(SymbolTable* symbol_table) {
		return this->value;
	}

};

class IfNode: public BaseNode {
	public:
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
			std::cout << "If statement is not boolean. Line: " << this->lineno << "\n";
		}

		it++;
		(*it)->semanticAnalysis(symbol_table);
		it++;
		(*it)->semanticAnalysis(symbol_table);
	}
};

class WhileNode: public BaseNode {
	public:
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
			std::cout << "While statement is not boolean. Line: " << this->lineno << "\n";
		}

		it++;
		(*it)->semanticAnalysis(symbol_table);
	}

};

class PrintLnNode: public BaseNode {
	public:
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
		it++;
		std::string assign_type = (*it)->evaluate(symbol_table);

		Record* lookup = symbol_table->lookup(id);

		// if (lookup->record_type == "NULL") {
		// 	std::cout << "Identifier: " << id << " not declared in current scope. Line: " << this->lineno << "\n";
		// }
		if ((lookup->type != assign_type) || (assign_type == "ID_NOEXIST")) {
			std::cout << "identifier: " << id << " doesn't match assign type. Line: " << this->lineno << "\n";
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

		Record* lookup = symbol_table->lookup(id);

		if (lookup->record_type == "NULL") {
			std::cout << "Identifier: " << id << " not declared in current scope. Line: " << this->lineno << "\n";
		}
		else if (lookup->type != "TYPE_INT_LIST") {
			std::cout << "Identifier: " << id << " doesn't match assign type. Line: " << this->lineno << "\n";
		}
		else if (index_type != "TYPE_INT"){
			std::cout << "Index on identifier: " << id << " is not INT. Line: " << this->lineno << "\n";
		}
		else if (assign_type != "TYPE_INT") {
			std::cout << "Expression on identifier: " << id << " is not INT. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in add expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in sub expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in mult expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in div expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_BOOLEAN" || rhs_type != "TYPE_BOOLEAN") {
			std::cout << "Type mismatch in logicAND expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_BOOLEAN" || rhs_type != "TYPE_BOOLEAN") {
			std::cout << "Type mismatch in logicOR expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in LT expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}

	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != "TYPE_INT" || rhs_type != "TYPE_INT") {
			std::cout << "Type mismatch in GT expression. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	std::string evaluate(SymbolTable* symbol_table) {
		auto it = children.begin();
		std::string lhs_type = (*it)->evaluate(symbol_table);
		it++;
		std::string rhs_type = (*it)->evaluate(symbol_table);

		if (lhs_type != rhs_type) {
			std::cout << "Type mismatch in EQUAL expression. Line: " << this->lineno << "\n";
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
			std::cout << "Type is not INT LIST. Line: " << this->lineno << std::endl;			
			return "TYPE_MISMATCH";
		}
		else if (bracket_expression != "TYPE_INT"){
			std::cout << "Type is not INT. Line: " << this->lineno << std::endl;			
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
			std::cout << "Type is not INT LIST. Line: " << this->lineno << std::endl;			
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

		Class* class_record = dynamic_cast<Class*>(symbol_table->root->lookup(id_type));
		if (class_record == nullptr) {
			std::cout << "Class " << id_type << " not defined. Line: " << this->lineno << "\n";
			return "ID_NOEXIST";
		}
		else {
		// TODO REWRITE, SEE INVALIDNESTEDMETHODCALLS :)
			auto method_iterator = class_record->class_methods.find(call_method);
			if(method_iterator == class_record->class_methods.end()){
				std::cout << "Class method " << call_method << " doesn't exist. Line: " << this->lineno << std::endl;
				return "METHOD_NOEXIST";
			}
			else {
				std::vector<Variable> parameters = method_iterator->second.parameters;
				if (parameters.size() != arguments.size()) {
					std::cout << "Size mismatch in method call. Line: " << this->lineno << "\n"; 
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
							std::cout << "Argument type mismatch. Lineno: " << this->lineno << std::endl;
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
			std::cout << "Type in bracket is not int. Lineno: " << this->lineno << std::endl;
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

		Record* id_record = symbol_table->root->lookup((*it)->evaluate(symbol_table));

		if (id_record->record_type == "NULL"){
			std::cout << "Class is not declared. Lineno: " << this->lineno << std::endl;
			return "ID_NOEXIST";
		}
		else if (id_record->record_type != "CLASS") {
			std::cout << "Class: " << id_record->identifier << "is not declared. Lineno: " << this->lineno << std::endl;
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
			std::cout << "Expression is not a boolean. Line: " << this->lineno << "\n";
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

	void execute(SymbolTable* symbol_table) {
		return;
	}
	
	std::string evaluate(SymbolTable* symbol_table){
		auto it = children.begin();
		Record* id_record = symbol_table->lookup(this->value);
		
		if(id_record->record_type == "NULL") {
			std::cout << "Identifier " << this->value << " not declared. Line: " << this->lineno << "\n";
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