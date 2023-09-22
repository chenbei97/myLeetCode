#ifndef SCANWELLPREVIEW_H
#define SCANWELLPREVIEW_H

#include "widgets/gradienthiddenwidget.h"
#include "widgets/pattern.h"
#include "widgets/pushbutton.h"
#include "widgets/groupbox.h"
#include "utilities/randomcolor.h"
#include "widgets/textedit.h"
#include "widgets/imageviewer.h"
#include "utilities/loadpix.h"
#include "scangroupdata.h"

typedef struct {
    QString group;
    QPoint pos;
    QString name;
    int order;
}PointData;
typedef  QVector<PointData> QPointDataVector;
typedef  const QPointDataVector& QCPointDataVector;

class ScanWellPreview : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanWellPreview(QWidget *parent = nullptr);
    void setPatternSize(int rows,int cols);
    void setViews(int views);
    void setGroupDatas(const GroupDataVector&d);
    void clearState();
private:
    void initObject();
    void initAttributes();
    void initConnections();
    void initLeftLayout();
    void initRightLayout();
private:
    QPointVector points(int group) const;
    QStringVector pointNames(int group) const;
    void setFakeData();
    void splitGroupDatas();
    void drawGroupPoints();
    void updateInfo();
    void showAllInfo();
    void getSortPointDatas();
    void printSortPointDatas();
    QPair<int,int> getPointIndexInGroupDatas(QCPoint point) const;
private slots:
    void onPreview();
    void onPatternClicked(const QPoint& point);
    void updatePatternSignedPoint(int index);
    void onDeletePoint();
private:
     QAction * mDeletePoint;
     Pattern * mPattern;
     GroupBox * mLeftBox;
     GroupBox * mRightBox;

     Label * mGroupName;
     Label * mPointPos;
     Label * mPointName;
     Label * mPointOrder;
     TextEdit * mAllInfo;
     PushButton * mPreviewBtn;

     ImageViewer* mPicture;
private:
     int mViews;
     GroupDataVector mGroupData;
     QGroupNameVector mGroupNames;
     QGroupPointVector mPointVector;
     QGroupPointNameVector mPointNameVector;
     QPointDataVector mSortPointDatas;
signals:

};

#endif // SCANWELLPREVIEW_H
