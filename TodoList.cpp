//
//  TodoList.cpp
//  Project1
//
//  Created by Mustafa Soby on 10/7/20.
//

#include "TodoList.hpp"
#include <cassert>
#include <fstream>

//Constructor
TodoList::TodoList(){
    position=0;
}

//Copy constructor
TodoList::TodoList(const TodoList &orig){
    for(int i=0;i<MAX_SIZE;++i){
        this->list[i]=orig.list[i];
    }
    position=orig.position;
}

//Add Items
void TodoList::addItem(){
    list[position++].fillMe();
}

//Edit Items
void TodoList::editItem(){
    if(position==0){
        std::cout<<"You have not created any items yet..."<<std::endl;
        return;
    }
    int inId, loco=-1;
    std::cout<<"Which item do you want to edit?(Enter the ID)"<<std::endl;
    std::cin>>inId;
    for(int i=0;i<position;++i){
        if(list[i].getId()==inId){
            loco=i;
            break;
        }
    }
    
    if(loco==-1){
        std::cout<<"No such ID"<<std::endl;
        return;
    }
    
    
    std::string attributeToEdit, temp;
    int tempInt;
    std::cout<<"Which attribute do you want to edit?"<<std::endl;
    std::cin.ignore();
    getline(std::cin, attributeToEdit);
    
    if(attributeToEdit=="Title"){
        std::cout<<"Enter the Title you want it to become:"<<std::endl;
        getline(std::cin, temp);
        list[loco].setTitle(temp);
    }else if(attributeToEdit=="Description"){
        std::cout<<"Enter the Description you want it to become:"<<std::endl;
        getline(std::cin, temp);
        list[loco].setDescription(temp);
    }else if(attributeToEdit=="Priority"){
        std::cout<<"Enter the Priority you want it to become:"<<std::endl;
        std::cin>>tempInt;
        list[loco].setPriority(tempInt);
    }else if(attributeToEdit=="Status"){
        std::cout<<"Enter the Status you want it to become:"<<std::endl;
        getline(std::cin, temp);
        list[loco].setStatus(temp);
    }else if(attributeToEdit=="Due Date"){
        std::cout<<"Enter the Due Date you want it to become:(Separated by spaces)"<<std::endl;
        int month,day,year;
        std::cin>>month>>day>>year;
        list[loco].setDueDate(month, day, year);
    }
    else{
        std::cout<<"Invalid attribute"<<std::endl;
    }
    
}

void TodoList::deleteAndShift(int loco){
    for(int i=loco;i<position-1;++i){
        list[i]=list[i+1];
    }
    position--;
}

//Delete Items
void TodoList::deleteItem(){
    int inId, loco=-1;
    std::cout<<"Which item do you want to delete?(Enter its Id)"<<std::endl;
    std::cin>>inId;
    for(int i=0;i<position;++i){
        if(list[i].getId()==inId){
            loco=i;
            break;
        }
    }
    
    if(loco==-1){
        std::cout<<"No such ID";
        return;
    }
    
    deleteAndShift(loco);
    
}

void TodoList::deleteByType(){
    std::string inType;
    std::cout<<"Which Type do you want to delete"<<std::endl;
    std::cin>>inType;
    
    for(int i=0;i<position;++i){
        if(list[i].getTypeAsString()==inType){
                deleteAndShift(i);
                i--;
        }
    }
}

void TodoList::deleteByStatus(){
    std::string inStatus;
    std::cout<<"Which Status do you want to delete"<<std::endl;
    std::cin>>inStatus;
    
    for(int i=0;i<position;++i){
        if(list[i].getStatusAsString()==inStatus){
            deleteAndShift(i);
            i--;
        }
    }
}

//Printers
void TodoList::printToFile(std::ofstream &out){
    //Print headers for each column
    out<<"ID,Title,Description,Type,Priority,Status,Create Date,Due Date,Last Modified\n";
    
    for(int i=0;i<position;++i){
        out<<list[i].getId()<<",";
        out<<list[i].getTitle()<<",";
        out<<list[i].getDescription()<<",";
        out<<list[i].getTypeAsString()<<",";
        out<<list[i].getPriority()<<",";
        out<<list[i].getStatusAsString()<<",";
        out<<list[i].getCreateDateAsString()<<",";
        out<<list[i].getDueDateAsString()<<",";
        out<<list[i].getLastModifiedAsString()<<",\n";
    }
}


