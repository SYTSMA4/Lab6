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

//Precondition:     Include library iostream
//Postcondition:    O
void Heading();

//Precondition:     Include library iostream
//Postcondition:    O
void FileInput(char binum, int decimal);

//Precondition:     Include library iostream
//Postcondition:    O
void Conversion(char binum, int decimal, ifstream& infile);

int main(){
    char binum = 0;
    int decimal = 0;

    Heading();
    FileInput(binum, decimal);
    
    return 0;
}

void Heading(){
    cout << setw(20) << "Binary Number" << setw(30) << "Decimal Equivalent\n";
}

void FileInput(char binum, int decimal){
    ifstream infile;
    infile.open(inputfile);
    
    if(!infile)
        cout << "\nCan't find file\n";
    
    Conversion(binum, decimal, infile);

    infile.close();
}

void Conversion(char binum, int decimal, ifstream& infile){
    int count = 0;
    bool FirstNum = false;
    
    infile.get(binum);
    
    while(infile){
        while(binum != '\n' && infile){
            if((!FirstNum && binum == '1') || (FirstNum && (binum == '1' || binum == '0'))){
                count++;
                FirstNum = true;
                cout << binum;
                decimal *= 2;
                
                if(binum == '1'){
                    decimal++;
                }
            }
            else if((binum != ' ') || (binum  == ' ' && FirstNum)){
                for(int i = 0; i < count; i++)
                    cout << '\b';
                cout << "Bad digit on input";
                infile.ignore(256, '\n');
                decimal = 0;
                break;
            }
            infile.get(binum);
        }
        cout << setw(20) << decimal << endl;
        FirstNum = false;
        decimal = 0;
        count  = 0;
        infile.get(binum);
    }
    
    
}
