//
//  Dollar.hpp
//  Lab 01
//
//  Created by Abel Atnafu on 7/4/20.
//  Copyright © 2020 Abel Atnafu. All rights reserved.
//

#ifndef Dollar_hpp
#define Dollar_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

class Dollar
{
protected:
    int noteV;
    int coinV;
    string noteN;
    string coinN;

public:

    // Constructors and Constructors with values
    Dollar();
    Dollar(int cNValue, int cCValue, string cNName, string cCName);
    Dollar (const Dollar& source);
    Dollar (int NV,int CV);



    /*
    Sets Note value
    pre : USD amount
    post:
    return:
    */
    void setNoteValue (int moneyValue) {noteV = moneyValue;};

    /*
    Sets Coin value
    pre : USD Coin amount
    post:
    return:
    */
    void setCoinValue (int coinValue);

    /*
    Sets Note Name
    pre : USD Name
    post:
    return:
    */
    void setNoteName (string noteName) {noteN = noteName;};

    /*
    Sets Coin Name
    pre : USD coin Name
    post:
    return:
    */
    void setCoinName (string coinName) {coinN = coinName;};


    /*
    Displays everything
    pre :
    post:
    return:
    */
    virtual void printEverything () const;

    /*
    Gets Note value
    pre : USD Note Value
    post:
    return:int
    */
    int getNoteValue () const;

    /*
    Gets Coin value
    pre : Coin Note Value
    post:
    return:int
    */
    int getCoinValue () const;

    /*
    Gets Note Name
    pre : USD Note Name
    post:
    return:string
    */
    string getNoteName () const;

    /*
    Gets Coin name
    pre : USD coin name
    post:
    return:string
    */
    string getCoinName () const;

    /*
    Overloads + operator
    pre : adding value
    post: will add the two values
    return:Dollar
    */
     Dollar  operator+ (Dollar a);

    /*
    Overloads = operator
    pre : Subtracting value
    post: will subtract the two values
    return:Dollar
    */
     Dollar  operator- (Dollar a);

    /*
    Overloads == operator
    pre : Checking equality Value
    post: compare
    return:boolean
    */
     bool operator== ( Dollar b);

    /*
    Overloads < operator
    pre : Checking less than Value
    post: compare
    return:boolean
    */
     bool operator< ( Dollar b);

    /*
    Overloads > operator
    pre : Checking Greater than Value
    post: compare
    return:boolean
    */
     bool operator> (Dollar b);

    /*
    Sets Coin Name
    pre : USD coin Name
    post:
    return:
    */
    void setEverythingZero () {coinV = 0; noteV=0;};
    friend ostream& operator<<(ostream& output, const Dollar& item);
    //void  printEverythingFile (ostream& output, Dollar file);



};



#endif /* Dollar_hpp */


//Constructor
Dollar :: Dollar ()
{

     noteV = 0;
     coinV = 00;
     noteN = "USD";
     coinN = "USDC";
}

//Constructor for assigning values
Dollar :: Dollar(int cNValue, int cCValue, string cNName, string cCName)
{
    noteV = cNValue;
     if (cCValue<100)
        coinV = cCValue;
     else
     {
         while (cCValue>=100)
        {
            cCValue = cCValue-100;
            noteV++;
        }
         coinV=cCValue;
     }
    noteN = cNName;
    coinN = cCName;
}

// Assignment
Dollar :: Dollar (const Dollar& source)
{
    noteV = source.getNoteValue();
    coinV = source.getCoinValue();
    noteN = source.getNoteName();
    coinN = source.getCoinName();
}

//Constructor with Values for USD
Dollar :: Dollar (int NV, int CV)
{
    noteV= NV;
    noteN="USD";
    coinN="USDC";
     if (CV<100)
              coinV = CV;
           else
           {
               while (CV>=100)
              {
                  CV = CV-100;
                  noteV++;
              }
               coinV=CV;
           }

}

//Coin setter
void Dollar :: setCoinValue (int coinValue)
{
    if (coinValue<100)
           coinV = coinValue;
        else
        {
            while (coinValue>=100)
           {
               coinValue = coinValue-100;
               noteV++;
           }
            coinV=coinValue;
        }

}

//Output Everything
 void Dollar:: printEverything () const
 {
     double k;
     k= noteV+ (coinV/100.0);
     cout << "Amount: "<<fixed<< setprecision(2)<< k <<" "<< noteN<<endl;
 }

//Note Value Getter
int Dollar :: getNoteValue () const
{
    return noteV;
}

//Coin Value Getter
int Dollar ::getCoinValue () const
{
    return coinV;
}

//Note Name Getter
string Dollar :: getNoteName () const
{
    return noteN;
}

//Coin Name Getter
string Dollar :: getCoinName () const
{
    return coinN;
}

//+ Overloading Operator
Dollar Dollar :: operator+ (Dollar a)
{
    int coinA, noteA;

    noteA= a.getNoteValue() + noteV;
    coinA= a.getCoinValue() + coinV;

    if (coinA<100)
                return Dollar(noteA,coinA);
    else
    {
        while (coinA>=100)
       {
           coinA = coinA-100;
           noteA++;
       }
                return Dollar(noteA,coinA);
    }



}

//- Overloading Operator
Dollar Dollar :: operator-(Dollar b)
{
    int coinS, noteS;

    noteS = noteV - b.getNoteValue();
    coinS = coinV - b.getCoinValue();
       if ( coinS<0 )
        {
            noteS = (noteS*100) + (coinS);
            coinS = noteS % 100;
            noteS = noteS / 100;
            return Dollar(noteS,coinS);
        }

        else
    return Dollar(noteS,coinS);


}

//Equality Overloading Operator
 bool Dollar:: operator==( Dollar b)
{
    int totalA, totalB;
    totalA= (noteV*100)+coinV;
    totalB= (b.getNoteValue()*100)+b.getCoinValue();
    return totalA==totalB;

}


// Less than OverloadingOperator
  bool Dollar:: operator< ( Dollar b)
{
    int totalA, totalB;
    totalA= (noteV*100)+coinV;
    totalB= (b.getNoteValue()*100)+b.getCoinValue();
    return totalA<totalB;

}

//Greater Than Overloading Operator
 bool Dollar:: operator> ( Dollar b)
{
    int totalA, totalB;
    totalA= (noteV*100)+coinV;
    totalB= (b.getNoteValue()*100)+b.getCoinValue();
    return totalA>totalB;

}

 ostream&  operator<<( ostream& output,const Dollar& item)
{
   double k;
    k= item.getNoteValue()+ (item.getCoinValue()/100.0);
    output << "Amount: ";
    output<<fixed<< setprecision(2)<< k <<" "<< "USD"<<endl;
    return output;

}

/*void Dollar:: printEverythingFile (ostream& output, Dollar file)
{
    output<< file<<endl;
}
*/
