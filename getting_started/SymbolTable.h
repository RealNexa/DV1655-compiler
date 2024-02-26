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


class Record{
    public:
    std::string identifier;
    std::string type;
    std::string record_type;
    
    std::string print_string() {
        return type + " " + identifier;
    }
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
    std::vector<Variable> parameters;
    std::map<std::string, Variable> variables;

    public:
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
    std::map<std::string, Variable>::iterator lookupVariable(std::string key){
        variables.find(key);
    }
    std::vector<Variable>::iterator lookupParameterVariable(Variable variable){
        std::vector<Variable>::iterator iter;
        iter = std::find(parameters.begin(), parameters.end(), variable);
        return iter;
    }

};


class Class: public Record{
    std::map<std::string,Variable> class_variables;
    std::map<std::string,Method> class_methods;

    public:
    Class(std::string identifier){
        this->identifier = identifier;
        this->type = "CLASS";
        this->record_type = "CLASS";
    }

    void addVariable(std::string key, Variable value){
        class_variables.insert(std::pair<std::string, Variable>(key, value));
    }
    void addMethod(std::string key, Method value){
        class_methods.insert(std::pair<std::string, Method>(key, value));
    }
    std::map<std::string,Variable>::iterator lookupVariable(std::string key){
        this->class_variables.find(key);
    }
    std::map<std::string,Method>::iterator lookupMethod(std::string key){   
        this->class_methods.find(key); 
    }
};


class Scope {
    public:
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
};


#endif
