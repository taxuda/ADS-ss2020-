//
// Created by dat tran on 11.05.21.
//

#include "print.h"

void print_menu(Ring &r){
    bool open = true;
    int command;
    std::cout << "\n\n\n OneRingToRuleThemAll v0.1, by Sauron Schmidt \n"
              << "==================================\n"
              << "1) Backup einfuegen\n"
              << "2) Backup suchen\n"
              << "3) Alle Backups ausgeben\n"
              << "4) Beenden \n"
              << "?> ";

    std::cin >> command;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (command) {
        case COMMAND_ADD:
            print_add(r);
            break;
        case COMMAND_SEARCH:
            print_search(r);
            break;
        case COMMAND_PRINT:
            r.print();
            print_goback(r);
            break;
        case COMMAND_QUIT:
            break;
    }
}

void print_add(Ring &r){
    std::string descr, data;
    std::cout << "+Neuen Datensatz einfuegen\n"
            << "Beschreibung ?> ";
    std::getline(std::cin, descr);
    std::cout<<"Daten ?> ";
    std::getline(std::cin, data);
    r.addNode(descr,data);
    std::cout<<"+Ihr Datensatz wurde hinzugefuegt." << std::endl;

    print_goback(r);
}

void print_search(Ring &r){
    std::string text;
    std::cout << "+Nach welchen Daten soll gesucht werden?" << std::endl
            << "?> ";
    std::getline(std::cin, text);
    r.search(text);

    print_goback(r);
}

void print_goback(Ring &r){
    char command;
    do{
        std::cout << "press y to go back ";
        std::cin >> command;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(command != 'y');
    print_menu(r);
}