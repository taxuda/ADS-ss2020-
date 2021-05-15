/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"
#include <fstream>

#define ADD_MANUELL 1
#define ADD_CSV 2
#define DELETE 3
#define SEARCH 4
#define PRINT_PRE 5
#define PRINT_LEVEL 6
#define QUIT 7

using namespace std;
void print_menu(Tree &data);
void print_return_menu(Tree &data);
void print_add_manuell(Tree &data);
void print_add_csv(Tree &data);
void print_delete(Tree &data);
void print_search(Tree &data);
void print_all(Tree &data);
void print_levelorder(Tree &data);
void import_csv(Tree &data);


void print_menu(Tree &data){
    int command;
    cout << "====================================\n"
            << "1) Datensatz einfuegen, manuell\n"
            << "2) Datensatz einfuegen, CSV Datei\n"
            << "3) Datensatz loeschen\n"
            << "4) Suchen\n"
            << "5) Ausgabe in Preorder\n"
            << "6) Ausgabe in Levelorder\n"
            << "7) Beenden \n"
            << "?> ";
    while(!(cin >> command) || command < 1 || command > 7){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please retry your command! ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (command) {
        case ADD_MANUELL:
            print_add_manuell(data);
            break;
        case ADD_CSV:
            print_add_csv(data);
            break;
        case DELETE:
            print_delete(data);
            break;
        case SEARCH:
            print_search(data);
            break;
        case PRINT_PRE:
            print_all(data);
            break;
        case PRINT_LEVEL:
            print_levelorder(data);
            break;
        case QUIT:
            break;
    }
}

void print_return_menu(Tree &data){
    cout << "Press any key to return to menu! ";
    if(cin.get()){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        print_menu(data);
    }

}

void print_add_manuell(Tree &data){
    string name;
    int old, plz;
    double income;
    cout << "+ Bitte geben Sie die den Datensatz ein\n";
    cout << "Name ?> ";
    getline(cin, name);
    cout << "Alter ?> ";
    cin >> old;
    cout << "Einkommen ?> ";
    cin >> income;
    cout << "PLZ ?> ";
    cin >> plz;
    data.addNode(name, old, income, plz);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
    print_return_menu(data);
}

void print_add_csv(Tree &data){
    char ch;
    cout << "+ Moechten Sie die Daten aus der Datei \"ExportZielanalyse.csv\" importieren (j/n) ?> ";
    while(!(cin >> ch) || (ch != 'j' && ch != 'n')){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "+ Moechten Sie die Daten aus der Datei \"ExportZielanalyse.csv\" importieren (j/n) ?> ";
    }

    if(ch == 'j') import_csv(data);

    print_return_menu(data);
}

void print_search(Tree &data){
    string name;
    cout << "+ Bitte geben Sie den zu suchenden Datensatz an\n"
            <<"Name ?> ";
    getline(cin, name);

    cout << "+ Fundstellen: " << endl;
    if(!data.searchNode(name)) cout << "not found!" << endl;

    print_return_menu(data);
}

void print_delete(Tree &data){
    int pos;
    cout << "+ Bitte geben Sie den zu l ̈oschenden Datensatz an\n"
           << "PosID ?> ";
    cin >> pos;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //data.deleteNode(pos);
    print_return_menu(data);
}

void print_all(Tree &data){
    data.printAll();
    print_return_menu(data);
}

void print_levelorder(Tree &data){
    data.printLevelOrder();
    print_return_menu(data);
}

void import_csv(Tree &data){
    string line;
    fstream csv("/Users/dattran/Desktop/projects/ads(ss2020)/praktikum/prak02/bst/ExportZielanalyse.csv", ios::in);
    if(csv.fail()){
        cout << "Cannot open file!" << endl;
        return;
    }

    while(getline(csv, line)){
        string name, tmp;
        int old, plz;
        double income;
        int i = 0;
        // get name
        for(; i < line.size() && line[i] != ';'; i++){
            tmp += line[i];
        }
        name = tmp;
        tmp = "";
        // get old
        for(i = i + 1; i < line.size() && line[i] != ';'; i++){
            tmp += line[i];
        }
        old = stoi(tmp);
        tmp = "";
        // get income
        for(i = i + 1; i < line.size() && line[i] != ';'; i++){
            tmp += line[i];
        }
        income = stod(tmp);
        tmp = "";
        // get plz
        for(i = i + 1; i < line.size() && line[i] != ';'; i++){
            tmp += line[i];
        }
        plz = stoi(tmp);

        data.addNode(name, old, income, plz);
    }

    if(csv.eof()){
        csv.close();
        cout << "Daten wurden dem Baum hinzugefuegt." << endl;
        return;
    }
}

int main() {

	int result = Catch::Session().run();
	Tree data;
    print_menu(data);
	return 0;
}
