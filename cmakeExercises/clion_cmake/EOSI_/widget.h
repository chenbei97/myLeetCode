//
// Created by chenbei on 2023/9/21.
//

#ifndef EOSI_WIDGET_H
#define EOSI_WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;
};


#endif //EOSI_WIDGET_H
