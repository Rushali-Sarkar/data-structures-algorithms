/*The intersection is one of the most popular operations 
which can be performed on data sets. Now, you will be implementing 
intersection for linked lists! 

Intersection 
Given two lists, A and B, the intersection is the largest list, 
which contains all the elements that are common to both the sets, 
but duplicates are not allowed.

The Intersection( LinkedList list1, LinkedList list2) the function takes two 
linked lists and returns all the elements that are common between two linked lists.

Input 
Two linked lists.

Output 
A list containing the intersection of the two lists.
Sample Input 
Input = 3
10
20
30
4
11
20
30
22
Sample Output 
20->30->null
*/

#include "LinkedList.h"
#include <unordered_set>
#include <iostream>

using namespace std;

LinkedList Intersection(LinkedList list1, LinkedList list2) {
    
    unordered_set<int> reference_list;
    unordered_set<int> intersection_list;
    Node* currentNode = list1.getHead();
    LinkedList intersection;
    
    while (currentNode != nullptr) {
        if (reference_list.find(currentNode -> data) == reference_list.end())
            reference_list.insert(currentNode -> data);
        currentNode = currentNode -> nextElement;
    }
    
    currentNode = list2.getHead();
    
    while (currentNode != nullptr) {
        
        if (reference_list.find(currentNode -> data) != reference_list.end() &&
            intersection_list.find(currentNode -> data) == intersection_list.end()) {
                intersection_list.insert(currentNode -> data);
                intersection.insertAtHead(currentNode -> data);
            }
            
            currentNode = currentNode -> nextElement;
    }
    
    return intersection;
}

int main(int argc, char* argv[]) {
    
    LinkedList list1;
    LinkedList list2;
    
    list1.insertAtHead(10);
    list1.insertAtHead(20);
    list1.insertAtHead(30);
    
    list2.insertAtHead(11);
    list2.insertAtHead(20);
    list2.insertAtHead(30);
    list2.insertAtHead(22);
    
    LinkedList intersection = Intersection(list1, list2);
    cout << intersection.elements() << endl;
    return 0;
 
}
