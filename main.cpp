//
//  main.cpp
//  Project1
//
//  Created by Mustafa Soby on 10/7/20.
//

#include <iostream>
#include <cstdlib>
#include "TodoList.cpp"
#include <fstream>

using namespace std;



TodoList list1;
TodoList list2;
int printMenu();
void handleSelection(int option, int whichList, TodoList &list);

int main(){
    int option=0;
    int whichList=1;
    
    cout<<"This Application is used to create Todo Lists. Two lists have already been created for you, these are the options you have."<<endl<<endl;
    
    
    while(true){
        cout<<"Do you want to work with list 1 or list 2 right now?(Enter 1 or 2)"<<endl;
        cin>>whichList;
        
        option=printMenu();
        if(option==0){
            break;
        }
        
        if(whichList==1){
            handleSelection(option,whichList, list1);
        }
        else if(whichList==2){
            handleSelection(option,whichList, list2);
        }
        else{
            cout<<"Not a valid list number.";
        }
        
        
        
    }
    
    
    
    
    
    return 0;
}

int printMenu(){
    int userInput;
    cout<<"Pick from these options: (Enter 0 to quit)"<<endl;
    
    /*
     cout<<"Todo item options:"<<endl;
     cout<<"1. Create a Todo item"<<endl;
     cout<<"2. Set a specific Todo item property"<<endl;
     cout<<"3. Edit a specific Todo item property"<<endl;
     cout<<"4. Get a specific Todo item property"<<endl;
     cout<<"5. Fill every Todo item property"<<endl;
     
     cout<<endl;
     */
    
    //cout<<"Todo List options:"<<endl;
    //cout<<"1. Create a Todo List"<<endl;
    cout<<"1. Add a task to the List"<<endl;
    cout<<"2. Edit a task from the list"<<endl;
    cout<<"3. Delete"<<endl;
    cout<<"4. Print"<<endl;
    cout<<"5. Sort"<<endl;
    cout<<"6. Merge"<<endl;
    cout<<"7. Clone"<<endl;
    cout<<"8. Make it 2D"<<endl;
    cout<<"9. Make it 3D"<<endl;
    cout<<"10. Input from a .txt"<<endl;
    
    cin>>userInput;
    cout<<endl;
    return userInput;
}

void handleSelection(int option, int whichList, TodoList &list){
    switch(option){
        case 1:
            list.addItem();
            break;
        case 2:
            list.editItem();
            break;
        case 3:
            int deleteChoice;
            cout<<endl;
            cout<<"How do you want to delete?"<<endl;
            cout<<"1. Single item, by ID"<<endl;
            cout<<"2. Multiple Items, by type"<<endl;
            cout<<"3. Multiple Items, by status"<<endl;
            cin>>deleteChoice;
            
            switch(deleteChoice){
                case 1:
                    list.deleteItem();
                    break;
                case 2:
                    list.deleteByType();
                    break;
                case 3:
                    list.deleteByStatus();
                    break;
            }
            
            break;
        case 4:
            int printChoice;
            cout<<endl;
            cout<<"How do you want to Print?"<<endl;
            cout<<"1. To console, one item"<<endl;
            cout<<"2. To console, all items"<<endl;
            cout<<"3. To console, all items, filtered by type"<<endl;
            cout<<"4. To console, all items, filtered by priority"<<endl;
            cout<<"5. To text file, all items"<<endl;
            cin>>printChoice;
            
            switch(printChoice){
                case 1:{
                    int inputID;
                    cout<<"What is the ID?"<<endl;
                    cin>>inputID;
                    list.printFilterID(inputID);
                    break;}
                case 2:{
                    list.printAll();
                    break;}
                case 3:
                {
                    string inputType="";
                    cout<<"What is the type?"<<endl;
                    cin>>inputType;
                    list.printFilterType(inputType);
                    break;
                }
                case 4:{
                    int inputPriority;
                    cout<<"What is the priority?"<<endl;
                    cin>>inputPriority;
                    list.printFilterPriority(inputPriority);
                    break;
                }
                case 5:{
                    string fileName="";
                    ofstream outFile;
                    cout<<"What do you want to name the output file?(Include the file extension '.csv' )"<<endl;
                    cin>>fileName;
                    outFile.open(fileName);
                    list.printToFile(outFile);
                    outFile.close();
                    break;
                }
            }
            break;
            
        case 5:
            int sortType;
            cout<<"How do you want to sort?"<<endl;
            cout<<"1. Priority"<<endl;
            cout<<"2. Due Date"<<endl;
            cout<<"3. Create Date"<<endl;
            cout<<"4. Type, then Priority"<<endl;
            cout<<"5. Type, then Due Date"<<endl;
            cin>>sortType;
            
            switch(sortType){
                case 1:{
                    list.sortByPriority(0, list.getPosition());
                }
                    break;
                case 2:{
                    list.sortByDueDate(0, list.getPosition());
                }
                    break;
                case 3:{
                    list.sortByCreateDate();
                }
                    break;
                case 4:{
                    list.sortByTypePriority();
                }
                    break;
                case 5:{
                    list.sortByTypeDueDate();
                }
                    break;
                    
            }
            break;
            
        case 6:
            if(whichList==1){
                list.merge(list2);
                cout<<"List 2 successfully merged to the end of list 1."<<endl;
            }
            if(whichList==2){
                list.merge(list1);
                cout<<"List 1 successfully merged to the end of list 2."<<endl;
            }
            break;
        case 7:
            cout<<"The clone feature copies the list you originally chose onto the other list:"<<endl;
            if(whichList==1){
                list.clone(list2);
                cout<<"List 1 successfully cloned on top of list 2."<<endl;
            }
            if(whichList==2){
                list.clone(list1);
                cout<<"List 2 successfully cloned on top of list 1."<<endl;
            }
            break;
        case 8:{
            makeIt2D(list);            
            break;
        }
        case 9:
        {
            makeIt3D(list);
            break;
        }
        case 10:
        {
            string inFileName;
            ifstream inFile;
            cout<<"What is the name of this file?(Include file extension .txt)";
            cin>>inFileName;
            inFile.open(inFileName);
            list.readList(inFile);
            inFile.close();
            break;
        }
    }
}
