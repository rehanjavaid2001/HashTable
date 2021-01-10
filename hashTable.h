//Rehan Javaid, rj3dxu, 10/12/2020, hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include <list> 

using namespace std;

class hashTable{
 public: 
   hashTable();

   hashTable(int size); 
   
  ~hashTable();

  int find(string findVal);

  int end();

  void insert(string word);

  int calculateHashVal(string hashVal);

private:
  
  vector<list<string>*> hashVals;
};

#endif 
