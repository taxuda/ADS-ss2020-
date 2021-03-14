/*************************************************
* ADS Praktikum 1.1
* Unit-Testdatei
* Änderungen fürs Praktikum untersagt!
*************************************************/
#include "catch.hpp"
#include "List.h"
#include "Node.h"
#include <string>

using namespace std;

// Friend-Methode fuer Testroutine
Node* get_anker(List& l) {
    return l.head_tail;
}

int get_AnzahlNodes(List& l) {
    return l.list_size;
}

TEST_CASE("List Testing", "[List]") {

    List test_list;
    List second;

    SECTION("Hinzufuegen und Suche von Nodes - simple") {
        test_list.insertFront(5);
        test_list.insertFront(7);

        test_list.insertBack(9);
        test_list.insertBack(4);

        REQUIRE(test_list.size() == 4);

        REQUIRE(test_list.search(7) == true);
        REQUIRE(test_list.search(8) == false);
        REQUIRE(test_list.search(3) == false);
        REQUIRE(test_list.search(9) == true);

        int value;
        test_list.getBack(value);
        REQUIRE(value == 4);
        test_list.getFront(value);
        REQUIRE(value == 7);
    }

    SECTION("Hinzufuegen von Nodes aus zweiter Liste am Ende") {
        test_list.insertFront(5);
        test_list.insertFront(7);

        test_list.insertBack(9);
        test_list.insertBack(4);

        second.insertFront(5);
        second.insertFront(5);

        second.insertBack(5);
        second.insertBack(5);

        test_list.insertBack(second);

        REQUIRE(test_list.size() == 8);
        REQUIRE(test_list.test() == true);
    }

    SECTION("Hinzufuegen von Nodes aus zweiter Liste am Ende") {
        test_list.insertFront(5);
        test_list.insertFront(7);

        test_list.insertBack(9);

        second.insertFront(55);
        second.insertFront(57);
        second.insertBack(59);

        Node* test1;
        vector<Node*> test1_p, test2_p;
        test1 = get_anker(test_list)->next;
        for (int i = 0; i < test_list.size();i++) {
            test1_p.push_back(test1);
            test1 = test1->next;
        }
        test1 = get_anker(second)->next;
        for (int i = 0; i < second.size(); i++) {
            test1_p.push_back(test1);
            test1 = test1->next;
        }

        test_list.insertBack(second);

        test1 = get_anker(test_list)->next;
        for (int i = 0; i < test_list.size(); i++) {
            REQUIRE(test1->key == test1_p[i]->key);		// value stimmt
            REQUIRE(test1 == test1_p[i]);					// Pointer stimmt
            test1 = test1->next;
        }


        REQUIRE(test_list.size() == 6);

        Node* tmp = get_anker(test_list);
        tmp = tmp->next;
        int value = tmp->key;
        REQUIRE(value == 7);

        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 5);

        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 9);

        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 57);

        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 55);

        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 59);

        for (int i = 0; i < 6; i++)
            tmp = tmp->prev;

        //head_tail wieder erreicht
        value = tmp->key;
        REQUIRE(value == 0);
    }

    SECTION("Hinzufuegen und Loeschen von Nodes - simpel") {
        test_list.insertFront(5);
        test_list.insertFront(7);
        test_list.insertFront(9);
        test_list.insertFront(4);

        test_list.insertBack(3);
        test_list.insertBack(2);
        test_list.insertBack(4);
        test_list.insertBack(1);

        REQUIRE(test_list.size() == 8);

        REQUIRE(test_list.del(8) == false);
        REQUIRE(test_list.del(4) == true);
        REQUIRE(test_list.del(1) == true);
        REQUIRE(test_list.del(5) == true);

        REQUIRE(test_list.size() == 5);

        int value;
        test_list.getBack(value);
        REQUIRE(value == 4);
        test_list.getFront(value);
        REQUIRE(value == 9);
    }

    SECTION("Vertauschen von zwei Elementen und testen der Zeiger") {
        test_list.insertFront(5);
        Node* fuenf = get_anker(test_list)->next;	// Zeiger auf 5 merken
        test_list.insertFront(7);
        Node* sieben = get_anker(test_list)->next;	// Zeiger auf 7 merken
        test_list.insertFront(9);
        test_list.insertFront(4);
        Node* vier = get_anker(test_list)->next;	// Zeiger auf 4 merken

        test_list.insertBack(3);
        test_list.insertBack(2);
        Node* zwei = get_anker(test_list)->prev;	// Zeiger auf 2 merken
        test_list.insertBack(4);
        test_list.insertBack(1);

        REQUIRE(test_list.size() == 8);
        //////////////////////////////////////////////////////////////
        //Fall 1: Zwei Knoten aus der Mitte, nicht nebeneinander	//
        //////////////////////////////////////////////////////////////
        REQUIRE(test_list.swap(7, 2) == true);
        Node* tmp = get_anker(test_list);
        //prüfe ob 2 an neuem Platz
        for (int i = 0; i < 3; i++)
            tmp = tmp->next;
        int value = tmp->key;
        REQUIRE(tmp == zwei);
        REQUIRE(value == 2);
        //Prüfe ob 7 an neuem Platz
        for (int i = 0; i < 3; i++)
            tmp = tmp->next;
        value = tmp->key;
        REQUIRE(tmp == sieben);
        REQUIRE(value == 7);
        tmp = tmp->next;
        //Prüfe ob Anker wieder erreichbar
        for (int i = 0; i < 7; i++)
            tmp = tmp->prev;
        value = tmp->key;
        REQUIRE(value == 0);

        //////////////////////////////////////////////////////////////////////////
        //Fall 2: Erster Knoten mit einem aus der Mitte, nicht nebeneinander	//
        //////////////////////////////////////////////////////////////////////////
        REQUIRE(test_list.swap(4, 5) == true);
        tmp = tmp->next;
        //Prüfe ob neuer erster richtig
        value = tmp->key;
        REQUIRE(tmp == fuenf);
        REQUIRE(value == 5);
        //Prüfe ob 4 an neuem Platz
        for (int i = 0; i < 3; i++)
            tmp = tmp->next;
        value = tmp->key;
        REQUIRE(tmp == vier);
        REQUIRE(value == 4);
        tmp = tmp->next;
        //Prüfe ob Anker wieder erreichbar
        for (int i = 0; i < 5; i++)
            tmp = tmp->prev;
        value = tmp->key;
        REQUIRE(value == 0);

        //////////////////////////////////////////////////////////////////////////
        //Fall 3: Letzter Knoten mit einem aus der Mitte, nicht nebeneinander	//
        //////////////////////////////////////////////////////////////////////////
        REQUIRE(test_list.swap(1, 3) == true);
        for(int i = 0; i < 5; i++)
            tmp = tmp->next;
        //Prüfe ob 1 an neuem Platz
        value = tmp->key;
        REQUIRE(value == 1);
        //Prüfe ob neuer letzter richtig
        for (int i = 0; i < 3; i++)
            tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 3);
        tmp = tmp->next;
        //Prüfe ob Anker wieder erreichbar
        for (int i = 0; i < 9; i++)
            tmp = tmp->prev;
        value = tmp->key;
        REQUIRE(value == 0);

        //////////////////////////////////////////////////////
        //Fall 4: Zwei Knoten aus der Mitte, nebeneinander	//
        //////////////////////////////////////////////////////
        REQUIRE(test_list.swap(4, 2) == true);
        for (int i = 0; i < 3; i++)
            tmp = tmp->next;
        //Prüfe ob 4 an neuem Platz
        value = tmp->key;
        REQUIRE(value == 4);
        //Prüfe ob 1 an neuem Platz
        tmp = tmp->next;
        value = tmp->key;
        REQUIRE(value == 2);
        tmp = tmp->next;
        //Prüfe ob Anker wieder erreichbar
        for (int i = 0; i < 5; i++)
            tmp = tmp->prev;
        value = tmp->key;
        REQUIRE(value == 0);
    }
}