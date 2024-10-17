#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  registry.emplace(id, Document(name, id, license_limit));
  documentList[name] = id;
  numberOfDocuments++;
}

void DocumentManager::addPatron(int patronID) {
  patrons.emplace(patronID, std::initializer_list<int>{});
  numberOfPatrons++;
}

int DocumentManager::search(std::string name) {
  return (documentList.count(name)) ? documentList[name] : 0;  
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (!patrons.count(patronID)) {
    return false;
  }
  if (!registry.count(docid)) {
    return false;
  } else if (registry[docid].license_limit <= 0) {
    return false;
  }

  patrons[patronID].insert(docid);
  registry[docid].license_limit--;

  return true;
    
}

void DocumentManager::returnDocument(int docid, int patronID) {
  patrons[patronID].erase(docid);
  registry[docid].license_limit++;
}
