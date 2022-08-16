#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

class BaseInfo : public QWidget
{
      Q_OBJECT
public:
      explicit BaseInfo(QWidget *parent = nullptr);
private:
      // 左侧布局
      QLabel * UserNameLabel;QLineEdit * UserNameEdit;
      QLabel * NameLabel;QLineEdit * NameEdit;
      QLabel * AgeLabel;QLineEdit * AgeEdit;
      QLabel * DepartLabel; QLineEdit * DepartEdit;
      QLabel * SexLabel; QComboBox * SexCombo;
      QLabel * RemarkLabel; // 备注
      QGridLayout * LeftLayout;
      // 右侧布局
      QLabel * HeadLabel;QLabel * HeadImage;QPushButton * UpdateHeadBtn;
      QHBoxLayout * RightTopLayout;
      QLabel * IntroLabel;QTextEdit * IntroEdit;
      QVBoxLayout * RightLayout;
};
#endif // BASEINFO_H
