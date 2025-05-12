#ifndef STRUCT_TYPE_PROJECT_3_H_INCLUDED
#define STRUCT_TYPE_PROJECT_3_H_INCLUDED

#include <string>
using std::string;

struct Date {
    short day{0};
    short month{0};
    short year{0};
};

enum EducationLevel {
    BasicSecondary,
    CompleteSecondary,
    Vocational,
    IncompleteHigher,
    BasicHigher,
    Higher
};

struct WorkExperience {
    short days{0};
    short months{0};
    short years{0};
};

struct PersonRecord {
    Date created;
    int registrationNumber{-1};
    int identifier{-1};
    char sex{'m'};
    char workType{'f'};
    string name;
    Date birth;
    string nationality;
    EducationLevel education[4]{};
    string educationInstitutions[4];
    string previousWorkplace;
    string previousPosition;
    WorkExperience experience;
    string address;
    string passportDetails;
    string extraInfo;
    Date terminationDate;
    string terminationReason;
};

#endif // STRUCT_TYPE_PROJECT_3_H_INCLUDED