void TodoList::printAll(){
    for(int i=0;i<position;++i){
        std::cout<<"ID: "<<list[i].getId()<<" "<<std::endl;
        std::cout<<"Title: "<<list[i].getTitle()<<" "<<std::endl;
        std::cout<<"Description: "<<list[i].getDescription()<<" "<<std::endl;
        std::cout<<"Type: "<<list[i].getTypeAsString()<<" "<<std::endl;
        std::cout<<"Priority: "<<list[i].getPriority()<<" "<<std::endl;
        std::cout<<"Status: "<<list[i].getStatusAsString()<<" "<<std::endl;
        std::cout<<"Create Date: "<<list[i].getCreateDateAsString()<<" "<<std::endl;
        std::cout<<"Due Date: "<<list[i].getDueDateAsString()<<" "<<std::endl;
        std::cout<<"Last Modified: "<<list[i].getLastModifiedAsString()<<"\n"<<std::endl;
    }
}

void TodoList::printFilterType(std::string type){
    for(int i=0;i<position;++i){
        if(list[i].getTypeAsString()==type){
            std::cout<<"ID: "<<list[i].getId()<<" "<<std::endl;
            std::cout<<"Title: "<<list[i].getTitle()<<" "<<std::endl;
            std::cout<<"Description: "<<list[i].getDescription()<<" "<<std::endl;
            std::cout<<"Type: "<<list[i].getTypeAsString()<<" "<<std::endl;
            std::cout<<"Priority: "<<list[i].getPriority()<<" "<<std::endl;
            std::cout<<"Status: "<<list[i].getStatusAsString()<<" "<<std::endl;
            std::cout<<"Create Date: "<<list[i].getCreateDateAsString()<<" "<<std::endl;
            std::cout<<"Due Date: "<<list[i].getDueDateAsString()<<" "<<std::endl;
            std::cout<<"Last Modified: "<<list[i].getLastModifiedAsString()<<"\n"<<std::endl;
        }
        
    }
}

void TodoList::printFilterPriority(int priority){
    for(int i=0;i<position;++i){
        if(list[i].getPriority()==priority){
            std::cout<<"ID: "<<list[i].getId()<<" "<<std::endl;
            std::cout<<"Title: "<<list[i].getTitle()<<" "<<std::endl;
            std::cout<<"Description: "<<list[i].getDescription()<<" "<<std::endl;
            std::cout<<"Type: "<<list[i].getTypeAsString()<<" "<<std::endl;
            std::cout<<"Priority: "<<list[i].getPriority()<<" "<<std::endl;
            std::cout<<"Status: "<<list[i].getStatusAsString()<<" "<<std::endl;
            std::cout<<"Create Date: "<<list[i].getCreateDateAsString()<<" "<<std::endl;
            std::cout<<"Due Date: "<<list[i].getDueDateAsString()<<" "<<std::endl;
            std::cout<<"Last Modified: "<<list[i].getLastModifiedAsString()<<"\n"<<std::endl;
        }
        
    }
}

void TodoList::printFilterID(int idIn){
    for(int i=0;i<position;++i){
        if(list[i].getId()==idIn){
            std::cout<<"ID: "<<list[i].getId()<<" "<<std::endl;
            std::cout<<"Title: "<<list[i].getTitle()<<" "<<std::endl;
            std::cout<<"Description: "<<list[i].getDescription()<<" "<<std::endl;
            std::cout<<"Type: "<<list[i].getTypeAsString()<<" "<<std::endl;
            std::cout<<"Priority: "<<list[i].getPriority()<<" "<<std::endl;
            std::cout<<"Status: "<<list[i].getStatusAsString()<<" "<<std::endl;
            std::cout<<"Create Date: "<<list[i].getCreateDateAsString()<<" "<<std::endl;
            std::cout<<"Due Date: "<<list[i].getDueDateAsString()<<" "<<std::endl;
            std::cout<<"Last Modified: "<<list[i].getLastModifiedAsString()<<"\n"<<std::endl;
            break;
        }
        
    }
}

//Merger & Cloner
void TodoList::merge(const TodoList &mergeMe){
    for(int i=0;i<mergeMe.position;++i){
        list[position++]=mergeMe.list[i];
    }
}

void TodoList::clone(TodoList &willBeOverwritten){
    for(int i=0;i<100;++i){
        willBeOverwritten.list[i]=this->list[i];
    }
    willBeOverwritten.position=this->position;
}




