// #include "AsmLoader.hpp"
// #include <fstream>
// #include <string>
// #include <cmath>

// AsmLoader::AsmLoader(Asm stackMachine) {
//     this->stackMachine = stackMachine;
//     this->iptr = 0;
//     this->dptr = 0;
// } 

// vector<string> AsmLoader::readFile(fs::path asmFile) {
//     vector<string> lines;
    
//     ifstream source;
//     source.open(asmFile);
//     if(source.is_open()) {
//         string line;
//         while(getline(source, line)) {
//             lines.push_back(line);
//         }
//     }

//     return lines;
// }

// void AsmLoader::load(fs::path asmFile) {
//     vector<string> lines = readFile(asmFile);
    
//     string line;
//     for(int i = 0; i < lines.size(); i++) {
//         line = lines[i];

//         ASMOperation operation = parseLine(line);
//         //stackMachine.insertOperation(operation, iptr);
//         iptr++;
//         if(operation.getOpcode() == Opcode::DLabel) {
//             symbolTable.insert(std::any_cast<std::string>(operation.getValue()), dptr);
//             cout << "ST: " << symbolTable.toString() << endl;
//         }
//         cout << operation.toString() << endl;
//     }
// }

// ASMOperation AsmLoader::parseLine(string line) {
//     vector<string> v = tokenize(line);
//     if(v.size() > 2) {
//         ASMOperation operation(Opcode::Error);
//         return operation;
//     }

//     Opcode op = OpcodeTools::getOpcode(v[0]);
   
//     if(v.size() == 1) {
//         ASMOperation operation(op);
//         return operation;
//     }

//     any value = parseValue(v[1]);
//     ASMOperation operation(op, value);
//     return operation;
// }

// vector<string> AsmLoader::tokenize(string line) {
//     vector<string> v;
    
//     string acc = "";
//     char currentChar = line[0];
//     for(int i = 0; i <= line.size(); i++) {
//         currentChar = line[i];
//         if(std::isspace(currentChar) || currentChar == '\0') {
//             if(acc.size() > 0) {
//                 v.push_back(acc);
//             }

//             if(currentChar == '\0') {
//                 break;
//             }

//             acc = "";
//             continue;
//         }

//         acc += currentChar;
//     }

//     return v;
// }

// any AsmLoader::parseValue(string value) {
//     try {
//         size_t pos = 0;
//         int iValue = std::stoi(value, &pos);
        
//         if(pos < value.size() && value[pos] == '.') {
//             float fValue = std::stof(value, &pos);
            
//             if(pos < value.size()) {
//                 return value;
//             }

//             return fValue;
//         }

//         return iValue;
//     } catch(const std::invalid_argument &ex) {
//         return value;
//     } catch(const std::out_of_range &ex) {
//         return value;
//     }
// }