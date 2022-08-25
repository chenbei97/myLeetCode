#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QMoveEvent>
#include <QResizeEvent>

class Dialog : public QDialog
{
  Q_OBJECT
public:
    Dialog(QWidget *parent = nullptr);
    void updateLabel();
protected:
    void resizeEvent(QResizeEvent * e) override;
    void moveEvent(QMoveEvent * e) override;
private:
    QLabel * xLabel;
    QLabel * yLabel;
    QLabel * posLabel;
    QLabel * frameGeometryLabel;
    QLabel * frameSizeLabel;
    QLabel * geometryLabel;
    QLabel * sideBarWidthLabel;
    QLabel * titleBarHeightLabel;
    QLabel * rectLabel;
    QLabel * sizeLabel;
    QLabel * widthLabel;
    QLabel * heightLabel;
    QLabel * baseSizeLabel;
    QLabel * sizeHintLabel;
    QLabel * sizeIncrementLabel;

    QLabel * xVLabel;
    QLabel * yVLabel;
    QLabel * posVLabel;
    QLabel * frameGeometryVLabel;
    QLabel * frameSizeVLabel;
    QLabel * geometryVLabel;
    QLabel * sideBarWidthVLabel;
    QLabel * titleBarHeightVLabel;
    QLabel * rectVLabel;
    QLabel * sizeVLabel;
    QLabel * widthVLabel;
    QLabel * heightVLabel;
    QLabel * baseSizeVLabel;
    QLabel * sizeHintVLabel;
    QLabel * sizeIncrementVLabel;

    QGridLayout * mainLayout;
};
#endif // DIALOG_H
