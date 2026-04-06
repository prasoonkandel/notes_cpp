#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
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
    cout<<"\033[36m";
    cout<<R"(
███╗   ██╗ ██████╗ ████████╗███████╗███████╗     ██████╗██████╗ ██████╗ 
████╗  ██║██╔═══██╗╚══██╔══╝██╔════╝██╔════╝    ██╔════╝██╔══██╗██╔══██╗
██╔██╗ ██║██║   ██║   ██║   █████╗  ███████╗    ██║     ██████╔╝██████╔╝
██║╚██╗██║██║   ██║   ██║   ██╔══╝  ╚════██║    ██║     ██╔═══╝ ██╔═══╝ 
██║ ╚████║╚██████╔╝   ██║   ███████╗███████║    ╚██████╗██║     ██║     
╚═╝  ╚═══╝ ╚═════╝    ╚═╝   ╚══════╝╚══════╝     ╚═════╝╚═╝     ╚═╝                                                                          
)";
    cout<<"\n"<<endl;
    cout<<"\033[0m";

    while(appRunning){
        int choice = 0;
    cout << "=====================================\n";
    cout << "|             \033[33mMAIN MENU\033[0m             |\n";
    cout << "=====================================\n";
    cout << "| 1. Create New File               |\n";
    cout << "| 2. Read File                     |\n";
    cout << "| 3. Write File                    |\n";
    cout << "| 4. List Files                    |\n";
    cout << "| 5. Exit                          |\n";
    cout << "=====================================\n";
    cout << "  Enter your choice: ";
    cin >> choice;
    cin.ignore();
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
            cout<<"  Coming Soon ";
            break;    

        case 5:
            cout<<"Bye!\n";
            appRunning = false;
            break;

        default:
            cout<<"  Invalid option\n";
        }}
    return 0;
}



string createFile(string filename){

    bool exists = fileExists(filename);

    if (exists){
        string message = "\033[31m""  File already exists.""\033[0m";
        return message;
        }

    ofstream file(BASE_DIR+filename);

    if(!file){
        string message = "\033[31m""  Can't create file.""\033[0m";
    }

    string message = "\033[32m""  File created successfully.""\033[0m";
    file.close();
    return message;

}

void listFiles(){


}