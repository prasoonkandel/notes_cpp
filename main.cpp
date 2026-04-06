#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>

#define BASE_DIR "./notes/"

// Namespaces
using namespace std;
namespace fs = filesystem;

bool fileExists(string filename){
    string path = BASE_DIR+filename;
    bool exists = std::filesystem::exists(path);
    return exists;
}

// Function Definations
int getChoice();
void createFile(string filename);
void listFiles();
void readFile(string filename);

// Main Function
int main() {
    if (!fs::exists(BASE_DIR)) {
    fs::create_directory(BASE_DIR);
    }

    bool appRunning = true;
    cout<<"\e[36m";
    cout<<R"(
███╗   ██╗ ██████╗ ████████╗███████╗███████╗     ██████╗██████╗ ██████╗ 
████╗  ██║██╔═══██╗╚══██╔══╝██╔════╝██╔════╝    ██╔════╝██╔══██╗██╔══██╗
██╔██╗ ██║██║   ██║   ██║   █████╗  ███████╗    ██║     ██████╔╝██████╔╝
██║╚██╗██║██║   ██║   ██║   ██╔══╝  ╚════██║    ██║     ██╔═══╝ ██╔═══╝ 
██║ ╚████║╚██████╔╝   ██║   ███████╗███████║    ╚██████╗██║     ██║     
╚═╝  ╚═══╝ ╚═════╝    ╚═╝   ╚══════╝╚══════╝     ╚═════╝╚═╝     ╚═╝                                                                          
)";
    cout<<"\n"<<endl;
    cout<<"\e[0m";


// Event Loop
    while(appRunning){
        int choice = 0;
        cout << "=====================================\n";
        cout << "|             \e[33mMAIN MENU\e[0m             |\n";
        cout << "=====================================\n";
        cout << "| 1. Create New File                |\n";
        cout << "| 2. Read File                      |\n";
        cout << "| 3. Write File                     |\n";
        cout << "| 4. List Files                     |\n";
        cout << "| 5. Exit                           |\n";
        cout << "=====================================\n";
        cout << "  Enter your choice: ";
        choice = getChoice();
        cout << "=====================================\n";
        string filename, text;
        
        switch(choice){
        case 1: 
            cout << "  Enter file name: ";
            getline(cin, filename);
            cout << "=====================================\n";
            createFile(filename);   
  			break;

        case 2: 
            cout << "  Enter file name:  ";
            getline(cin, filename);
            cout << "=====================================\n";
            readFile(filename);
        	break;

        case 3: 
            cout<<"  Coming Soon"<<endl;
       		break;

        case 4: 
            listFiles();
            break;    

        case 5:
            cout<<"Bye!\n";
            appRunning = false;
            break;

        default:
            cout<<"\e[1;31m""  Invalid option\n""\e[0m";
        }}
    return 0;
}

// Secondary Functions

int getChoice(){
    int choice = 0;
    if(cin>>choice) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = 0;
        return  choice;
    }
    return choice;
}
void createFile(string filename){

    bool exists = fileExists(filename);

    if (exists){
        cout << "\e[1;31m""  File already exists.""\e[0m"<<endl;
      }

    ofstream file(BASE_DIR+filename);

    if(!file){
        cout << "\e[1;31m""  Can't create file.""\e[0m"<<endl;
    }
    file.close();
    cout << "\e[1;32m""  File created successfully.""\e[0m"<<endl;
    
}

void readFile(string filename){
    bool exists = fileExists(filename);
    bool isEmpty = true;
    if (!exists){
        cout << "\e[1;31m""  File doesn't exist""\e[0m"<<endl;
    }
    else{
        string path = BASE_DIR+filename;
        ifstream file(path);
        string line;
        cout<<"\e[1m""File content: ""\e[0m"<<endl;
        while(getline(file, line)){
            isEmpty = false;
            cout<<line<<endl;
        }
        if(isEmpty){
            cout<<"\e[1;31m""(File is empty)""\e[0m"<<endl;
        }
        
        cout << "=====================================\n";
        cout << "\e[1;32m""  File Read successfully.""\e[0m"<<endl;
    }
    

}

void listFiles(){
    string path = BASE_DIR;
    if(fs::is_empty(path)){
        cout<<"There are no files saved.";
    }
    else{
        cout<<"Listing Files:"<<endl;
        for(const auto &entry : fs::directory_iterator(path)){
            if(fs::is_regular_file(entry.status())){
                cout<<"File: "<<entry.path().filename()<<endl;
            }
            else if(fs::is_directory(entry.status())){
                cout<<"Folder: "<<entry.path().filename()<<endl;
            }
        } 
        string dummy;
        cout << "\nPress Enter to continue...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, dummy);
    }
}