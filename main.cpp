//Jane McPheron

//teammates: Jane McPheron, Sonja Case, Somayeh Najafi Hamedani, Yassine Berrada Rekhami

/*

jvmcpheron@dyn-10-140-246-187 CS2_HW9 % ./main
Left Set:
D: Y 
C: X 
B: Y 
A: X 
Right Set:
Y: B D 
X: A C 

*/


//Yassine Berrada Rekhami
#include <iostream>
#include <unordered_map>
#include <vector>


//class for data structure
class BipartiteGraph {
private:
    //left side
   std::unordered_map<std::string, std::vector<std::string>> leftSet;

   //right side
   std::unordered_map<std::string, std::vector<std::string>> rightSet;


public:
    //method to add edge to data structure
   void addEdge(const std::string& leftVertex, const std::string& rightVertex) {
       leftSet[leftVertex].push_back(rightVertex);
       rightSet[rightVertex].push_back(leftVertex);
   }

    //method to get connected data from left
   std::vector<std::string> getNeighborsLeft(const std::string& vertex) {
       return leftSet[vertex];
   }

    //method to get connected data from right
   std::vector<std::string> getNeighborsRight(const std::string& vertex) {
       return rightSet[vertex];
   }

    //method to display sets
   void display() {
       std::cout << "Left Set:\n";
       for (const auto& entry : leftSet) {
           std::cout << entry.first << ": ";
           for (const auto& neighbor : entry.second) {
               std::cout << neighbor << " ";
           }
           std::cout << std::endl;
       }


       std::cout << "Right Set:\n";
       for (const auto& entry : rightSet) {
           std::cout << entry.first << ": ";
           for (const auto& neighbor : entry.second) {
               std::cout << neighbor << " ";
           }
           std::cout << std::endl;
       }
   }
};


int main() {
   BipartiteGraph graph;


   graph.addEdge("A", "X");
   graph.addEdge("B", "Y");
   graph.addEdge("C", "X");
   graph.addEdge("D", "Y");


   graph.display();


   return 0;
}

