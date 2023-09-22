#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "qprogressbar.h"
#include "../public.h"

class COMPONENT_IMEXPORT ProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget * parent = nullptr);
};

#endif // PROGRESSBAR_H
