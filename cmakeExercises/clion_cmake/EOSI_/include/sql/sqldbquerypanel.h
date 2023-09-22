#ifndef SQLDBQUERYPANEL_H
#define SQLDBQUERYPANEL_H

#include "../../../include/widgets/pushbutton.h"
#include "../../../include/widgets/lineedit.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/widgets/dateedit.h"
#include "../../../include/widgets/groupbox.h"
#include "qstatusbar.h"

class SqlDBQueryPanel : public QWidget
{
    Q_OBJECT
public:
    explicit SqlDBQueryPanel(QWidget *parent = nullptr);
public slots:
    void showQueryResult(const QString&result);
    void updateCommand(const QString&table,const QStringList&fields);
    void updateKeywords(const QString&table,const QStringList&fields);
private:
    DateEdit * mStartDateEdit;
    DateEdit * mEndDateEdit;
    ComboBox * mTableFields;
    ComboBox * mSymbols;
    LineEdit * mKeyWordEdit;
    PushButton * mFilterBtn;
    LineEdit * mPanel;
    ComboBox * mCommand;
    PushButton * mExecBtn;
    PushButton * mClearBtn;
    QStatusBar * mStatusBar;
    GroupBox* initleft();
    GroupBox* initright();
private slots:
    void onDateChanged();
    void onFieldChanged(const QString& field);
    void onTextEdited(const QString& text);
    void onFilterBtn();
    void onQueryBtn();
    void onCommandChanged(const QString& command);

signals:
    void queryCommand(const QString& q);
    void filterField(const QString& field,const QString& key);
    void dateChanged(const QString& start,const QString& end);
};

#endif // SQLDBQUERYPANEL_H
