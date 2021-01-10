//Rehan Javaid, rj3dxu, 10/12/2020, wordPuzzle.cpp

#include "timer.h"
#include "hashTable.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);

string getWordInGrid(int startRow, int startCol, int dir, int len,int numRows, int numCols);

bool checkprime(unsigned int p);

int getNextPrime (unsigned int n);

int makePrime(string filename);

hashTable readFile(string filename){
  int size = makePrime(filename); 
  hashTable h1((int)size/(.61)); 
  string word; 
  fstream wordsFile(filename);
  while (wordsFile >> word){
    h1.insert(word);
  } 
  return h1; 
}

int makePrime(string filename){
  vector<string> v1;
  string word;
  fstream wordsFile(filename);
  while (wordsFile >> word){
    v1.push_back(word);
  }
  int size = v1.size();
  if (checkprime(size) == false){
    size = getNextPrime(size);
  }
  return size;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
   
    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}


void findWords(string filename, string gridFileName, int rows, int cols){
  hashTable h1 = readFile(filename);
  int count = 0; 
  int numRows = rows;
  int numCols = cols;
  vector<string> printVect; 
  if(readInGrid(gridFileName, rows, cols) == true){
    for(int r = 0; r < rows; r++){
      for (int c = 0; c < cols; c++) { 
	for (int lenWord = 3; lenWord <= 22; lenWord++){
	  string s = getWordInGrid(r,c,0,lenWord,numRows,numCols);
	  if (h1.find(s) != h1.end() && s.length() == lenWord){
	    string foundW = "N (" + to_string(r) + ", " + to_string(c) + "): " + s;
	    printVect.push_back(foundW);
	    count++;
	  }
	  string s1 = getWordInGrid(r,c,1,lenWord,numRows,numCols);
	  if (h1.find(s1) != h1.end() && s1.length() == lenWord){
	    string foundW = "NE(" + to_string(r) + ", " + to_string(c) + "): " + s1;
	    printVect.push_back(foundW);
	    count++;
	  }
	  string s2 = getWordInGrid(r,c,2,lenWord,numRows,numCols);
	  if (h1.find(s2) != h1.end() && s2.length() == lenWord){
	    string foundW = "E (" + to_string(r) + ", " + to_string(c) + "): " + s2;
	    printVect.push_back(foundW);
	    count++;
	  }
	  string s3 = getWordInGrid(r,c,3,lenWord,numRows,numCols);
	  if (h1.find(s3) != h1.end() && s3.length() == lenWord){
	    string foundW = "SE(" + to_string(r) + ", " + to_string(c) + "): "  + s3;
	    printVect.push_back(foundW); 
	    count++;
	  }
	  string s4  = getWordInGrid(r,c,4,lenWord,numRows,numCols);
	  if (h1.find(s4) != h1.end() && s4.length() == lenWord){
	    string foundW = "S (" + to_string(r) + ", " + to_string(c) + "): "+ s4;
	    printVect.push_back(foundW);
	    count++;
	  }
	  string s5 = getWordInGrid(r,c,5,lenWord,numRows,numCols);
	  if (h1.find(s5) != h1.end() && s5.length() == lenWord){
	    string foundW =  "SW(" + to_string(r) + ", " + to_string(c) + "): " + s5;
	    printVect.push_back(foundW); 
	    count++;
	  }
	  string s6 = getWordInGrid(r,c,6,lenWord,numRows,numCols);
	  if (h1.find(s6) != h1.end() && s6.length() == lenWord){
	    string foundW =  "W (" + to_string(r) + ", " + to_string(c) + "): " + s6 ;
	    printVect.push_back(foundW);
	    count++;
	  }
	  string s7 = getWordInGrid(r,c,7,lenWord,numRows,numCols);
	  if (h1.find(s7) != h1.end() && s7.length() == lenWord){
	    string foundW =  "NW(" + to_string(r) + ", " + to_string(c) + "): " + s7;
	    printVect.push_back(foundW);
	    count++;
	  }
	}
      }
    }
  }
  for (int i = 0; i < printVect.size(); i++){
    cout << printVect[i] << endl;
  }
  cout << count << " words found" << endl;
}
	  
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}


int main(int argc, char* argv[]){

  int numberRows = 0;
  int numberCols = 0;
  
  string dictionaryWords = argv[1];
  string gridText = argv[2];
  
  string num1;
  string num2; 
  string line;
  ifstream gridFile(gridText);
  if (gridFile.is_open()){
      getline(gridFile, line);
      num1 = line;
      getline(gridFile, line);
      num2 = line;
  }
  gridFile.close();
  
  if (num1.length() == 1){
    numberRows = stoi(num1);
  }
  if (num1.length() > 1){
    numberRows = stoi(num1);
  }
  if (num2.length() == 1){
    numberCols = stoi(num2);
  }
  if (num2.length() > 1){
    numberCols = stoi(num2);
  }
  timer t1;
  t1.start();
  findWords(dictionaryWords, gridText, numberRows, numberCols);
  t1.stop();
  return 0; 
}


