#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>
#include <vector>

// Including Operations Header File
#include "operations.hpp"

// Namespaces
using namespace std;
namespace fs = filesystem;


// Get Functions
bool fileExists(string filename){
    string path = getBaseDir()+filename;
    bool exists = fs::exists(path);
    return exists;
}

string getBaseDir(){

    #ifdef _WIN32 
        return string(getenv("USERPROFILE")) + "\\notes_cpp\\";
    #else 
        return string(getenv("HOME")) + "/notes_cpp/";

    #endif  

}

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

// Margin 
void margin(){
    cout << "==========================================\n";
}

//File Operations
void createFile(string filename){
    if(filename == ""){
        cout <<"\033[1;31m"" Name of the file can't be empty.""\033[0m"<<endl;
        return;
    }

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


void writeFile(string filename){

    if(filename == ""){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }

    bool exists = fileExists(filename);
    if(!exists){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }
    cout<<"  This program doesn't support editing file"<<endl;
    cout<<"  Do you want to overwrite it? (y/n): ";
    char *yn_ptr = new char;
    cin>>*yn_ptr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    margin();
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
            cout<<line_no<<" ";
            getline(cin, *temp_line);
            if(*temp_line == "END" || *temp_line == "end"){
                writting = false;
                break;
            }
            file<<*temp_line<<endl;
            line_no++;
        }
        delete temp_line;
        file.close();
        margin();
        cout<< "\033[1;32m""  File overwritten successfully.""\033[0m"<<endl; 
    }
    else if(*yn_ptr == 'n' || *yn_ptr == 'N'){
        cout<< "\033[1;32m""  File saved without any changes""\033[0m"<<endl; 
    }
    else{
        cout <<"\033[1;31m""  Invalid Input""\033[0m"<<endl;
    }

    delete yn_ptr;
}

void readFile(string filename){
    if(filename == ""){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }
    bool exists = fileExists(filename);
    bool isEmpty = true;
    if (!exists){
        cout << "\033[1;31m""  File doesn't exist""\033[0m"<<endl;
        return;
    }

    string path = getBaseDir()+filename;
    ifstream file(path);
    string line;
    int line_no = 1;
    while(getline(file, line)){
        if(isEmpty){
            cout<<"\033[1m""File content: ""\033[0m"<<endl;
            isEmpty = false;
        }
        cout<<line_no<<" ";
        cout<<line<<endl;
        line_no++;
    }
    if(isEmpty){
        cout<<"\033[1;31m""(File is empty)""\033[0m"<<endl;
        return;
    }
    margin();
    cout << "\033[1;32m""  File Read successfully.""\033[0m"<<endl;
 
    

}

void editFile(string filename){
    if (filename ==  ""){
        cout<<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
 
        return;
    }

    bool exists = fileExists(filename);

    if(!exists){
        cout<<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }
    string path = getBaseDir() + filename;
    ifstream file(path);
    bool isEmpty = true;
    vector<string> file_content;
    string line;
    int line_no = 1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(getline(file, line)){
        if(isEmpty){
            cout<<"\033[1m""File content: ""\033[0m"<<endl;
            isEmpty = false;
        }
        file_content.push_back(line);

        cout<<line_no<<" ";
        cout<<line<<endl;
        line_no++;
    }
    
    if(isEmpty){
        cout<<"\033[1;31m""  (File is empty)""\033[0m"<<endl;
        return;
    }

    file.close();

    margin();
    
    int choice;
    cout<<"  Enter the line number to edit: ";

    while(!(cin>>choice)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\033[1;31m""  Invalid Input (Must be a number)""\033[0m"<<endl;
        cout<<"  Enter the line number to edit: ";
    }

    if(choice<=0 || choice > file_content.size()){
        cout<<"\033[1;31m""  Line "<<choice<<" doesn't exist""\033[0m"<<endl;
        return;
    }

    string old_content = file_content[choice-1];

    cout<<endl;
    cout<<"  Old content: "<<endl;
    cout<<"  "<<old_content<<endl;
    cout<<endl;
    cout<<"  New content: "<<endl;
    cout<<"  ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, file_content[choice-1]);

    if(file_content[choice-1] == ""){
        file_content.erase(file_content.begin() + (choice - 1));
    }

    margin();
                                                                                                                                                                                                         
    ofstream file_write(path);

    for(int i = 0; i<file_content.size(); i++){
        file_write<<file_content[i]<<endl;
    }

    cout<<"\033[1;32m""  File edited successfully.""\033[0m"<<endl;
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

void deleteFile(string filename){
    if(filename == ""){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }
    bool exists = fileExists(filename);

    if(!exists){
        cout <<"\033[1;31m""  File doesn't exist.""\033[0m"<<endl;
        return;
    }

    string path = getBaseDir() + filename;

    if(fs::remove(path)){
        cout <<"\033[1;32m""  File deleted successfully.""\033[0m"<<endl;
    }
    else{
        cout <<"\033[1;31m""  Unexpected error occurred""\033[0m"<<endl;
    }

}