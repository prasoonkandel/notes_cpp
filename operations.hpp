#include <string>

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP


// Get Functions
bool fileExists();
std::string getBaseDir();
int getChoice();

// Margin

void margin();

// File operations
void createFile(std::string filename);
void writeFile(std::string filename);
void readFile(std::string filename);
void listFiles();


#endif