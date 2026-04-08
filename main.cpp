#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>

// Namespaces
using namespace std;
namespace fs = filesystem;

// Getting Base Directory to store notes
string getBaseDir() {
    #ifdef _WIN32
        return string(getenv("USERPROFILE")) + "\\notes_cpp\\";
    #else
        return string(getenv("HOME")) + "/notes_cpp/";
    #endif
}

bool fileExists(string filename){
    string path = getBaseDir()+filename;
    bool exists = fs::exists(path);
    return exists;
}


// Function Definations
int getChoice();
void createFile(string filename);
void listFiles();
void readFile(string filename);
void writeFile(string filenme);
// Main Function
int main() {
    if (!fs::exists(getBaseDir())) {
    fs::create_directories(getBaseDir());
    }
    bool appRunning = true;
    cout<<"\n";
    cout<<"\033[1;36m";
        cout << "#===============  NOTES CPP  ===============#\n";
    cout<<"\033[0m"<<endl;
// Event Loop
    while(appRunning){
        int choice = 0;
        cout << "==========================================\n";
        cout << "|             \033[33mMAIN MENU\033[0m                  |\n";
        cout << "==========================================\n";
        cout << "| 1. Create New File                     |\n";
        cout << "| 2. Write File                          |\n";
        cout << "| 3. Read File                           |\n";
        cout << "| 4. List Files                          |\n";
        cout << "| 5. Exit                                |\n";
        cout << "==========================================\n";
        cout << "  Enter your choice: ";
        choice = getChoice();
        cout << "==========================================\n";
        string filename, text;
        
        switch(choice){
        case 1: 
            cout << "  Enter file name: ";
            getline(cin, filename);
            cout << "==========================================\n";
            createFile(filename);   
  			break;

        case 2: 
            cout << "  Enter file name:  ";
            getline(cin, filename);
            cout << "==========================================\n";
            writeFile(filename);
        	break;

        case 3: 
            cout << "  Enter file name:  ";
            getline(cin, filename);
            cout << "==========================================\n";
            readFile(filename);
       		break;

        case 4: 
            listFiles();
            break;    

        case 5:
            cout<<"Bye!\n";
            appRunning = false;
            break;

        default:
            cout<<"\033[1;31m""  Invalid option\n""\033[0m";
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
        cout << "\033[1;31m""  File already exists.""\033[0m"<<endl;
    }
    else{
        ofstream file(getBaseDir()+filename);
        if(!file){
        cout << "\033[1;31m""  Can't create file.""\033[0m"<<endl;
        }
        else{
        file.close();
        cout << "\033[1;32m""  File created successfully.""\033[0m"<<endl;
        }   
    }
}

void readFile(string filename){
    bool exists = fileExists(filename);
    bool isEmpty = true;
    if (!exists){
        cout << "\033[1;31m""  File doesn't exist""\033[0m"<<endl;
    }
    else{
        string path = getBaseDir()+filename;
        ifstream file(path);
        string line;
        cout<<"\033[1m""File content: ""\033[0m"<<endl;
        int line_no = 1;
        while(getline(file, line)){
            isEmpty = false;
            cout<<line_no<<" ";
            cout<<line<<endl;
            line_no++;
        }
        if(isEmpty){
            cout<<"\033[1;31m""(File is empty)""\033[0m"<<endl;
        }

        cout << "==========================================\n";
        cout << "\033[1;32m""  File Read successfully.""\033[0m"<<endl;
    }
    

}

void writeFile(string filename){
    bool exists = fileExists(filename);
    if(!exists){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }
    cout<<"  This program doesn't support editing file"<<endl;
    cout<<"  Do you want to overwrite it? (y/n): ";
    char *yn_ptr = new char;
    cin>>*yn_ptr;
    cout << "==========================================\n";
    if (*yn_ptr == 'y' || *yn_ptr == 'Y'){
        string path = getBaseDir()+filename;
        ofstream file(path);
        if (!file){
            cout <<"\033[1;31m""  Unexpected error occured""\033[0m"<<endl;
            return;
        }
        cout<< "  Write File content here (END for exit): "<<endl;
        bool writting = true;
        string *temp_line = new string;
        int line_no = 1;
        while(writting){
            
            getline(cin, *temp_line);
            if(*temp_line == "END" || *temp_line == "end"){
                writting = false;
                break;
            }
            cout<<line_no<<" ";
            file<<*temp_line<<endl;
            line_no++;
        }
        delete temp_line;
        file.close();
    }
    else if(*yn_ptr == 'n' || *yn_ptr == 'N'){
        cout<< "\033[1;32m""  File saved without any changes""\033[0m"<<endl; 
    }
    else{
        cout <<"\033[1;31m""  Invalid Input""\033[0m"<<endl;
    }

    delete yn_ptr;
}

void listFiles(){
    string path = getBaseDir();
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