#ifndef CFG_H
#define CFG_H

#include <iostream>
#include <fstream>
#include <list>
#include "TAC.h"

void generate_CFG_content(BBlock* block, std::ofstream *outStream, std::list<std::string>& visited_nodes) {

    if (find(visited_nodes.begin(), visited_nodes.end(), block->name) != visited_nodes.end()) {
        return;
    }
    visited_nodes.push_back(block->name);
    
    *outStream << block->name << " [label=\"" << block->name << "\\n\\n" << block->get_print_string() << "\"];" << std::endl;


    if (block->trueExit != nullptr) {
        *outStream << block->name << "->" << block->trueExit->name << " [xlabel=\"true""\"];" << std::endl;
        generate_CFG_content(block->trueExit, outStream, visited_nodes);
    }

    if (block->falseExit != nullptr) {
        *outStream << block->name << "->" << block->falseExit->name << " [xlabel=\"false""\"];" << std::endl;
        generate_CFG_content(block->falseExit, outStream, visited_nodes);
    }
}

void generate_CFG() {
    std::ofstream outStream;
    char* filename = "CFG.dot";
    std::list<std::string> visited_blocks = {};
    outStream.open(filename);
    outStream << "digraph {" << std::endl;
    outStream << "graph [splines=ortho]" << std::endl;
    outStream << "node [shape=box]" << std::endl;

    for(auto it = BBlock::method_blocks.begin(); it != BBlock::method_blocks.end(); it++){
        generate_CFG_content(*it, &outStream, visited_blocks);
    }

    outStream << "}" << std::endl;
    outStream.close();
}

#endif