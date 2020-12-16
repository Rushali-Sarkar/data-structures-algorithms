/* Problem Statement 

You will implement the removeDuplicates() function. 
When a linked list is passed to this function, 
it removes any node, which is a duplicate of another existing node.

Input 

Size of the linked list.

Output 

A list with all the duplicates removed.
Sample Input = 8   
Sample Output =  1 Inserted!List : 1->null                                                       
2 Inserted!List : 2->1->null                                                    
3 Inserted!List : 3->2->1->null                                                 
4 Inserted!List : 4->3->2->1->null                                              
5 Inserted!List : 5->4->3->2->1->null                                           
6 Inserted!List : 6->5->4->3->2->1->null                                        
7 Inserted!List : 7->6->5->4->3->2->1->null                                     
2 Inserted!List : 2->7->6->5->4->3->2->1->null                                  
4 Inserted!List : 4->2->7->6->5->4->3->2->1->null                               
1 Inserted!List : 1->4->2->7->6->5->4->3->2->1->null                            
1->4->2->7->6->5->3->null                              
*/

#include <iostream>
#include "LinkedList.h"
#include <unordered_set>

using namespace std;

string removeDuplicates(LinkedList list) {
    
    Node* previousNode = list.head;
    Node* currentNode = previousNode -> nextElement;
    
    unordered_set<int> track_duplicate;
    track_duplicate.insert(previousNode -> data);
    
    int size = track_duplicate.size();
    
    
    while (currentNode != nullptr) {
        
        int value = currentNode -> data;
        
        if (track_duplicate.find(value) != track_duplicate.end()) {
            previousNode -> nextElement = currentNode -> nextElement;
            delete currentNode;
            currentNode = previousNode -> nextElement;
            continue;
        }
            
        
        else
            track_duplicate.insert(value);
            
        previousNode = previousNode -> nextElement;
        currentNode = currentNode -> nextElement;
        
    }
    
    return list.elements();
}

int main(int argc, char* argv[]) {
    
    LinkedList list;
    int x = 8;
    for (int i = 1; i < x; i++) {
        list.insertAtHead(i);
        list.printList();
    }
    
    list.insertAtHead(2);
    list.printList();
    list.insertAtHead(4);
    list.printList();
    list.insertAtHead(1);
    list.printList();
    
    
    string result = removeDuplicates(list);
    cout << result << endl;
    return 0;
}
