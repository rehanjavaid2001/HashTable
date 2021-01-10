//Rehan Javaid, rj3dxu, 10/12/2020, hashTable.cpp

#include "hashTable.h"
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

hashTable::hashTable(){
}

hashTable::hashTable(int size){
  hashVals.resize(size);
}

hashTable::~hashTable(){
  for(int i = 0; i < hashVals.size(); i++){
    delete(hashVals[i]);
  }
}


int hashTable::find(string findVal){ 
  int hash = calculateHashVal(findVal);
  if (hashVals[hash] != nullptr){
    for(list<string>::const_iterator i = (hashVals[hash] -> begin()); i != (hashVals[hash] -> end()); ++i){
      if (*i == findVal){
	return hash;
      }
    }
  }
  int e = end();
  return e;
}

int hashTable::end(){
  int i = hashVals.size();
  return i;
}

void hashTable::insert(string word){
  int location = calculateHashVal(word);
  if (hashVals[location] == nullptr){
    list<string>* listPtr = new list<string>;
    hashVals[location] = listPtr;
    listPtr -> push_front(word);
  }
  else{
    list<string>* l1 = hashVals[location];
    l1 -> push_front(word);
  }
}

//implementation of the djb2 Algorithm for hashing 
int hashTable::calculateHashVal(string hashVal){
  int iVal = 0;
  unsigned long int hash = 5381;
  for (auto x: hashVal){
    iVal = x;
    hash = ((hash << 5) + hash) + iVal;
  }
  return (int)(hash % hashVals.size());
}
    
  // vector<unsigned int> v1(21);
  // v1[0] = 1;
  // for (int i = 1; i < 21; i++){
  //   v1[i] = v1[i-1]*33;
  // }
  // for (int i = 0; i < hashVal.length(); i++){
  //   sum += (int) (hashVal[i] + (hashVal[i] - 'a' + 1)* v1[i]);
  // }
  // int hashValue = sum % hashVals.size();
  // return hashValue; 
//}

