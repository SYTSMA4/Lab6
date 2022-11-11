/*
 Sam Sytsma
 C++ Fall 2022
 Due: Nov. 11, 2022
 Lab 6 Binary to Decimal
 This Lab is a demo of my ability to write a C++ program that reads characters representing binary (base 2)
 numbers from a data file called BinaryIn.dat and translates them to decimal (base 10) numbers.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

string inputfile = "/Users/samsytsma/Documents/Lab6/Lab6/BinaryIn.dat";

//Precondition:     Include library iostream, iomanip
//Postcondition:    Outputs heading
void Heading();

//Precondition:     Include library iostream, fstream
//Postcondition:    Opens and closes file
void FileInput(char binum, int decimal);

//Precondition:     Include library iostream, iomanip. File BinaryIn.dat opened.
//Postcondition:    Outputs binary number.  Converts binary to decimal.  Outputs decimal.
void Conversion(char binum, int decimal, ifstream& infile);

int main(){
    char binum = 0;
    int decimal = 0;

    Heading();
    FileInput(binum, decimal);
    
    return 0;
}

void Heading(){         //Outputs heading
    cout << setw(21) << "Binary Number" << setw(85) << "Decimal Equivalent\n";
}

void FileInput(char binum, int decimal){
    ifstream infile;
    infile.open(inputfile);              //Opens file
     
    if(!infile)                          //Checks for file
        cout << "\nCan't find file\n";
    
    Conversion(binum, decimal, infile);

    infile.close();                     //Closes file
}

void Conversion(char binum, int decimal, ifstream& infile){
    int count = 0;
    bool FirstNum = false;
    bool BadDigit = false;
    
    infile.get(binum);                  //Grabs primer number
    
    while(infile){                       //Runs loop as long as there are inputs in file
        cout << "\t\t\t";
        while(binum != '\n' && infile){
            if((!FirstNum && binum == '1') || (FirstNum && (binum == '1' || binum == '0'))){      //Checks for a one or zero to check for a bad digit
                count++;
                FirstNum = true;
                cout << binum;
                decimal *= 2;                           //Equation to solve binum is #count*2 + (1 or 0)
                
                if(binum == '1'){                       //If there is a one in binary number you add one to decimal calculation
                    decimal++;
                }
            }
            else if((binum != ' ') || (binum  == ' ' && FirstNum)){        //Checks for space inside number.  Checks for non 1 or 0.
                for(int i = 0; i < count; i++)
                    cout << '\b';
                cout << "Bad digit on input";
                infile.ignore(256, '\n');
                decimal = 0;
                BadDigit = true;
                cout << endl;
                
                break;
            }
            infile.get(binum);
        }
        if(!BadDigit)
            cout << setw(85-count) << decimal << endl;
        FirstNum = false;                              //Resets digits for next calculation
        BadDigit = false;
        decimal = 0;
        count  = 0;
        infile.get(binum);
    }
    
}
