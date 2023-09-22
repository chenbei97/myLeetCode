#ifndef DATEEDIT_H
#define DATEEDIT_H

#include "qdatetimeedit.h"
#include "../public.h"

class COMPONENT_IMEXPORT DateEdit : public QDateEdit
{
    Q_OBJECT
public:
    explicit DateEdit(QWidget*parent = nullptr);
};

#endif // DATEEDIT_H
