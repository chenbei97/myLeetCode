#ifndef MYCUSTOMSTRUCT_H
#define MYCUSTOMSTRUCT_H
#include <QObject>
#include <QWidget>
struct MyCustomStruct :QObject {
    Q_OBJECT
public:
    MyCustomStruct();
    MyCustomStruct(const int id,float data,QString name);
    MyCustomStruct(const MyCustomStruct &rhs);
    ~MyCustomStruct();
    int id;
    float data;
    QString name;
};
#endif // MYCUSTOMSTRUCT_H
