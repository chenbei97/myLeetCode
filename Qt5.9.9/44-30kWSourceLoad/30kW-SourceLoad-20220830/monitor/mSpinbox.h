#ifndef MONITORSPINBOX_H
#define MONITORSPINBOX_H

#include <QDoubleSpinBox>
class MonitorSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit MonitorSpinBox(QWidget * parent = Q_NULLPTR);
};
#endif // MONITORSPINBOX_H
