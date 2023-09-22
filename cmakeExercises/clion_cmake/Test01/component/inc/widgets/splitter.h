#ifndef SPLITTER_H
#define SPLITTER_H

#include "qsplitter.h"
#include "../public.h"

class COMPONENT_IMEXPORT Splitter : public QSplitter
{
    Q_OBJECT
public:
    explicit Splitter(Qt::Orientation orientation, QWidget *parent = nullptr);
    explicit Splitter(QWidget *parent = nullptr);
};

#endif // SPLITTER_H
