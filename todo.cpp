#include<bits/stdc++.h>
#include"nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

using namespace std;
string addTask(string task);
void showTask();
void removeTask();
json j;

int main(){

    char command {};

    do {
        cout << "\n ........................ " << "\n";
        cout << "1. Add Task" << "\n";
        cout << "2. Show all Tasks" << "\n";
        cout << "3. Remove all tasks" << "\n";
        cout << "4. Load your JSON file and Show all your tasks (WIP)" << "\n";
        cout << "Q. Quit? ";
        cout << "\n ........................ " << "\n";
        cout << "Enter your command " << "\n";

        cin >> command;

        if(command == '1'){
            string task {};
            cin >> task;
            addTask(task);
        }
        else if (command == '2') showTask();
        else if (command == '3') removeTask();
        else if (command == 'Q' || command == 'q') cout << "Come again later!" << "\n";
        else cout << "unknown option ... try again " << "\n";
        } while (command != 'q' && command != 'Q');

    return 0;
}

string addTask(string task){
    if (task.empty()) return "";
    else j.push_back(task);
    cout << "Task added " << "\n";
    return task;
}

void showTask(){
    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        std::cout << *it << '\n';
    }
}

void removeTask(){
    j.clear();
}
