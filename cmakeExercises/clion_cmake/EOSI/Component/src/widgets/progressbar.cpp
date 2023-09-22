#include "../../inc/widgets/progressbar.h"

ProgressBar::ProgressBar(QWidget * parent) :QProgressBar(parent)
{
        setRange(0,100);
        setValue(50);
        setAlignment(Qt::AlignCenter);
        setStyleSheet(ProgressBarStyle);
        INIT_PROGRESSBAR_MINSIZE;
        INIT_FONT;
}
