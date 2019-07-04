#ifndef TIMESHEET_H
#define TIMESHEET_H

#include "list"
#include <QFile>
#include <QString>
#include "string"
#include "ctime"
#include <QTextCodec>
// важные константы
#define COUNTTIMES 6
#define COUNTDAY 5
#define MAXNUMLESSONSINDAY 6
#define MAXTEACHERSNAMES 16
#define MAXLESSONSNAMES 20
using namespace std;
// Названия предметов и преподов случайны и носят преднамеренный характер
const string LessonsNames[20] =
{
    "Алгоритмы и структуры данных",
    "Архитектура вычислительных систем",
    "Операционные системы",
    "Современная научная картина мира",
    "Философия",
    "Иностранный язык",
    "Экономика",
    "Физическое воспитание",
    "Математический анализ",
    "Физические основы электроники",
    "Социально-психологические основы общения",
    "Дискретная математика",
    "Введение в информатику",
    "Объектно-ориентированное программирование",
    "Периферийные устройства",
    "Бизнес-планирование",
    "Основы предпринимательской деятельности",
    "Теоретические основы информатики",
    "История",
    "Безопасность жизнедеятельности"
};
const string TeachersNames[16] =
{
       "Бубнова Н.Д.", "Боровцов Е.Г.",  "Троицкий В.С.", "Попов А.В", "Васильев С.Ф.", "Рогозина И.В.",
    "Данильчик Т.Л.", "Пацюк С.И.", "Киркинский А.С.", "Шупта М.А", "Перепелкин Д.А.", "Старолетов С.А",
    "Казанцева Л.Г.Б.Т", "Асахова Е.В", "Литвинова О.Н", "Вишняк М.А"

};
const string timeOfLesson[6] =
{
    "8:15-9:45", "9:55-11:25", "11:35-13:05", "13:35-15:05", "15:15-16:45", "16:55-18:25"
};
struct Lesson
{
public:
    QString Name;
    QString TeachersName;
    int NumCabinet;
    QString ToString()
    {
        QString rez = Name;
        rez += " * * ";
        rez += TeachersName;
        rez += " * * *";
        rez += NumCabinet;
        return rez;

    }
};


class Timesheet
{
private:
    vector<vector<Lesson>> SchoolDay;
public:
    void SetDay(int index, list<Lesson> NewLessons);
    void SetRandomDay(int index);
    void SetRandomTimesheet();
    void ReadTimesheet(QString WayToFile);
    vector<QString> ToString();
    Timesheet();
};

#endif // TIMESHEET_H
