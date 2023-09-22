#ifndef DATETIMEEDIT_H
#define DATETIMEEDIT_H

#include "qdatetimeedit.h"
#include "../public.h"

class COMPONENT_IMEXPORT DateTimeEdit : public QDateTimeEdit
{
    Q_OBJECT
public:
    explicit DateTimeEdit(QWidget *parent = nullptr);
};

#endif // DATETIMEEDIT_H
