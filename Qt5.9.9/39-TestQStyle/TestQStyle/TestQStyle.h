#ifndef TESTQSTYLE_H
#define TESTQSTYLE_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class TestQStyle; }
QT_END_NAMESPACE
class TestQStyle : public QMainWindow
{
  Q_OBJECT
public:
  explicit TestQStyle(QWidget *parent = nullptr);
  ~TestQStyle();
private slots:
  void on_comboSysStyle_currentIndexChanged(const QString& arg1);
  void on_btnCancelStyleSheet_clicked();
  void on_btnSetStyleSheet_clicked();
  void on_btnFontLarge_clicked();

  void on_btnFontSmall_clicked();

private:
  Ui::TestQStyle *ui;
};
#endif // TESTQSTYLE_H
