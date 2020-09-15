//
//  hash.h
//  Lab 06
//
//  Created by Abel Atnafu on 8/7/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

class HashTable {
    private:
    //hashtable size
    int size;
    //dollar list
    Dollar *table;
    //constant m
    static const int m=2;
    //constant n
    static const int n=3;
    //amount of items
    int amount=0;
    //amount of collisions
    int totalCollision=0;

    public:
    /*
    constructor with the size parameter.
    pre :integer length
    post:
    return:
    */
    HashTable(int length);//
    /*
    hashes the note value and coin value
    pre :Dollar value being hashed
    post:hashes
    return:hashed int home address
    */
    int getHash(Dollar k);//
    /*
    Gets the load factor
    pre :
    post:amount/size
    return:double
    */
    double getLoadFactor();//
    /*
    Gets collision
    pre :
    post:
    return:total collusion
    */
    int getCollision();//
    /*
    inserts a new value to the hash table
    pre :the new Dollar being added
    post:adds dollar
    return:bool to confirm it being added
    */
    bool insertItem(Dollar edu);//
    /*
    removes a  value from the hash table if found
    pre :the  Dollar being removed
    post:removes dollar
    return:bool to confirm its removed
    */
    bool removeItem(Dollar edu);//
    /*
    seaches for a value in the hash table
    pre :the  Dollar being searched for
    post:finds a Dollar object
    return:int index if it finds or -1 if not
    */
    int searchTable(Dollar edu);//
    /*
    prints the whole hash table
    pre
    post:prints dollar members
    return:
    */
    void printTable();//


};

#endif /* hash_h */


HashTable :: HashTable(int length)
{
    size =length;
    table = new Dollar[size];
    for (int i=0 ; i<size; i++)
    {
        table[i].setNoteValue(-1);
        table[i].setCoinValue(-1);

    }
}

int HashTable :: getHash (Dollar k)
{
    int note,coin;
    note= k.getNoteValue();
    coin= k.getCoinValue();
    return ((m*note +  n*coin) % size);
}

bool HashTable:: insertItem(Dollar edu)
{
    int buckets=getHash(edu);
    int i=0;
    int bucketsProbed=0;
    while (bucketsProbed<size)
    {
    if(table[buckets].getNoteValue()<0)
    {
        Dollar zItem (edu.getNoteValue(),edu.getCoinValue(),"USD","USC" );
        table[buckets]= zItem;
        amount++;
        //cout << "Collision= " << bucketsProbed<<endl;
        totalCollision = totalCollision + bucketsProbed;
        return true;
    }
        i++;
        buckets = (getHash(edu) + (i*i))%size; //could have used getHash(edu)+ c1*i + c2*i*i for everything
                                              //but class lecture also used getHash(edu) + i*i as a quadratic probing
        bucketsProbed++;
    }
    return false;
}

bool HashTable:: removeItem(Dollar edu)
{
    int i = 0;
    int bucketsProbed = 0;


    int bucket = getHash(edu);

    while (table[bucket].getNoteValue()>0 && table[bucket].getCoinValue()>=0 && bucketsProbed < size)// >= FOR COINVALUE for empty after remove
    {
        if (table[bucket].getNoteValue()== edu.getNoteValue() && table[bucket].getCoinValue()== edu.getCoinValue())
        {
            Dollar zItem (-1,0,"USD","USC" );//COIN 0 to show that its empty after removed
            table[bucket]= zItem;
            amount--;
            return true;//found and removed
        }

        i = i + 1;
        bucket = (getHash(edu) + (i * i)) % size;//could have used getHash(edu)+ c1*i + c2*i*i for everything
                                                 //but class lecture also used getHash(edu) + i*i as a quadratic probing
        bucketsProbed = bucketsProbed + 1;
    }
    return false;  // key not found
}


int HashTable:: searchTable(Dollar edu)
{
      int i = 0;
      int bucketsProbed = 0;


      int bucket = getHash(edu);

      while (table[bucket].getNoteValue()>0 && table[bucket].getCoinValue()>=0 && bucketsProbed < size)// >= FOR COINVALUE for empty after remove
      {
          if (table[bucket].getNoteValue()== edu.getNoteValue() && table[bucket].getCoinValue()== edu.getCoinValue())
          {

              return bucket;//found
          }

          i = i + 1;
          bucket = (getHash(edu) + (i * i)) % size; //could have used getHash(edu)+ c1*i + c2*i*i for everything
                                                    //but class lecture also used getHash(edu) + i*i as a quadratic probing
          bucketsProbed = bucketsProbed + 1;
      }
      return -1;  // key not found
}


void HashTable:: printTable()
{
    for (int i=0; i<size; i++)
    {
        if (table[i].getNoteValue()>0)
        {
            cout<<i<<" ";
            table[i].printEverything();
        }
        else
        {
            cout<<i<<" ";
            cout<< "Empty"<<endl;
        }
    }
}

double HashTable:: getLoadFactor()
{
    return (amount*1.00/size);
}

 int HashTable:: getCollision()
{
    return totalCollision;
}
