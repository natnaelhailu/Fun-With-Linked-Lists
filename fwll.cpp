/*
*Written by: natizgr8
*Description: This program accepts two integers (n and k)
*             from the user, creates a linked list of size
*             n, reverses the list k number of nodes at
*             a time and displays the reversed list. 
*Input: n: size of the list
        k: number of nodes to be reversed at a time
*Output: data of the reversed list.
*/

#include <iostream>
#include "fwll.hpp"

int main()
{
    int n;    		  // total number of nodes
    int k;    		  // number of nodes to reverse
    LL<int> list;         // an empty linked list

    while(true) {
        // prompt user for input & validate that it is of type int
        while(std::cout << "Enter n and k: " && !(std::cin >> n >> k)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // validate range of input values
        if(n < 0 || k <= 0 || k > n) {
            continue;
        }
        else {
            break;
        }
    }

    // initialize the linked list
    for(auto value = 1; value <= n; value++) {
        list.add(value);
    }

    // display initialized list
    std::cout << "Original List:\n";
    std::cout << list << std::endl;

    // reverse list
    list.reverseKLists(k);

    // display reversed list
    std::cout << "Reversed List:\n";
    std::cout << list << std::endl;

    return 0;
}

/* EOF */


