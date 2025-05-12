#ifndef MODULESMYRONENKO_H_INCLUDED
#define MODULESMYRONENKO_H_INCLUDED

#include "struct_type_project_3.h"
#include <vector>
#include <ostream>
#include <string>

void PrintDatabase(const std::vector<PersonRecord>& database, std::ostream& out);
void AddPersonalCard(std::vector<PersonRecord>& database);

#endif // MODULESMYRONENKO_H_INCLUDED
