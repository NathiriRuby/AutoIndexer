#include <iostream>
#include <cstring>
#include "DSString.h"
using namespace std;

DSString::DSString(): strings(nullptr), length(0), capacity(0){}

DSString::DSString(const char* newStrings)
{   //replace a string with a character array
            for(length=0; newStrings[length]!=0; length++); //measure length by every character in array
            this->capacity=length +1;   //add null character
            strings = new char[capacity];    //create a new char array
            for(int i=0; i<capacity; i++)    //loop for all characters in array
            {
                strings[i]=newStrings[i];  // replace characters
            }
}

DSString::DSString(const DSString& rhs)
{
        char* strings = new char[rhs.capacity]; //create a nw char array
        this->capacity=rhs.capacity;    //take capacity
        this->length=rhs.length;    //take length
        for (int i=0; i<capacity; i++)  //loop through all characters
        {
            strings[i] = rhs.strings[i];    //replace empty char set with imported set
        }
}
DSString& DSString::operator= (const char* rhs)
{
        if(strings!=nullptr)    //if the object exists but empty
        {
            delete[] strings;   //Delete that waste of space
        }
        if(rhs[0]!=NULL)    //if the first character isn't null, then the rest of the array won't be null
        {
            for(length=0; rhs[length]!='\0'; length++); //get the length through other means
            this->length=length;    //set new string's length
            this->capacity=length +1;   //capacity is length+1
            strings = new char[capacity];   //create the array
            for(int i=0; i<capacity; i++)   //loop through
            {
                strings[i]=rhs[i];  //replacing characters
            }
            if(strings[length-1]!='\0')  //ensure last variable is null
            {
                temp[length-1] = '\0';
            }
        }
}

DSString& DSString::operator = (const DSString& rhs)    //set strings
{
    if(this!=&rhs)  //check to make sure that this is the right object
    {
        if (strings!=nullptr)   //if the string is not empty
        {
            delete[] strings;   //delete everything! go, go, go!
        }
        if(rhs.strings!=nullptr)    //as long as the imported string isnn't empty
        {
            strings=new char[rhs.capacity]; //create a new array with the size of the new string
            this->capacity=rhs.capacity;    //set capacity of this string to the new string's
            this->length=rhs.length;    //sset the length of this string to the new string's
            for(int i=0; i<capacity; i++)   //for loop for importing seperate characters
            {
                strings[i]=rhs.strings[i];  //replace the characters
            }
        }
        return *this;   //return the pointer for the new string
    }
}

DSString DSString::operator+ (const DSString& rhs)
{
    int size =(this->length-1) + (rhs.length-1) +1; //size is both of the strings plus 1
    char* temp= new char[size]; //temporary array
    for (int i=0; i<(this->length-1); i++)  //loop
    {
        temp[i]=this->strings[i];   //replace variables with first string's
    }
    //begin second string
    int j=0;
    for(int k = this->length -1; j=0, k<(size-1); k++, j++) //loop for second string
    {
        temp[k]=rhs.strings[j]; //replacing... variables
    }
    if(temp[size-1]!='\0')  //ensure last variable is null
    {
        temp[size-1] = '\0';
    }
    DSString S3(temp);  //set S3;
    delete[] temp;  //delete temp
    return S3;
}

bool DSString::operator== (const char* rhs)
{
    int rhslength;  //because the system didn't recognize the obvious initialization a line below.
    for(rhslength=0; rhs[rhslength]!='\0'; rhslength++);    //REDEFINING LENGTH!

    if(this->length == rhslength)    //if the two strings are the same length
    {
            int length1 = this->length;   //take one of the strings' lengths (They're the same)
            int counter = 0;    //set the counter for same letters
            int i = 0;  //set the initial loop counter to 0
            while(i != length1) //while the loop is still less than the string
            {
                if(this->strings[i] != rhs[i])    //if even a letter is different, then the word is not the same.
                {
                    counter++;  //add to the counter
                }
                i++;    //make sure the loop doesnt redo the same letters
            }
            cout << i << " " << counter << endl;    //test output
            if(counter != 0) //as long as the counter remains 0, then the word is the same
            {
                return false;   //the word was not the same
            }
            else
            {
                return true;    //the word was the same!
            }
     }
    else
    {
        return false;   //word has too many or too few letters. THerefore, not the same word.
    }
}

