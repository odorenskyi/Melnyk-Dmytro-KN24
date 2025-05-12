#ifndef MODULESMELNYK_H_INCLUDED
#define MODULESMELNYK_H_INCLUDED

#include "struct_type_project_3.h"
#include <vector>
#include <ostream>
#include <string>

void SearchBySurname(const std::vector<PersonRecord>& database, const std::string& surname, std::ostream& out);
void SaveDatabaseToFile(const std::vector<PersonRecord>& database, const std::string& filename);

#endif // MODULESMELNYK_H_INCLUDED
