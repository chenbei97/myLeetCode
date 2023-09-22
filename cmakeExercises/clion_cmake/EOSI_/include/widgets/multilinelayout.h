#ifndef MULTILINELAYOUT_H
#define MULTILINELAYOUT_H

#include "dualcolumnicon.h"
#include "../public.h"

class COMPONENT_IMEXPORT MultilineLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    enum MarginType {LeftMargin,Gap1,Gap2,RightMarigin,Height};
    explicit MultilineLayout(const QList<QVector<QWidget*>>& items ,const QMap<MarginType,int> margins);
};

#endif // MULTILINELAYOUT_H
