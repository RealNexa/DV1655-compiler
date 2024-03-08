#ifndef C

#include <iostream>
#include <fstream>
#include "TAC.h"


void generate_tree(BBlock* entry_block) {
    std::ofstream outStream;
    char* filename = "CFG.dot";
    outStream.open(filename);

    outStream << "digraph {" << std::endl;
    outStream << "graph [splines=ortho]" << std::endl;
    outStream << "node [shape=box]" << std::endl;
    generate_tree_content(entry_block, &outStream);
    outStream << "}" << std::endl;
    outStream.close();
}

void generate_tree_content(BBlock* block, std::ofstream *outStream) {
    *outStream << block->name << " [label=\"" << block->name << "\"];" << std::endl;

    if (block->trueExit != nullptr) {
        *outStream << block->name << "->" << block->trueExit->name << " [xlabel=\"true""\"];" << std::endl;
        generate_tree_content(block->trueExit, outStream);
    }

    if (block->falseExit != nullptr) {
        *outStream << block->name << "->" << block->falseExit->name << " [xlabel=\"false""\"];" << std::endl;
        generate_tree_content(block->falseExit, outStream);
    }
}
