#ifndef SYMBOLTABLE_H
#define	SYMBOLTABLE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include <algorithm>
#include <sstream>


class Record{
    public:
    std::string identifier;
    std::string type;
    std::string record_type;
    
    std::string print_string() {
        return type + " " + identifier;
    }

    virtual ~Record() = default;
};

class NullRecord: public Record {
    public:
    NullRecord() {
        identifier = std::string();
        type = std::string();
        record_type = "NULL";
    }
};

class Variable: public Record{
    public:
    Variable(std::string identifier, std::string type) {
        this->identifier = identifier;
        this->type = type;
        this->record_type = "VARIABLE";
    }

    bool operator==(const Variable& other) {
        return (this->identifier == other.identifier) && (this->type == other.type);
    }
};

class Method: public Record{

    public:
    std::vector<Variable> parameters;
    std::map<std::string, Variable> variables;

    Method(std::string type, std::string identifier) {
        this->type = type;
        this->identifier = identifier;
        this->record_type = "METHOD";
    }

    void addParameters(Variable value){
        parameters.push_back(value);
    }
    void addVariable(std::string key, Variable value){
        variables.insert(std::pair<std::string, Variable>(key, value));
    }
    bool lookupVariable(std::string key){
        return variables.find(key) != variables.end();
    }
    bool lookupParameterVariable(std::string variable){
        for(auto it = parameters.begin(); it != parameters.end(); it++) {
            if (it->identifier == variable) {
                return true;
            }
        }
        return false;
    }

};


class Class: public Record{

    public:
    std::map<std::string,Variable> class_variables;
    std::map<std::string,Method> class_methods;

    Class(std::string identifier){
        this->identifier = identifier;
        this->type = identifier;
        this->record_type = "CLASS";
    }

    void addVariable(std::string key, Variable value){
        class_variables.insert(std::pair<std::string, Variable>(key, value));
    }
    void addMethod(std::string key, Method value){
        class_methods.insert(std::pair<std::string, Method>(key, value));
    }
    bool lookupVariable(std::string key){
        return this->class_variables.find(key) != this->class_variables.end();
    }
    bool lookupMethod(std::string key){
        return this->class_methods.find(key) != this->class_methods.end();
    }
};


class Scope {
    public:
        int id;
        int next_child_index = 0;
        Scope* parent;
        std::map<std::string, Record*> records;
        std::vector<Scope*> children_scope;
        Scope() {this->parent = nullptr;};
        Scope(Scope* parent) {
            this->parent = parent;
        };
    
    Scope* next_child() {
        Scope* next_child;
        if (this->next_child_index == children_scope.size()) {
            next_child = new Scope(this);
            children_scope.push_back(next_child);
        }
        else {
            next_child = children_scope.at(next_child_index);
        }
        next_child_index++;
        return next_child;
    }
    Record* lookup(std::string key) {
       if (records.find(key) != records.end()) {    // key exist
            return records.at(key);
       } 
       else{        // key doesn't exist
            if (parent == nullptr) {
                return new NullRecord();
            }
            else{
                return parent->lookup(key);
            }
       }
    }

    bool exist(std::string key) {
       if (records.find(key) != records.end()) {    // key exist
            return true;
       } 
       else{        // key doesn't exist
            if (parent == nullptr) {
                return false;
            }
            else{
                return parent->exist(key);
            }
       }
    }

    bool remove(std::string key){
        if (exist(key)) {
            records.erase(key);
            return true;
        }
        else{
            return false;
        }
    }

    std::string get_records_string() {

        std::stringstream records_string;
        for(auto it = records.begin(); it != records.end(); it++) {
            records_string  << "Identifier: " << it->second->identifier
                            << ", Record: " << it->second->record_type 
                            << ", Type: " << it->second->type << "\\n";
        }
        return records_string.str();
    }

    void generate_tree_content(int &count, std::ofstream *outStream) {
	    id = count++;
	    *outStream << "n" << id << " [label=\"" << this->get_records_string() << "\"];" << std::endl;

	  for (auto i = children_scope.begin(); i != children_scope.end(); i++)
	  {
		  (*i)->generate_tree_content(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << std::endl;
	  }
    }

};

class SymbolTable{
    public:
    Scope* current;
    Scope* root;
    Method* current_method;
    Class* current_class;

    SymbolTable() {
        root = new Scope();
        current = root;
    };

    void enter_scope() {
        current = current->next_child();
    }

    void exit_scope() {
        this->current = current->parent;
    }

    void put(std::string record_name, Record* record_value) {
        current->records.insert(std::pair<std::string, Record*>(record_name, record_value));
    }

    Record* lookup(std::string key) {
        return current->lookup(key);
    }

    bool exist(std::string key) {
        return current->exist(key);
    }

    bool remove(std::string key) {
        return current->remove(key);
    }

    void generate_tree() {
		std::ofstream outStream;
		char* filename = "table.dot";
	  	outStream.open(filename);

		int count = 0;
		outStream << "digraph {" << std::endl;
		root->generate_tree_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();

    }

    void print_current_scope() {
        std::cout << "Current Scope: " << std::endl;
        std::cout << current->get_records_string() << "\n";
    }

    void reset_tree() {
        this->current = this->root;
        recursive_reset(this->root);
    }

    void recursive_reset(Scope* s) {
        s->next_child_index = 0;
        for (auto i = s->children_scope.begin(); i != s->children_scope.end(); i++){
            recursive_reset(*i);
        }    
    }
};

#endif
