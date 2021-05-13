#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    AVLTree mytree;
    for(int i = 0; i < 10; i++){
        mytree.insertNode(mytree.root, i);
    }
    if(!mytree.searchNode(10)){
        cout << "10 not found!" << endl;
    }
    if(mytree.searchNode(6)){
        cout << "6 is found!" << endl;
    }

    mytree.print_levelorder();
    return 0;
}
