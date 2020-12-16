/* Problem Statement 

The union is one of the most popular operations which can be performed on data sets. 
Now, you will be implementing a union for linked lists! 

Union 

Given two lists, A and B, the union is the list that contains elements or 
objects that belong to either A or to B or to both, but duplicates are not allowed.

The Union( LinkedList list1, LinkedList list2) the function takes two linked lists 
and returns their union. 


Input 

Linked List

Output 

A list containing the union of the two lists.
Sample Input 

5  // size                                                                            
10                                                                              
20                                                                              
80                                                                              
20                                                                              
60                                                                              
7      // size                                                                         
10                                                                              
20                                                                              
80                                                                              
60                                                                              
15  
30
45


Sample Output 


15->30->45->10->80->20->60->null

*/

#include "LinkedList.h"
#include <unordered_set>
#include <iostream>

using namespace std;

LinkedList Union(LinkedList list1, LinkedList list2) {
    
    LinkedList union_list;
    Node* currentNode = list1.getHead();
    unordered_set<int> helper_union_list;
    
    while (currentNode != nullptr) {
        
        if (helper_union_list.find(currentNode -> data) == 
            helper_union_list.end()) {
        helper_union_list.insert(currentNode -> data);
        union_list.insertAtHead(currentNode -> data);
            }
        currentNode = currentNode -> nextElement;
    }
    
    currentNode = list2.getHead();
    while (currentNode != nullptr) {
        
        if (helper_union_list.find(currentNode -> data) == 
            helper_union_list.end()) {
        helper_union_list.insert(currentNode -> data);
        union_list.insertAtHead(currentNode -> data);
            }
        currentNode = currentNode -> nextElement;
    }
    
    return union_list;
}


int main(int argc, char* argv[]) {
    
    LinkedList list1;
    LinkedList list2;
    
    list1.insertAtHead(10);
    list1.insertAtHead(20);
    list1.insertAtHead(80);
    list1.insertAtHead(20);
    list1.insertAtHead(60);

    list2.insertAtHead(10);
    list2.insertAtHead(20);
    list2.insertAtHead(80);
    list2.insertAtHead(60);
    list2.insertAtHead(15);
    list2.insertAtHead(30);
    list2.insertAtHead(45);
    
    LinkedList union_list = Union(list1, list2);
    cout << union_list.elements() << endl;
    return 0;
    
}
