#ifndef ENUMS_H
#define ENUMS_H
#include "QMetaEnum"

class Enums
{
public:
    Enums();
    enum TypesOfBlocks
    {
        FreeBlock = 0,
        Wall = 1,
        Desk = 2,
        Track = 3,
        FreeForStudent = 4,
        FreeForTeacher = 5,
        EntranceToTheClassroom = 6,
        Student = 7,
        Teacher = 8
    };
    Q_ENUMS(TypesOfBlocks)
};

#endif // ENUMS_H