//Read list from file
void TodoList::readList(std::ifstream &inFile){
    int idIn;
    std::string titleIn;
    std::string descriptionIn;
    
    std::string typeIn;
    int priorityIn;
    std::string statusIn;
    
    int createDateMonthIn;
    int createDateDayIn;
    int createDateYearIn;
    
    int dueDateMonthIn;
    int dueDateDayIn;
    int dueDateYearIn;
    
    int lastModifiedMonthIn;
    int lastModifiedDayIn;
    int lastModifiedYearIn;
    if(!inFile.is_open())
    {
        std::cout<<"COULD NOT OPEN"<<std::endl;
        assert(false);
    }
    while(!inFile.eof()){
        inFile>>idIn>>titleIn>>descriptionIn>>typeIn>>priorityIn>>statusIn>>createDateMonthIn>>createDateDayIn>>createDateYearIn>>dueDateMonthIn>>dueDateDayIn>>dueDateYearIn>>lastModifiedMonthIn>>lastModifiedDayIn>>lastModifiedYearIn;
        
        list[position].setId(idIn);
        list[position].setTitle(titleIn);
        list[position].setDescription(descriptionIn);
        
        list[position].setType(typeIn);
        list[position].setPriority(priorityIn);
        list[position].setStatus(statusIn);
        
        list[position].setCreateDate2(createDateMonthIn, createDateDayIn,createDateYearIn);
        list[position].setDueDate(dueDateMonthIn, dueDateDayIn, dueDateYearIn);
        list[position].setLastModified2(lastModifiedMonthIn, lastModifiedDayIn,lastModifiedYearIn);
        
        position++;
    }
    
    
    
}

//Helpers
int TodoList::getPosition(){
    return position;
}

std::string TodoList::getTitleByPos(int positionIn){
    return list[positionIn].getTitle();
}

Todo TodoList::getItemByPos(int positionIn){
    return list[positionIn];
}

std::string TodoList::getTypeAsStringByPos(int positionIn){
    return list[positionIn].getTypeAsString();
}

std::string TodoList::getPriorityAsStringByPos(int positionIn){
    return std::to_string(list[positionIn].getPriority());
}


//Sorting
void TodoList::swapUs(int leftIndex, int rightIndex){
    Todo temp;
    temp=list[leftIndex];
    list[leftIndex]=list[rightIndex];
    list[rightIndex]=temp;
    
}


void TodoList::sortByCreateDate(){
    int minIndex;
    for(int i=0;i<position;++i){
        minIndex=i;
        for(int k=i+1;k<position;++k){
            if(list[k].createLessThan(list[minIndex])){
                minIndex=k;
            }
        }
        swapUs(i,minIndex);
    }
}

void TodoList::sortByTypePriority(){
    //Three types are shopping, house, and work
    int moveTo=0, saveMoveTo=0;
    
    //Moves every item that has shopping in it to the beginning of the list
        for(int i=saveMoveTo;i<position;++i){
            if(list[i].getType()==Type::shopping){
                swapUs(moveTo, i);
                moveTo++;
            }
        }
    
    //Reorders every item that has type shopping in that range
    sortByPriority(saveMoveTo,moveTo);
    
    saveMoveTo=moveTo;
    
    //Moves every item that has house in it to the beginning of the list
        for(int i=saveMoveTo;i<position;++i){
            if(list[i].getType()==Type::house){
                swapUs(moveTo, i);
                moveTo++;
            }
        }
    
    //Reorders every item that has type shopping in that range
    sortByPriority(saveMoveTo,moveTo);
    
    saveMoveTo=moveTo;
    
    //Reorders every item that has type work in the end range
    sortByPriority(moveTo,position);
}

void TodoList::sortByTypeDueDate(){
    //Three types are shopping, house, and work
    int moveTo=0, saveMoveTo=0;
    
    //Moves every item that has shopping in it to the beginning of the list
        for(int i=saveMoveTo;i<position;++i){
            if(list[i].getType()==Type::shopping){
                swapUs(moveTo, i);
                moveTo++;
            }
        }
    
    //Reorders every item that has type shopping in that range
    sortByDueDate(saveMoveTo,moveTo);
    
    saveMoveTo=moveTo;
    
    //Moves every item that has house in it to the beginning of the list
        for(int i=saveMoveTo;i<position;++i){
            if(list[i].getType()==Type::house){
                swapUs(moveTo, i);
                moveTo++;
            }
        }
    
    //Reorders every item that has type shopping in that range
    sortByDueDate(saveMoveTo,moveTo);
    
    saveMoveTo=moveTo;
    
    //Reorders every item that has type work in the end range
    sortByDueDate(moveTo,position);
}


//Inner Sorters
void TodoList::sortByPriority(int lower, int upper){
    bool needsChange=false;
    int min, index=lower;
    for(int i=lower;i<upper-1;++i){
        min=list[i].getPriority();
        for(int k=i+1;k<upper;++k){
            if(list[k].getPriority()<min){
                min=list[k].getPriority();
                index=k;
                needsChange=true;
            }
        }
        if(needsChange){
        swapUs(i,index);
            needsChange=false;
        }
    }
}

void TodoList::sortByDueDate(int lower, int upper){
    bool needsChange=false;
    int minIndex;
    for(int i=lower;i<upper-1;++i){
        minIndex=i;
        for(int k=i+1;k<upper;++k){
            if(list[k].dueLessThan(list[minIndex])){
                minIndex=k;
                needsChange=true;
            }
        }
        if(needsChange){
        swapUs(i,minIndex);
            needsChange=false;
        }
        
    }
}

