#ifndef TESTFILEDIROPERA_H
#define TESTFILEDIROPERA_H

#include <QDialog>
#include <QFileSystemWatcher>

namespace Ui {
  class TestFileDirOpera;
}

class TestFileDirOpera : public QDialog
{
  Q_OBJECT

public:
  explicit TestFileDirOpera(QWidget *parent = nullptr);
  ~TestFileDirOpera();

private slots:
  // 打开文件、打开目录和清除文本框
  void on_pushButton_41_clicked();
  void on_pushButton_45_clicked();
  void on_pushButton_5_clicked();

  // QCoreApplication的API
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_61_clicked();
  void on_pushButton_40_clicked();
  // QFile的API
  void on_pushButton_48_clicked();
  void on_pushButton_51_clicked();
  void on_pushButton_49_clicked();
  void on_pushButton_50_clicked();
  void on_pushButton_53_clicked();
  void on_pushButton_54_clicked();
  void on_pushButton_55_clicked();
  void on_pushButton_56_clicked();
  // QFileInfo的API
  void on_pushButton_28_clicked();
  void on_pushButton_29_clicked();
  void on_pushButton_33_clicked();
  void on_pushButton_34_clicked();
  void on_pushButton_38_clicked();
  void on_pushButton_37_clicked();
  void on_pushButton_30_clicked();
  void on_pushButton_31_clicked();
  void on_pushButton_39_clicked();
  void on_pushButton_32_clicked();
  void on_pushButton_42_clicked();
  void on_pushButton_43_clicked();
  void on_pushButton_35_clicked();
  void on_pushButton_58_clicked();
  void on_pushButton_36_clicked();
  void on_pushButton_44_clicked();
  void on_pushButton_59_clicked();
  void on_pushButton_27_clicked();
  // QDir的API
  void on_pushButton_10_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_60_clicked();
  void on_pushButton_20_clicked();
  void on_pushButton_24_clicked();
  void on_pushButton_22_clicked();
  void on_pushButton_23_clicked();
  void on_pushButton_26_clicked();
  void on_pushButton_12_clicked();
  void on_pushButton_13_clicked();
  void on_pushButton_14_clicked();
  void on_pushButton_15_clicked();
  void on_pushButton_19_clicked();
  void on_pushButton_18_clicked();
  void on_pushButton_16_clicked();
  void on_pushButton_11_clicked();
  void on_pushButton_17_clicked();
  // QTemporaryDir的API
  void on_pushButton_21_clicked();
  // QTemporaryFile的API
  void on_pushButton_25_clicked();
  // QFileSystemWatcher的API
  void on_pushButton_46_clicked(); // 监听目录
  void on_directoryChanged(const QString path); // 目录变化槽函数
  void on_fileChanged(const QString path); // 文件变化槽函数
  void on_pushButton_47_clicked();
  void on_pushButton_52_clicked();
  void on_pushButton_57_clicked();
private:
  Ui::TestFileDirOpera *ui;
  void showBtnInfo(QObject *btn);
  QFileSystemWatcher * fileWatcher;
};

#endif // TESTFILEDIROPERA_H
