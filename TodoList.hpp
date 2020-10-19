//
//  TodoList.hpp
//  Project1
//
//  Created by Mustafa Soby on 10/7/20.
//

#ifndef TodoList_hpp
#define TodoList_hpp

#include <stdio.h>
#include "Todo.cpp"

#define MAX_SIZE 100

class TodoList{
private:
    Todo list[MAX_SIZE];
    int position;
    //Helper
    void deleteAndShift(int loco);
public:
    TodoList();
    TodoList(const TodoList &orig);
    void addItem();
    void editItem();
    void deleteItem();
    
    void readList(std::ifstream &inFile);
    void deleteByType();
    void deleteByStatus();
    
    //Sorters
    void sortByPriority(int lower, int upper);
    void sortByDueDate(int lower, int upper);
    void sortByCreateDate();
    void sortByTypePriority();
    void sortByTypeDueDate();
    
    //Printers
    void printToFile(std::ofstream &out);
    void printAll();
    void printFilterType(std::string type);
    void printFilterPriority(int priority);
    void printFilterID(int idIn);
    
    //Merger & Cloner
    void merge(const TodoList &mergeMe);
    void clone(TodoList &willBeOverwritten);
    
    //Helper
    int getPosition();
    std::string getTitleByPos(int positionIn);
    std::string getTypeAsStringByPos(int positionIn);
    std::string getPriorityAsStringByPos(int positionIn);
    void swapUs(int leftIndex, int rightIndex);
    Todo getItemByPos(int positionIn);
    
};

void makeIt2D( TodoList &aList);
void makeIt3D( TodoList &aList);


#endif /* TodoList_hpp */
