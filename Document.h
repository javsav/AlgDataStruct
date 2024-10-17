#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

struct Document {

  std::string name;
  int id;
  int license_limit;  
  Document(std::string name, int id, int license_limit);
  Document();


};

#endif