//
// Created by dat tran on 04.03.21.
//

#include "List.h"

List::List()
{
    // Konstruktor für eine leere Liste
    head_tail = new Node;
    list_size = 0;
    temp = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

List::List(const List & _List)
{
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List.list_form;
    head_tail = new Node;
    list_size = 0;
    temp = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node * tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail)
    {
        head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

List::List(const List * _List)
{
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    list_form = _List->list_form;
    head_tail = new Node;
    list_size = 0;
    temp = _List->temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node * tmp_node;
    tmp_node = _List->head_tail->next;
    while (tmp_node != _List->head_tail)
    {
        head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

List::~List()
{
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
/*
	hier alle Knoten löschen, die im Objekt List allokiert wurden
*/

    //std::cout << "doi tuong dang bi xoa" << std::endl;
    Node * tmp = head_tail->next;
    while(tmp != head_tail){
        /*
        Node* tmp2 = tmp->next;
        delete tmp;
        tmp = tmp2;
        //*/
        tmp = tmp->next;
        delete tmp->prev;
        tmp->prev = nullptr;
    }
    delete head_tail;
    head_tail = nullptr;
    list_size = 0;
}

void List::insertFront(int key)
{

/*
	Einen neuen Knoten mit dem Schlüsselwert key am Anfang der Liste einfügen
*/
    // Einen neuen Knoten mit dem Schlüsselwert key erzeugen!
    Node * neu = new Node();
    neu->key = key;
    // Einfügen eines neuen Knotens am Anfang der Liste
    neu->next = head_tail->next;
    head_tail->next->prev = neu;
    head_tail->next = neu;
    neu->prev = head_tail;

    list_size++;
}

void List::insertFront(List & _List)
{
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
*/

    if (_List.size() != 0) { // _List ist nicht empty
        // Einfügen einer vorhandenen Liste am Anfang
        _List.head_tail->prev->next = head_tail->next;
        (head_tail->next)->prev = _List.head_tail->prev;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->next->prev = head_tail;

        // list_size aktuellisiert
        list_size += _List.size();

        // _List ist leer am Ende!
        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;
        _List.list_size = 0;
    }
}

void List::insertFront(List * _List)
{
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
*/

    if (_List->size() != 0) {   // _List ist nicht empty!
        // Einfügen einer vorhandenen Liste am Anfang
        _List->head_tail->prev->next = head_tail->next;
        (head_tail->next)->prev = _List->head_tail->prev;
        head_tail->next = _List->head_tail->next;
        _List->head_tail->next->prev = head_tail;

        // list_size aktuellisiert
        list_size += _List->size();

        // _List ist leer am Ende!
        _List->head_tail->next = _List->head_tail;
        _List->head_tail->prev = _List->head_tail;
        _List->list_size = 0;
    }
}

void List::insertBack(int key)
{
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Ende der Liste einfügen
*/
    // Einen neuen Knoten erzeugen
    Node * neu = new Node();
    neu->key = key;
    // Einfügen eines neuen Knotens am Ende der Liste
    (head_tail->prev)->next = neu;
    neu->prev = head_tail->prev;
    neu->next = head_tail;
    head_tail->prev = neu;

    list_size++;
}

void List::insertBack(List & _List)
{
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
*/
    if(_List.size() != 0){   //_List ist nicht leer!
        // Einfügen einer vorhandenen Liste am Ende
        (head_tail->prev)->next = _List.head_tail->next;
        (_List.head_tail->next)->prev = head_tail->prev;
        (_List.head_tail->prev)->next = head_tail;
        head_tail->prev = _List.head_tail->prev;

        // list_size aktuellisiert
        list_size += _List.size();

        // _List ist leer am Ende!
        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;
        _List.list_size = 0;
    }
}

void List::insertBack(List * _List)
{
    /*
    Die einzufügenden Knoten werden übernommen (nicht kopiert)
    Die einzufügende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
*/
    if(_List->size() != 0){   //_List ist nicht leer!
        // Einfügen einer vorhandenen Liste am Ende
        (head_tail->prev)->next = _List->head_tail->next;
        (_List->head_tail->next)->prev = head_tail->prev;
        (_List->head_tail->prev)->next = head_tail;
        head_tail->prev = _List->head_tail->prev;

        // list_size aktuellisiert
        list_size += _List->size();

        // _List ist leer am Ende!
        _List->head_tail->next = _List->head_tail;
        _List->head_tail->prev = _List->head_tail;
        _List->list_size = 0;
    }
}

bool List::getFront(int & key)
{
    /*
	Der Wert des vorderen Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
    */
    // LIST IST LEER!
    if(list_size == 0) return false;
    // LIST IST NICHT LEER!
    Node * tmp = head_tail->next;
    // entnehmen des Knotens am Anfang der Liste
    head_tail->next = tmp->next;
    (tmp->next)->prev = head_tail;
    // der Wert wird als Parameter zurückgegeben
    key = tmp->key;
    // der Knoten wird entnommen
    delete tmp;
    // update list_size
    list_size--;
    return true;
}

bool List::getBack(int & key)
{
/*
	Der Wert des letzten Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/
    // LIST IST LEER!
    if(list_size == 0) return false;

    // LIST IST NICHT LEER!
    Node * tmp = head_tail->prev;   // get the last node
    // entnehmen des Knotens am Ende der Liste
    head_tail->prev = tmp->prev;
    tmp->prev->next = head_tail;
    // der Wert wird als Parameter zurückgegeben
    key = tmp->key;
    // der Knoten wird entnommen
    delete tmp;
    // update list_size
    list_size--;
    return true;
}

bool List::del(int key)
{
    // Löschen eines gegebenen Knotens
/*
	Löschen des Knotens mit dem Schlüssel key
*/
    Node * tmp = head_tail->next;
    bool found = false;
    while(tmp != head_tail){
        if(tmp->key == key){
            found = true;
            break;
        }
        tmp = tmp->next;
    }
    if(found){
        // set pointer next and prev
        (tmp->prev)->next = tmp->next;
        (tmp->next)->prev = tmp->prev;
        // delete tmp
        delete tmp;
        // update list_size
        list_size--;
        return true;
    }
    return false;
}

bool List::search(int key)
{
    // suchen eines Knotens
/*
	suchen ob ein Knoten mit dem Schlüssel key existiert.
*/
    Node * tmp = head_tail->next;
    while(tmp != head_tail){
        if(tmp->key == key) return true;
        tmp = tmp->next;
    }
    return false;
}

bool List::swap(int key1, int key2)
{
    // Vertauschen von zwei Knoten
    // Dabei werden die Zeiger der Knoten und deren Nachbarn verändert.
/*
	Vertauschen von zwei Knoten mit dem key1 und dem key2
	Es dürfen nicht nur einfach die Schlüssel in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhängen.
*/
    // tìm 2 Knoten đầu tiên chứa key1 và key2, đi từ đầu dãy
    bool key1_found = false;
    bool key2_found = false;
    bool inOrder = false; // Xác định key1 hay key 2 được tìm ra đầu tiên
    Node* tmp = head_tail->next;
    Node* tmp1 = head_tail;
    Node* tmp2 = head_tail;
    while(tmp != head_tail){
        if(tmp->key == key1 && !key1_found){
            tmp1 = tmp;
            key1_found = true;
            if(!key2_found) inOrder = true; // key1 được tìm thấy đầu tiên
        }
        if(tmp->key == key2 && !key2_found){
            tmp2 = tmp;
            key2_found = true;
        }
        if(key1_found && key2_found) break;
        tmp = tmp->next;
    }
    // không tìm thấy một trong 2 key
    if(!key1_found || !key2_found) return false;

    // người dùng điền key không theo thứ tự, xác định lại thứ tự tmp1 và tmp2
    if(!inOrder){
        Node* swap = tmp2;
        tmp2 = tmp1;
        tmp1 = swap;
    }   // kết thúc: tmp1 luôn đứng trước tmp2

    // phân loại trường hợp
    if(tmp1->next == tmp2){
        // tmp1 và tmp2 kề nhau
        Node* prev_tmp1 = tmp1->prev;
        tmp1->prev->next = tmp2;
        tmp2->next->prev = tmp1;
        // đổi con trỏ next và prev của tmp1 và tmp2
        tmp1->next = tmp2->next;
        tmp1->prev = tmp2;
        tmp2->next = tmp1;
        tmp2->prev = prev_tmp1;
    }else{
        // tmp1 và tmp2 cách nhau
        // đổi con trỏ next và prev của Nodes trước, sau, giữa tmp1 và tmp2
        (tmp1->prev)->next = tmp2;
        (tmp1->next)->prev = tmp2;
        (tmp2->prev)->next = tmp1;
        (tmp2->next)->prev = tmp1;
        // đổi con trỏ next và prev của tmp1 và tmp2
        // lưu Nodes trước và sau tmp1 trước khi thay đổi
        Node* next_tmp1 = tmp1->next;
        Node* prev_tmp1 = tmp1->prev;
        // thay đổi
        tmp1->next = tmp2->next;
        tmp1->prev = tmp2->prev;
        tmp2->next = next_tmp1;
        tmp2->prev = prev_tmp1;
    }
    return true;
}

int List::size(void)
{
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/

    // Rückgabe der Knoten in der Liste mit O(1)
    return list_size;
}

bool List::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und zurück
    // Es werden dabei die Anzahl der Knoten gezählt.
    // Stimmt die Anzahl der Knoten überein liefert die Methode true
    Node * tmp = head_tail->next;
    int i_next = 0, i_prev = 0;
    while (tmp != head_tail) {
        tmp = tmp->next;
        if (i_next > list_size) return false;
        i_next++;
    }
    if (i_next != list_size) return false;
    tmp = head_tail->prev;
    while (tmp != head_tail) {
        tmp = tmp->prev;
        if (i_prev > list_size) return false;
        i_prev++;
    }
    return i_prev == i_next;
}

List & List::operator = (const List & _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == &_List) return *this;		//  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node * tmp_node;
    if (list_size)
    {
        Node * tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List.head_tail->next;		// Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.head_tail)
    {
        insertBack(tmp_node->key);
        tmp_node = tmp_node->next;
    }
    if (_List.temp) delete & _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
    return *this;
}

List & List::operator = (const List * _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
    // Kopiert wird in das Objekt "this"
    if (this == _List) return *this;		//  !! keine Aktion notwendig
    list_form = _List->list_form;
    Node * tmp_node;
    if (list_size)
    {
        Node * tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List->head_tail->next;
    while (tmp_node != _List->head_tail)	// Die Listen-Knotenwerte werden kopiert
    {
        insertBack(tmp_node->key);
        tmp_node = tmp_node->next;
    }
    if (_List->temp) delete _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
    return *this;
}

List & List::operator + (const List & List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node * tmp_node;
    List * tmp;
    if (temp) {										// this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else {
        tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
    }
    if (List_Append.list_size) {					// anhängen der übergebenen Liste an tmp
        tmp_node = List_Append.head_tail->next;
        while (tmp_node != List_Append.head_tail) {
            tmp->insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return *tmp;
}

List & List::operator + (const List * List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
    Node * tmp_node;
    List * tmp;
    if (temp) {										// this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else {
        tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
    }
    if (List_Append->list_size) {					// anhängen der übergebenen Liste an tmp
        tmp_node = List_Append->head_tail->next;
        while (tmp_node != List_Append->head_tail) {
            tmp->insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return *tmp;
}

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node * tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
    if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste->list_form.start;
    for (Node * tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
        stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
    if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
    return stream;
}
