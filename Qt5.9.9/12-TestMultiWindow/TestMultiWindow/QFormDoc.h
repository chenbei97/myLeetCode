#ifndef QFORMDOC_H
#define QFORMDOC_H

#include <QWidget>

namespace Ui {
  class QFormDoc;
}

class QFormDoc : public QWidget
{
  Q_OBJECT
private:
    QString mCurrentFile; //当前文件名称
    void initActionToolBar(); // 初始化工具栏的动作,因为界面没有手动添加,这里就使用代码添加
public:
  explicit QFormDoc(QWidget *parent = nullptr);
  ~QFormDoc();
  void    loadFromFile(QString& aFileName); // 从文件中加载

private slots: // 打开和字体2个动作的槽函数,其他动作已经关联了窗体或者QPlainText
  void on_actOpen_triggered();
  void on_actFont_triggered();
private:
  Ui::QFormDoc *ui;
private:
  void closeEvent(QCloseEvent *event) override;
signals:
    void isAboutClosed(bool close);
};

#endif // QFORMDOC_H
