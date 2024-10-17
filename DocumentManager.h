#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include "Document.h"

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <initializer_list>

class DocumentManager {

 private:
  int numberOfDocuments;
  int numberOfPatrons;
  std::unordered_map<int, std::unordered_set<int>> patrons;
  std::unordered_map<std::string, int> documentList;
  std::unordered_map<int, Document> registry;

 public:
  void addDocument(std::string name, int id, int license_limit);
  void addPatron(int patronID);
  int search(std::string name);
  bool borrowDocument(int docid, int patronID);
  void returnDocument(int docid, int patronID);
};

#endif