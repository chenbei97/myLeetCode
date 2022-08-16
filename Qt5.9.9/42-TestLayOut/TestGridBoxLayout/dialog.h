#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Dialog : public QDialog
{
  Q_OBJECT
public:
  Dialog(QWidget *parent = nullptr);
  ~Dialog();
private: // 涉及的布局有左布局,右布局,底部布局和主布局,主布局包含3个子布局
  // 左布局
  QLabel * UserNameLabel ; // 用户名
  QLabel * NameLabel;// 姓名
  QLabel * SexLabel; // 性别
  QLabel * DepartmentLabel; // 部门
  QLabel * AgeLabel; // 年龄
  QLabel * RemarkLabel; // 备注
  QLineEdit * UserNameEdit;
  QLineEdit * NameEdit;
  QComboBox * SexCombo;
  QLineEdit * DepartmentEdit;
  QLineEdit * AgeEdit;
  QGridLayout * LeftLayout; // 整体栅格布局=左布局
  // 右布局
  QLabel  *HeadLabel;
  QLabel * HeadImage; // 头像
  QPushButton * UpdateHeadImage; // 更新头像
  QHBoxLayout * RightTopLayout; // 头像的3个组件整体水平布局
  QLabel * IntroductionLabel;//自我介绍
  QTextEdit * IntroductionEdit;
  QVBoxLayout * RightLayout; // 水平布局+自我介绍=垂直布局=右布局
  // 底部布局
  QPushButton * OkBtn;
  QPushButton * CancelBtn;
  QHBoxLayout * BottomLayout; // 整体水平布局=底部布局
};
#endif // DIALOG_H
