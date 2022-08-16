#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QLabel>
class Detail : public QWidget
{
      Q_OBJECT
public:
      explicit Detail(QWidget *parent = nullptr);
private:
      QLabel * NationLabel;QComboBox *NationCombo;
      QLabel * ProvinceLabel;QComboBox * ProvinceCombo;
      QLabel * CityLabel; QLineEdit * CityEdit;
      QLabel * IntroLabel; QTextEdit * IntroEdit;
      QGridLayout * mainLayout;
};
#endif // DETAIL_H
