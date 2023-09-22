#ifndef IMAGECONTROLBAR_H
#define IMAGECONTROLBAR_H

#include "pushbutton.h"

class COMPONENT_IMEXPORT ImageControlBar : public QWidget
{
    Q_OBJECT
public:
    explicit ImageControlBar(QWidget * parent = nullptr);
private slots:
    void on_forwardButton_clicked();
    void on_backButton_clicked();
private:
    QPushButton *forwardButton;
    QPushButton *backButton;
signals:
    void back();
    void next();
};

#endif // IMAGECONTROLBAR_H
