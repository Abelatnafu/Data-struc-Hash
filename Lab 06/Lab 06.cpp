
/*
Name: Abel Atnafu
Class: CIS 22C
Lab 06
Aid for lab 3

 This program stores ten dollar values into a hashtable then lets the user search values in a loop.

 *//*

                 Pseudocode

 Declare size;
 Print (name Box);
 Create Dollar objects;
 Define Dollar objects;

 zHashTable;

 //Insert Dollar object to list
 zHashTable.insertDollars();
 Dollar ptr;
 Trial =1;

 print(zHashTable);
 print(loadFactor);
 print(collision);
 //Ask user if they wanna search then answer sets trial to 1 or 2
 while(trial==1)
 {
         Ask and input dollar and coin amount;
         ptr= new Dollar(dollar,coin, “USD”,”USC”);
         zHashTable.search(ptr);
         If (found)
             Print( index);
         Else
             Print (not found);

 Ask if wanna try again then answer sets trial to 1 or 2

 }
 End


 */


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <list>
#include "Dollar.h"
#include "hashTable.h"


int main()
{
    //size
    const int tableSize=29;
    //name
    cout<< left<< fixed<< setw(18)<<"****************************************"<<endl;
    cout<< left<< fixed<< setw(18)<<"Name: Abel Atnafu"<<endl;
    cout<< left<< fixed<< setw(18)<<"Summer CIS 22C"<<endl;
    cout<< left<< fixed<< setw(18)<<"Lab 06"<<endl;
    cout<< left<< fixed<< setw(18)<<"Lab 03 Aid."<<endl;
    cout<< left<< fixed<< setw(18)<<"****************************************"<<endl;
    //declare
     Dollar soda(2,99,"USD","USC");
     Dollar pizza(10,49,"USD","USC");
     Dollar drugs(49,99,"USD","USC");
     Dollar lolipop(2,49,"USD","USC");
     Dollar clothes(40,00,"USD","USC");
     Dollar car(3000,13,"USD","USC");
     Dollar shoes(250,51,"USD","USC");
     Dollar alcohol(46,00,"USD","USC");
     Dollar friends(20,99,"USD","USC");
     Dollar invest(1000,51,"USD","USC");
     HashTable zTable(tableSize);

     cout<< "Inserting the Dollar values to the Hashtable"<<endl;
        //insert
     zTable.insertItem(soda);
     zTable.insertItem(pizza);
     zTable.insertItem(drugs);
     zTable.insertItem(lolipop);
     zTable.insertItem(clothes);
     zTable.insertItem(car);
     zTable.insertItem(shoes);
     zTable.insertItem(alcohol);
     zTable.insertItem(friends);
     zTable.insertItem(invest);
     cout<< "All dollar values entered. "<<endl<<endl;
     int trial=1;
     int noteV,coinV;
     Dollar* searchin;
    cout<< "Printing the table "<<endl;
     cout<< left<< fixed<< setw(18)<<"----------------------------------------"<<endl;

    zTable.printTable();
    cout<< left<< fixed<< setw(18)<<"----------------------------------------"<<endl;
    cout<<fixed<<setprecision(2)<<"The load factor is "<<zTable.getLoadFactor()<<"."<<endl;
    cout<<"The Total collision amount was "<< zTable.getCollision()<< "."<<endl;
    cout<< left<< fixed<< setw(18)<<"----------------------------------------"<<endl;
    cout<<"Do you want to search for a specific Dollar in the list?" << endl;
    cout <<"1)yes   2)No"<<endl;
    cin >> trial;

    while(trial ==1)
    {
        cout<<"Enter the Note Value for the Dollar amount you want to search"<<endl;
        cin>> noteV;
        cout<<"Enter the Coin Value for the Dollar amount you want to search"<<endl;
        cin >> coinV;


        searchin= new Dollar(noteV,coinV,"USD","USC");
        if (zTable.searchTable(*searchin)>0)
        {
            cout << "Found at index "<< zTable.searchTable(*searchin)<< "." <<endl;

        }
        else
        {
             cout << "Invalid Data!"<<endl;

        }
        cout<< left<< fixed<< setw(18)<<"----------------------------------------"<<endl;
        cout<<"Do you want to search again? "<<endl;
        cout <<"1)yes   2)No"<<endl;
        cin>> trial;
        delete searchin;

    }
        cout<< " Thanks a lot for all the help this quarter. :)"<< endl<<endl;


}
