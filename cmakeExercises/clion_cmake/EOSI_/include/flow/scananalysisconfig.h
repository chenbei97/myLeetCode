#ifndef SCANANALYSISCONFIG_H
#define SCANANALYSISCONFIG_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/widgets/spinbox.h"
#include "../../../include/widgets/textedit.h"
#include "../../../include/widgets/label.h"



class SpectralUnmixing : public QWidget
{
    Q_OBJECT
public:
    explicit SpectralUnmixing(QWidget *parent = nullptr);
    explicit SpectralUnmixing(const QString &text,QWidget *parent = nullptr);
    void setText(const QString &text);
    double value() const;
private:
    SpinBox * spinbox;
    Label * label;
};

class ScanAnalysisConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanAnalysisConfig(QWidget *parent = nullptr);
    QString analysisType() const;
    QString analysisDefinition() const;
    double spectralUnmixPercentOf1() const;
    double spectralUnmixPercentOf2() const;
    QString analysisNotes() const;
private:
    ComboBox * mAnaType;
    ComboBox * mAnaDefine;
    SpectralUnmixing * mSpectralFirst;
    SpectralUnmixing * mSpectralSecond;
    QTextEdit * mNotes;
signals:

};

#endif // SCANANALYSISCONFIG_H
