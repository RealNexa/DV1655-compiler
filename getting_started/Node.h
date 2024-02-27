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
		it += 2;
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
		Class *non_main_class = new Class((*it)->value);
		symbol_table->put((*it)->value, non_main_class);
		symbol_table->current_class = non_main_class;

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
		it += 2;
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
		return;
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

		Variable* var = new Variable(identifier, type);
		symbol_table->put(identifier, var);
		symbol_table->current_class->addVariable(identifier, *var);
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		return;
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

		Method* _method = new Method(type, method_name);
		symbol_table->current_method = _method;
		symbol_table->put(method_name, _method);
		symbol_table->current_class->addMethod(method_name, *_method);

		symbol_table->enter_scope();
		it++;
		(*it)->execute(symbol_table); // Adds method parameters to scope
		it++;
		(*it)->execute(symbol_table); // Adds method body to scope
		
		symbol_table->exit_scope();
	}

	void semanticAnalysis(SymbolTable* symbol_table) {
		symbol_table->enter_scope();
		auto it = children.begin();
		std::string method_type = (*it)->evaluate(symbol_table);

		it += 4;
		std::string method_return_type = (*it)->evaluate(symbol_table);
		if (method_type != method_return_type) {
			std::cout << "Method return type mismatch. Line: " << this->lineno << "\n"; 
		}

		auto it = children.begin();
		it += 3;
		(it*)->semanticAnalysis(symbol_table);

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
		return;
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
		return;
	}

	void semanticAnalysis(SymbolTable* symbol_table){
		auto it = children.begin();
		
		std::string id = (*it)->value;
		it++;
		std::string assign_type = (*it)->evaluate(symbol_table);

		Record* lookup = symbol_table.lookup(id);

		if (lookup->record_type == "NULL") {
			std::cout << "Identifier: " << id << " not declared in current scope. Line: " << this->lineno << "\n";
		}
		else if (lookup->record_type != assign_type) {
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

		Record* lookup = symbol_table.lookup(id);

		if (lookup->record_type == "NULL") {
			std::cout << "Identifier: " << id << " not declared in current scope. Line: " << this->lineno << "\n";
		}
		else if (lookup->record_type != "TYPE_INT_LIST") {
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

		if (lhs_type != rhs_type) {
			std::cout << "Type mismatch in add expression. Line: " << this->lineno << "\n";
			return "TYPE_MISMATCH";
		}
		else {
			return lhs_type;
		}
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
};

class ThisNode: public BaseNode {
	public:
	ThisNode(string t, string v, int l) {
		this->type = t;
		this->value = v;
		this->lineno = l;
	}

	void execute(SymbolTable* symbol_table) {
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
		if(symbol_table->lookup(this->value).record_type == "NULL") {
			std::cout << "Identifier " << this->value << " not declared. Line: " << this->lineno << "\n";
			return "ID_NOEXIST";
		}
		else {
			return this->type;
		} 
	}
};




#endif