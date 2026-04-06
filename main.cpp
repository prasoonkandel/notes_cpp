#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>

#define BASE_DIR "./notes/"
using namespace std;
namespace fs = filesystem;

bool fileExists(string filename){
    string path = BASE_DIR+filename;
    bool exists = std::filesystem::exists(path);
    return exists;
}


string createFile(string filename);
void listFiles();
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

    while(appRunning){
        int choice = 0;
    cout << "=====================================\n";
    cout << "|             \e[33mMAIN MENU\e[0m             |\n";
    cout << "=====================================\n";
    cout << "| 1. Create New File               |\n";
    cout << "| 2. Read File                     |\n";
    cout << "| 3. Write File                    |\n";
    cout << "| 4. List Files                    |\n";
    cout << "| 5. Exit                          |\n";
    cout << "=====================================\n";
    cout << "  Enter your choice: ";
    cin>>choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "=====================================\n";
        string filename, text;

        switch(choice){
        case 1: 
            cout << "  Enter file name: ";
            getline(cin, filename);
            cout << "=====================================\n";
            cout<<createFile(filename)<<endl;    
  			break;

        case 2: 
            cout<<"  Coming Soon ";
        	break;

        case 3: 
            cout<<"  Coming Soon ";
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



string createFile(string filename){

    bool exists = fileExists(filename);

    if (exists){
        string message = "\e[31m""  File already exists.""\e[0m";
        return message;
        }

    ofstream file(BASE_DIR+filename);

    if(!file){
        string message = "\e[31m""  Can't create file.""\e[0m";
    }

    string message = "\e[32m""  File created successfully.""\e[0m";
    file.close();
    return message;

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