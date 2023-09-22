#ifndef SCANWELLCONFIG_H
#define SCANWELLCONFIG_H

#include "widgets/gradienthiddenwidget.h"
#include "widgets/lineedit.h"
#include "widgets/pushbutton.h"
#include "widgets/listwidgetitem.h"
#include "widgets/groupbox.h"
#include "widgets/pattern.h"
#include "widgets/combobox.h"
#include "scangroupdata.h"
#include "qlistwidget.h"

class ScanWellConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanWellConfig(QWidget *parent = nullptr);
    void setPatternSize(int rows,int cols);
    bool allEmptyGroup();
    int groupCount() const;
    int groupPointCount(int group) const;
    int pointCount() const;
    bool hasEmptyGroup() const;
    GroupDataVector groupDatas() const;
    void clearState();
private:

     ScanGroupData *  mGroupData;
     Pattern * mPattern;

     GroupBox * mLeftBox;
     GroupBox * mRightBox;

     QListWidget * mGroupList;
     PushButton * mAddGroup;
     LineEdit * mGroupName;
     PushButton * mRemoveGroup;
     PushButton * mRemoveAllGroups;

     Label * mCurrentGroup;
     PushButton * mAddPoint;
     LineEdit * mPointName;
     PushButton * mRemovePoint;
     PushButton * mRemoveAllPoints;
     QListWidget *  mPointList;
private:
     void initObject();
     void initAttributes();
     void initLeftLayout();
     void initRightLayout();
     void initConnections();
private slots:
     void onAddGroup();
     void onRemoveGroup();
     void onRemoveAllGroups();
     void onAddPoint();
     void onRemovePoint();
     void onRemoveAllPoints();
     void onGroupCurrentRowChanged(int row);
signals:


};

#endif // SCANWELLCONFIG_H
