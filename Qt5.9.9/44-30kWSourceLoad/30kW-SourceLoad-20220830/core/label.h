#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget * parent = Q_NULLPTR);
    explicit Label(const char* text="",QWidget * parent = Q_NULLPTR);
    explicit Label(const QString & text,QWidget * parent = Q_NULLPTR);
private:
    void init();
};
#endif // LABEL_H
