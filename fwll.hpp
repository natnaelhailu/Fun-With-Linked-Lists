#ifndef FWLL_HPP_
#define FWLL_HPP_

#include <iostream>

// prototypes
template <typename type> class LL;
template <typename type1>
std::ostream& operator<<(std::ostream&, const LL<type1>&);

/*
* LL: Implementation of a doubly linked list
* constructors: LL<type>::LL()
* public functions: void reverseKLists(int)
*                   void add(const type&)
*                   std::ostream& operator<<(std::ostream&, const LL<type1>&)
*/
template <typename type>
class LL
{
    struct node
    {
        type data;
        node *next;
        node *prev;
    };

public:
    LL();
    ~LL();

    void reverseKLists(int);
    void add(const type&);

    template <typename type1>
    friend std::ostream& operator<<(std::ostream&, const LL<type1>&);

private:
    void reverse(LL<type>::node*&, LL<type>::node *&);
    node *head;
    node *tail;
};

/*
* constructor for LL class
*/
template <typename type>
LL<type>::LL() {
    head = NULL;
    tail = NULL;
}

/*
* destructor for LL class
*/
template <typename type>
LL<type>::~LL() {
    node *temp;
    while(head != NULL) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

/*
* reverseKLists: passes the left and right most node pointers of a
*                doubly linked list to 'reverse' function, k nodes at a
*                time.
* parameters: k: number of nodes to be reversed.
*/
template <typename type>
void LL<type>::reverseKLists(int k) {
    node *l_end = head;            // left end pointer to sublist
    node *r_end = head;            // right end pointer to sublist
    auto sublist = 1;              // # of qualified sublists reversed

    for( ; l_end != NULL; sublist++) {
        // initialize r_end for each sublist
        while(r_end->data != k*sublist && r_end->next != NULL) {
            r_end = r_end->next;
        }

        // reverse only sublists of size k
        if(r_end->data-l_end->data == k-1) {
            reverse(l_end, r_end);
        }

        l_end = r_end->next;
    }
}

/*
* add: pushes a node of data 'item' at the end a list.
* parameters: item: the data of the new node to be added.
*/
template <typename type>
void LL<type>::add(const type& item) {
    node *new_node = new node;	// a new node to be added

    // update new node properties
    new_node->data = item;
    new_node->next = NULL;

    // if list is empty, make new_node the head
    if(head == NULL) {
        head = new_node;
        new_node->prev = NULL;
    }

    // If it isn't, append new_node to list
    else {
        new_node->prev = tail;
        tail->next = new_node;
    }

    // make newly appended node the tail
    tail = new_node;
}

/*
* reverse: reverses all the nodes between 'leftEndPoint'
*          and 'rightEndPoint' of a doubly linked list
*          in decreasing order.
* parameters: leftEndPoint: beginning of nodes to be reversed
*             rightEndPoint: end of nodes to be reversed
*/
template <typename type>
void LL<type>::reverse(LL<type>::node*& leftEndPoint, LL<type>::node*& rightEndPoint) {
    node *node2move = leftEndPoint->next;   // node to be moved to front of list
    node *temp1;                            // node next to node2move
    node *temp2;                            // node before node2move
    auto pos = 1;                           // number of moves to next node2move

    // perform move until last node of sublist is the head
    while(rightEndPoint != leftEndPoint) {
        temp1 = node2move->prev;
        temp2 = node2move->next;

        // perform the move
        node2move->next = leftEndPoint;
        node2move->prev = leftEndPoint->prev;
        if(leftEndPoint->prev != NULL) {
            leftEndPoint->prev->next = node2move;
        }
        temp1->next = temp2;
        if(temp2 != NULL) {
            temp2->prev = temp1;
        }
        leftEndPoint->prev = node2move;

        // reset node2move & leftEndPoint for next iteration
        pos++;
        leftEndPoint = leftEndPoint->prev;
        for(auto i = pos; i != 0; i--) {
            node2move = node2move->next;
        }
    }

    // update head of list
    if(leftEndPoint->prev == NULL) {
        head = leftEndPoint;
    }

    // move r_end to end of sublist
    while(pos != 1) {
        rightEndPoint = rightEndPoint->next;
        pos--;
    }

    // update tail of list
    if(rightEndPoint->next == NULL) {
        tail = rightEndPoint;
    }
}

/*
* <<: overloaded standard output operator that displays data
*     contained in succesive nodes of a linked list.
* parameters: out: the standard outout stream
*             list: the linked list whose nodes' data are to be displayed
* return value: out: the standard output stream
*/
template <typename type>
std::ostream& operator<<(std::ostream& out, const LL<type>& list) {
    auto *current = list.head;    // current node to display

    for( ; current != NULL; current = current->next) {
        out << current->data;
        if(current != list.tail) {
            out << "->";
        }
    }

    return out;
}

#endif  // FWLL_HPP_

/* EOF */
