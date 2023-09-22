#include "../../inc/widgets/textedit.h"

TextEdit::TextEdit(QWidget * parent) :QWidget(parent)
{
    mTitle = new LineEdit(tr("实验名称: ..."));
    mText = new QTextEdit;
    mText->setFontPointSize(DefaultFontSize);
    mText->setFontFamily(DefaultFontFamily);
    mText->setText(tr("备注实验的描述信息...")); // 先设置格式再设置文字才起作用
    mText->setUndoRedoEnabled(false); // 防止加载大文本比如10MB卡死
    mText->setCurrentFont(QFont(DefaultFontFamily,DefaultFontSize));

    mLay = new QVBoxLayout;
    mLay->addWidget(mTitle);
    mLay->addWidget(mText);
    mLay->setMargin(0);
    mLay->setSpacing(0);

    setLayout(mLay);
    INIT_FONT;
}

void TextEdit::hideTitle()
{
    mTitle->hide();
}

void TextEdit::showTitle()
{
    mTitle->show();
}

void TextEdit::setTitle(const QString& title)
{
    mTitle->setReadOnly(true);
    mTitle->setText(title);
}

QString TextEdit::title() const
{
    return mTitle->text();
}

void TextEdit::setReadOnly(bool r)
{
    mText->setReadOnly(r);
}

void TextEdit::setText(const QString&text)
{
    mText->setText(text);
}

QString TextEdit::text() const
{
    return mText->toPlainText();
}

void TextEdit::append(const QString& label,const QString& text, const QColor& color)
{
    mText->append(tr("<strong><font color = %1>%2:</font></strong> %3")
                  .arg(color.name()).arg(label).arg(text));
}

void TextEdit:: clearText()
{
    mText->clear();
}

void TextEdit::closeEvent(QCloseEvent *event)
{
    emit textChanged(text());
    event->accept();
}
