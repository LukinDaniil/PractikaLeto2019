#ifndef ENUMS_H
#define ENUMS_H
#include "QMetaEnum"

class Enums
{
public:
    Enums();
    enum TypesOfBlocks
    {
        FreeBlock = 0,//свободный блок, на нём ничего нет, по нему можно ходить
        Wall = 1,//блок - препятствие, стена
        Desk = 2,//тоже блок - препятствие, рядом с такими блоками есть места для того, чтобы сидеть
        EntranceToTheUniversity = 3,//блок обозначающий вход в институт
        FreeForStudent = 4,//блок - свободное место для студента на время занятий
        FreeForTeacher = 5,//блок - свободное место для преподавателя на время занятий
        EntranceToTheClassroom = 6,//вход в кабинет
        EntranceToTheCanteen = 7,//вход в столовую
        EntranceToTheToilet = 8,//вход в туалет
        Student = 9,//обозначение студента на карте
        Teacher = 10//обозначение учителя на карте
    };
    Q_ENUMS(TypesOfBlocks)
};

#endif // ENUMS_H
