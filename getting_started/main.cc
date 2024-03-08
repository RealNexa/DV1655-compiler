#include <iostream>
#include "parser.tab.hh"
#include "SymbolTable.h"
#include "TAC.h"
#include "CFG.h"

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

			// Populate symbol table
			root->execute(symbol_table);

			// Create symbol table tree
			symbol_table->generate_tree();

			// Reset next_child counters
			symbol_table->reset_tree();
			
			root->semanticAnalysis(symbol_table);


			// IR code generation
			BBlock* entry = new BBlock();
			entry->name = "ENTRY";
			
			root->genIR(entry);

			generate_CFG(entry);
		}
	}

	return errCode;
}

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
