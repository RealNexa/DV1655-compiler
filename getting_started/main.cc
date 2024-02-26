#include <iostream>
#include "parser.tab.hh"
#include "SymbolTable.h"

extern BaseNode *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

void traverse_preorder(Scope*);

enum errCodes
{
	SUCCESS = 0,
	LEXICAL_ERROR = 1,
	SYNTAX_ERROR = 2,
	AST_ERROR = 3,
	SEMANTIC_ERROR = 4,
	SEGMENTATION_FAULT = 139
};

int errCode = errCodes::SUCCESS;

// Handling Syntax Errors
void yy::parser::error(std::string const &err)
{
	if (!lexical_errors)
	{
		std::cerr << "Syntax errors found! See the logs below:" << std::endl;
		std::cerr << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input:" << err.c_str() << std::endl;
		std::cerr << "End of syntax errors!" << std::endl;
		errCode = errCodes::SYNTAX_ERROR;
	}
}

int main(int argc, char **argv)
{
	// Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
	if (argc > 1)
	{
		if (!(yyin = fopen(argv[1], "r")))
		{
			perror(argv[1]);
			return 1;
		}
	}
	//
	if (USE_LEX_ONLY)
		yylex();
	else
	{
		yy::parser parser;

		bool parseSuccess = !parser.parse();

		if (lexical_errors)
			errCode = errCodes::LEXICAL_ERROR;

		if (parseSuccess && !lexical_errors)
		{
			printf("\nThe compiler successfuly generated a syntax tree for the given input! \n");

			printf("\nPrint Tree:  \n");
			try
			{
				root->print_tree();
				root->generate_tree();
			}
			catch (...)
			{
				errCode = errCodes::AST_ERROR;
			}
			SymbolTable* symbol_table = new SymbolTable();

			root->execute(symbol_table);
			symbol_table->current = symbol_table->root;
			
			root->semanticAnalysis(symbol_table);

			traverse_preorder(symbol_table->root);

		}
	}

	return errCode;
}


/*
void build_symbol_table(Node* root, SymbolTable* table) {
	if (root->type == "GOAL") {
		build_symbol_table(root->children.front(), table);
		build_symbol_table(root->children.back(), table);
	}

	else if (root->type == "MAIN_CLASS") {
		table->enter_scope();
		std::list<Node*>::iterator it = root->children.begin();

		Class main_class((*it)->value, (*it)->type);
		table->put((*it)->value, main_class);
		it++;
		
		Variable parameter((*it)->value, (*it)->type);
		main_class.addVariable((*it)->value, parameter);
		it++;

		Node* body = *it;

		

		build_symbol_table(root->children[2], table);
	}

	else if (root->type == "SCOPE") {
		table->enter_scope();
		for (std::list<Node*>::iterator it = root->children.begin(); it != root->children.end(); ++it){
			build_symbol_table(*it, table);
		}
	}
}



void handle_node(Node* node, SymbolTable* symbol_table) {
	if (node->type == "MAIN_CLASS") { // TODO ADD METHOD
		symbol_table->enter_scope();
		std::list<Node*>::iterator children_it = node->children.begin();
		Class *main_class = new Class((*children_it)->value);
		symbol_table->current_class = main_class;

		children_it++;
		Variable var((*children_it)->value, "TYPE_STRING_LIST");
		symbol_table->current_class->addVariable(var.identifier, var);
		symbol_table->exit_scope();
	}
	else if (node->type == "CLASS_DECLARATION") {
		symbol_table->enter_scope();

		std::list<Node*>::iterator children_it = node->children.begin();
		Class *non_main_class = new Class((*children_it)->value);
		symbol_table->current_class = non_main_class;
		symbol_table->put((*children_it)->value, non_main_class);

	}
	else if (node->type == "VAR_DECLARATIONS") {
		for (auto it = node->children.begin(); it != node->children.end(); it++){
			std::string type = (*it)->children.front()->type;
			std::string value = (*it)->children.back()->value;

			Variable *var = new Variable(value, type); 
			symbol_table->current_class->addVariable(value, *var);
			symbol_table->put(value, var);
		}
	}
	else if (node->type == "METHOD_DECLARATION") {
		symbol_table->enter_scope();
		std::list<Node*>::iterator children_it = node->children.begin();
		std::string type = (*children_it)->type;
		children_it++;
		std::string identifier = (*children_it)->value;
		Method *method = new Method(type, identifier);

		symbol_table->current_class->addMethod(identifier, *method);
		symbol_table->current_method = method;
		symbol_table->put(identifier, method);
	}
}
*/



void print_records(std::map<std::string, Record*> records) {
	std::cout << "\nSCOPE\n";
	for(auto it = records.begin(); it != records.end(); it++) {
		std::cout << (it->second->record_type) << ": " << (it->second)->print_string() << "\n";
	}
}

void traverse_preorder(Scope* root_scope) {
	if (root_scope->children_scope.size() == 0) {
		print_records(root_scope->records);
	} 
	else {
		print_records(root_scope->records);
		for (auto it = root_scope->children_scope.begin(); it != root_scope->children_scope.end(); ++it){
			traverse_preorder(*it);
		}
	}
}



void traverse_postorder(BaseNode* root, SymbolTable* symbol_table) {
	if (root_scope->children_scope.size() == 0) {
		print_records(root_scope->records);
	} 
	else {
		for (auto it = root_scope->children_scope.begin(); it != root_scope->children_scope.end(); ++it){
			traverse_preorder(*it);
		}
		print_records(root_scope->records);
	
	}
}
