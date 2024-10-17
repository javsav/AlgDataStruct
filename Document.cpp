#include "Document.h"

Document::Document(std::string name, int id, int license_limit) : name(name), id(id), license_limit(license_limit) {}

Document::Document() : name(), id(), license_limit() {}