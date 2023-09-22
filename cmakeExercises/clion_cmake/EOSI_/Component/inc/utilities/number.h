#ifndef NUMBER_H
#define NUMBER_H

#include "qregexp.h"

static bool isNumeric(const QString& str)
{
    QRegExp regex("\\d+");
    return regex.exactMatch(str);
}

#endif // NUMBER_H
