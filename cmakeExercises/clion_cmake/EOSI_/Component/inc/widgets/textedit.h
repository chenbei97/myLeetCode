#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "label.h"
#include "qtextedit.h"
#include "lineedit.h"

class COMPONENT_IMEXPORT TextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit TextEdit(QWidget * parent=nullptr);
    void closeEvent(QCloseEvent *event) override;

    void hideTitle();
    void showTitle();
    void setTitle(const QString& title);
    QString title() const;

    void setReadOnly(bool r);

    QString text() const;
    void setText(const QString& text);
    void clearText();

    void append(const QString& label,const QString& text, const QColor& color = "#75FA8D");
private:
     QVBoxLayout * mLay;
     QTextEdit * mText;
     LineEdit * mTitle;
signals:
     void textChanged(const QString& text);
};

#endif // TEXTEDIT_H
