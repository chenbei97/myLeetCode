#ifndef TABLESIZEDIALOG_H
#define TABLESIZEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>
#include <core/enum.h>
#include <QDebug>

class TableSizeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TableSizeDialog(QWidget * parent = Q_NULLPTR);
    enum class Field{SrcVol,SrcCurr,SrcPow,SrcRes,LoadVol,LoadCurr,LoadPow,LoadRes};
    struct LogField{
         QStringList headerString;
         QList<Field> headerField;
    };
    void setCurrentSize(int,int);//让当前行列的设置和外部保持一致
    int row() const;
    int col() const;
    TableSizeDialog::LogField header() const;
private:
    void addFields(bool,QListWidget *);
    QGridLayout * mainLayout;
    QLineEdit * mRowEdit;
    QLineEdit * mColEdit;
    QLineEdit * mHeaderEdit;
    QPushButton * mOkBtn;
    QPushButton * mCancelBtn;
    QListWidget * mSourceFields;
    QListWidget * mLoadFields;
    int mRow;
    int mCol;
    LogField mHeader;
signals:
    void customTableNotImport();
    void customTableUseImport(QStringList&);
    void unCustomTable();
    void workModeChanged(WORKMODE);
};

#endif // TABLESIZEDIALOG_H