bool DSString::operator== (const DSString& string2)
{   //compare the lengths of the two strings
    if(this->length == string2.length)    //if the two strings are the same length
    {
            int length1 = this->length;   //take one of the strings' lengths (They're the same)
            int counter = 0;    //set the counter for same letters
            int i = 0;  //set the initial loop counter to 0
            while(i != length1) //while the loop is still less than the string
            {
                if(this->strings[i] != string2.strings[i])    //if even a letter is different, then the word is not the same.
                {
                    counter++;  //add to the counter
                }   
                i++;    //make sure the loop doesnt redo the same letters
            }
            cout << i << " " << counter << endl;    //test output
            if(counter != 0) //as long as the counter remains 0, then the word is the same
            {
                return false;   //the word was not the same
            }
            else
            {
                return true;    //the word was the same!
            }		
     }
    else 
    {
        return false;   //word has too many or too few letters. THerefore, not the same word.
    }
}

bool DSString::operator> (const DSString& rhs)
{
            int length1 = this->length;   //take first string's length
            int length2=  rhs.length;   //take the second string's length
            int counter; //initialize counter
            int i = 0;  //set the initial loop counter to 0
            if(this->strings[0]!=rhs.strings[0])    //if the first letter isn't the same
            {
                if(this->strings[0]>rhs.strings[0]) //test immediately!!!
                    return true;    //this comes before rhs
                else
                    return false;   //rhs comes before this
            }
            if(length1>length2) //this is larger than rhs
            {
                 while(i != length1) //while the loop is still less than the string
                {
                    if(this->strings[i] != rhs.strings[i])    //when a letter is different, mark the place with the counter
                    {
                        if (counter>0)  //the loop found a strange letter
                        {
                            counter=i;  //bookmarked
                        }
                    }
                    i++;    //make sure the loop doesnt redo the same letters
                }
            }
            else    //rhs is longer than this
            {
               while(i != length2) //while the loop is still less than the string
               {
                   if(this->strings[i] != rhs.strings[i])   //when letter is different, mark with counter
                   {
                       if (counter>0)   //strange letter
                       {
                           counter=i;   //bookmarked
                       }
                   }
                   i++;    //make sure the loop doesnt redo the same letters
               }
            }
            cout << i << " " << counter << endl;    //test output
            if (counter==0 && length2>length1)  //this contains the exact same letters as rhs
            {
                return true;    //this has less letters of the same word, therefore, this goes first
            }
            else if (counter==0 && length1>length2) //rhs contains the same letters as this
            {
                return false;   //rhs has less letters than this, therfore, rhs goes first
            }
            else if(counter==0) //(somehow) this and rhs are the same word
            {
                return false;   //neither of them is first
            }
           if(this->strings[counter]>rhs.strings[counter])  //if the strange letter in this is before the strange letter in rhs
           {
               return true; //then this is first
           }
           return false;    //everything else failed, rhs must be first
}

char& DSString::operator[] (const int rhs)  //return the element at a specific spot
{
    return strings[rhs-1];  //yep
}

int DSString::size()    //return the size of the string
{
    return this->length-1;  //yep
}

DSString DSString::substring(int index, int length) //return a part of a string
{
    {
    int size = length+1;    //define size
    char* temp = new char[size];    //new array
    int j = 0;  //initialize j
    for(int i = index, j = 0; i < length; i++, j++) //loop through the indexes
    {
        temp[j] = strings[i];   //replace nulls with characters
    }
    if(temp[size -1] != '\0')   //make sure last spot is null
    {
        temp[size -1] = '\0';
    }
    DSString substringedString; //a variable
    substringedString.length = size;    //that variable's size
    if(substringedString.strings!=nullptr){ //make sure that a non-initialized pointer doesn't exist
        delete[] substringedString.strings;
    }
    substringedString.strings = new char[size]; //create new array
    for(int k = 0; k < (size -1); k++)  //loop through
    {
        substringedString.strings[k] = temp[k]; //take the substringed substring and put the substring that used to be the substring in temp there
    }

    if(substringedString.strings[size-1] != '\0')   //make sure last character is null
    {
        substringedString.strings[size-1] = '\0';
    }
    return substringedString;   //return the substring
    delete[] temp;  //delete temp
    }
}

char* DSString::c_str() //convert string to char array? probably
{
    char* temp=new char[length+1];  //create new array with space
    for(int i=0; i<length; i++) //loop through array
    {
        temp[i]=strings[i]; //replace null characters with real characters
    }
    temp[length+1]='\0';    //put a null at the end
    SString S3(temp);  //set S3
    delete[] temp;  //delete temp
    return S3;    //return S3
}

ostream& operator<< (std::ostream& OS, const DSString& importString)
{
    OS << importString.strings; //send the imported string to the OS
    return OS;  //and then return the OS (is it really that simple???)
}

DSString::~DSString()
{
    if(strings!=nullptr)    //if the string is not empty, delete it!
        delete[] strings;
}