//Global Functions
void makeIt2D(TodoList &aList){
    int length=aList.getPosition();
    //Make the string array, 1st dimension holds title, second holds type
    Todo **array2D= new Todo*[3];
    int shopLen=0, houseLen=0, workLen=0;
    
    //Make each mini array length long
    for(int i=0;i<length;++i){
        array2D[i]=new Todo[length];
    }
    
    //Shopping row
    for(int i=0;i<length;++i){
        if(aList.getTypeAsStringByPos(i)=="shopping"){
            Todo x=aList.getItemByPos(i);
            array2D[0][shopLen].setId(x.getId());
            array2D[0][shopLen].setTitle(x.getTitle());
            array2D[0][shopLen].setDescription(x.getDescription());
            array2D[0][shopLen].setType(x.getTypeAsString());
            array2D[0][shopLen].setPriority(x.getPriority());
            array2D[0][shopLen].setStatus(x.getStatusAsString());
            array2D[0][shopLen].setCreateDate2(x.getCreateDate().day,x.getCreateDate().month,x.getCreateDate().year);
            array2D[0][shopLen].setDueDate(x.getDueDate().day,x.getDueDate().month,x.getDueDate().year);
            array2D[0][shopLen].setLastModified2(x.getLastModified().day,x.getLastModified().month,x.getLastModified().year);
            
            shopLen++;
        }
    }
    
    //House row
    for(int i=0;i<length;++i){
        if(aList.getTypeAsStringByPos(i)=="house"){
            Todo x=aList.getItemByPos(i);
            array2D[1][houseLen].setId(x.getId());
            array2D[1][houseLen].setTitle(x.getTitle());
            array2D[1][houseLen].setDescription(x.getDescription());
            array2D[1][houseLen].setType(x.getTypeAsString());
            array2D[1][houseLen].setPriority(x.getPriority());
            array2D[1][houseLen].setStatus(x.getStatusAsString());
            array2D[1][houseLen].setCreateDate2(x.getCreateDate().day,x.getCreateDate().month,x.getCreateDate().year);
            array2D[1][houseLen].setDueDate(x.getDueDate().day,x.getDueDate().month,x.getDueDate().year);
            array2D[1][houseLen].setLastModified2(x.getLastModified().day,x.getLastModified().month,x.getLastModified().year);
            
            houseLen++;
        }
    }
    
    //Work row
    for(int i=0;i<length;++i){
        if(aList.getTypeAsStringByPos(i)=="work"){
            Todo x=aList.getItemByPos(i);
            array2D[2][workLen].setId(x.getId());
            array2D[2][workLen].setTitle(x.getTitle());
            array2D[2][workLen].setDescription(x.getDescription());
            array2D[2][workLen].setType(x.getTypeAsString());
            array2D[2][workLen].setPriority(x.getPriority());
            array2D[2][workLen].setStatus(x.getStatusAsString());
            array2D[2][workLen].setCreateDate2(x.getCreateDate().day,x.getCreateDate().month,x.getCreateDate().year);
            array2D[2][workLen].setDueDate(x.getDueDate().day,x.getDueDate().month,x.getDueDate().year);
            array2D[2][workLen].setLastModified2(x.getLastModified().day,x.getLastModified().month,x.getLastModified().year);
        
            workLen++;
        }
    }
    
    std::cout<<"The following represents the items in each location of the 2D array that was created and filled."<<std::endl;
    //Print the shopping mini array
        for(int c=0;c<shopLen;++c){
            std::cout<<array2D[0][c].getTitle()<<" ";
        }
        std::cout<<std::endl;
    
    //Print the shopping mini array
        for(int c=0;c<houseLen;++c){
            std::cout<<array2D[1][c].getTitle()<<" ";
        }
        std::cout<<std::endl;
    
    //Print the shopping mini array
        for(int c=0;c<workLen;++c){
            std::cout<<array2D[2][c].getTitle()<<" ";
        }
        std::cout<<std::endl;
    
    //Deallocate the space
    for(int i=0;i<3;++i){
        delete[] array2D[i];
    }
    
    delete[] array2D;
}


void makeIt3D(TodoList &aList){
    int length=aList.getPosition(), shopLen=0, houseLen=0, workLen=0;
    
    //Second dimension holds type, third holds priority
    Todo ***array3D= new Todo**[3];
    
    //Make each second degree array 5 long since there are 5 levels of priority
    for(int i=0;i<length;++i){
        array3D[i]=new Todo*[5];
    }
    
    //Make each third degree array length long since each one could have all the parts in it
    for(int i=0;i<length;++i){
        array3D[i][i]=new Todo[length];
    }
    
    
}
