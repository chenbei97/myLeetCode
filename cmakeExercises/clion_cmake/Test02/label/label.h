//
// Created by chenbei on 2023/9/20.
//

#ifndef TEST5_LABEL_H
#define TEST5_LABEL_H

//#include <QLabel>
#include "qlabel.h"
class  label : public QLabel{
public:
    explicit label(const QString& text,QWidget*parent = 0);
};


#endif //TEST5_LABEL_H
