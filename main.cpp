#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>

#include "operations.hpp"

// Namespaces
using namespace std;
namespace fs = filesystem;

// Main Function
int main() {
    if (!fs::exists(getBaseDir())) {
    fs::create_directories(getBaseDir());
    }
    bool appRunning = true;
    cout<<"\n";
    cout<<"\033[1;36m";
        cout << "#==============  NOTES CPP  ==============#\n";
    cout<<"\033[0m"<<endl;
// Event Loop
    while(appRunning){
        int choice = 0;
        margin();
        cout << "|             \033[33mMAIN MENU\033[0m                  |\n";
        margin();
        cout << "| 1. Create New File                     |\n";
        cout << "| 2. Write File                          |\n";
        cout << "| 3. Read File                           |\n";
        cout << "| 4. List Files                          |\n";
        cout << "| 5. Delete File                         |\n";
        cout << "| 6. Exit                                |\n";
        margin();
        cout << "  Enter your choice: ";
        choice = getChoice();
        margin();
        string filename, text;
        
        switch(choice){
        case 1: 
            cout << "  Enter file name: ";
            getline(cin, filename);
            margin();
            createFile(filename);   
            break;

        case 2: 
            cout << "  Enter file name:  ";
            getline(cin, filename);
            margin();
            writeFile(filename);
            break;

        case 3: 
            cout << "  Enter file name:  ";
            getline(cin, filename);
            margin();
            readFile(filename);
            break;

        case 4: 
            listFiles();
            break;    

        case 5:
            cout << "  Enter file name:  ";
            getline(cin, filename);
            margin();
            deleteFile(filename);
            break;

        case 6:
            cout<<"  Thanks for using notes_cpp. Developer's Info: https://prasoonkandel.com/\n";
            appRunning = false;
            break;

        default:
            cout<<"\033[1;31m""  Invalid option\n""\033[0m";
        }}
    return 0;
}

// Secondary Functions
