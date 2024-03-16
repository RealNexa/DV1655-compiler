#ifndef GENCODE_H
#define GENCODE_H

#include "TAC.h"
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <map>

void traverse_cfg(BBlock* current_block, std::ofstream* outStream, std::list<std::string>& visited_blocks, ProgramData* program_data){
    
    if (find(visited_blocks.begin(), visited_blocks.end(), current_block->name) != visited_blocks.end()) {
        return;
    }

    *outStream << current_block->name << std::endl;
    visited_blocks.push_back(current_block->name);

    for(auto it = current_block->tacInstructions.begin(); it != current_block->tacInstructions.end(); it++){
        (*it)->genByteCode(outStream, program_data);
    }

    if(current_block->trueExit != nullptr && current_block->falseExit == nullptr){
        UnconditionalJump(current_block->trueExit->name).genByteCode(outStream, program_data);        
    }

    if(current_block->trueExit != nullptr){
        traverse_cfg(current_block->trueExit, outStream, visited_blocks, program_data);
    }

    if(current_block->falseExit != nullptr){
        traverse_cfg(current_block->falseExit, outStream, visited_blocks, program_data);
    }
}

void traverse_entry_blocks(){
    std::ofstream outStream;
    char* filename = "instructions.bc";
    outStream.open(filename);
    std::list<std::string> visited_blocks = {};
    ProgramData program_data;
    
    for(auto it = BBlock::method_blocks.begin(); it != BBlock::method_blocks.end(); it++) {
        program_data.current_row = 0;
        traverse_cfg(*it, &outStream, visited_blocks, &program_data);
    }
    outStream.close();
}

#endif