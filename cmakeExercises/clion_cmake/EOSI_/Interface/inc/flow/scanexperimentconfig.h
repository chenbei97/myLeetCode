#ifndef SCANEXPERIMENTCONFIG_H
#define SCANEXPERIMENTCONFIG_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/widgets/button.h"

/*
 * 类器官和侵袭需要Z轴扫描
 * 类器官的视野数量不可选择，是全视野
 * 划痕视野的形状不同，不是正方形而是十字形
*/

class ScanExperimentConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanExperimentConfig(QWidget *parent = nullptr);
   QString experimentType();
private:
    Button * mProliferation; // 细胞增殖
    Button * mScratch; // 划痕
    Button * mOrganoid;// 类器官
    Button * mPC;// 药效和细胞毒性 Pharmacodynamics and Cytotoxicity
    Button * mInvasion;// 侵袭
    Button * mMorphology;// 形态学
    Button * mTransfection;// 转染
    Label * mCurrentExper;
    QString type;
private:
    void onProliferation();
    void onScratch();
    void onOrganoid();
    void onPC();
    void onInvasion();
    void onMorphology();
    void onTransfection();
signals:

};

#endif // SCANEXPERIMENTCONFIG_H
