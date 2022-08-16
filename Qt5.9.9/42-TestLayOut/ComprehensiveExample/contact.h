#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
class Contact : public QWidget
{
      Q_OBJECT
public:
      explicit Contact(QWidget *parent = nullptr);
private:
      // 邮箱,地址,邮政编码,手机(接收留言),座机
      QLabel * EmailLabel; QLineEdit * EmailEdit;
      QLabel * AddrLabel; QLineEdit * AddrEdit;
      QLabel * CodeLabel; QLineEdit * CodeEdit;
      QLabel * PhoneLabel;QLineEdit * PhoneEdit;QCheckBox * AcceptInfoCheckBox;
      QLabel * LandTelLabel;QLineEdit * LandTelEdit;

      QGridLayout * mainLayout;
};
#endif // CONTACT_H
