/* Problem Statement
 *
 * You have to implement the string tracePath(unordered_map<string, string> map) function, which will take in an
 * array of source-destination pairs and return the correct sequence of the whole journey from the first city to 
 * the last.
 *
 * Input
 *
 * An unordered_map of type <string, string> containing string pairs of source-destination cities.
 *
 * Output
 *
 * A string of source-destination pairs in correct order.
 *
 * Sample Input
 * 4
 *
 * NewYork
 * Chicago
 * Boston
 * Texas
 * Missouri
 * NewYork
 * Texas
 * Missouri
 *
 * Sample Output
 *
 * Boston -> Texas, Texas -> Missouri, Missouri -> NewYork, NewYork->Chicago
 */



#include<unordered_map>
#include<iostream>
#include<string>

using namespace std;


string tracePath(unordered_map<string, string> map) {
    
    string last_place = "";
    unordered_map <string, string> invertedSourceDestination;
    

    for (auto const& pair: map) {
        if (map.find(pair.second) == map.end()) 
            last_place = pair.second;

        invertedSourceDestination[pair.second] = pair.first;
    } 

    string result = "";

    while (invertedSourceDestination.find(last_place) != invertedSourceDestination.end()) {

        result = invertedSourceDestination[last_place] + "->" + last_place + ", " + result;
        last_place = invertedSourceDestination[last_place];
    }

    return result.substr(0, result.length() - 2);

  }


int main(int argc, char* argv[]) {

    unordered_map<string, string> map;
    map["NewYork"] = "Chicago";
    map["Boston"] = "Texas";
    map["Missouri"] = "NewYork";
    map["Texas"] = "Missouri" ;

    string result = tracePath(map);
    cout << result << endl;

    return 0;
}
