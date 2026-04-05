#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
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
    cout<<"\033[0m";

    while(appRunning){
        int choice = 0;

        cout<<"\n============================\n";
        cout<<"1. Create New File\n";
        cout<<"2. Read File\n";
        cout<<"3. Write File\n";
        cout<<"4. List Files\n";
        cout<<"5. Exit \n";
        cout<<"============================\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string filename, text;

        switch(choice){
        case 1: 
            cout<<"Enter file name: ";
  			break;

        case 2: 
            cout<<"Enter file name: ";
        	break;

        case 3: 
            cout<<"Enter file name: ";
       		break;

        case 4:
            cout<<"Bye!\n";
            appRunning = false;
            break;

        default:
            cout<<"Invalid option\n";
        }}
    return 0;
}