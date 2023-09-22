#include "../../inc/widgets/combobox.h"

ComboBox::ComboBox(QWidget*parent):QComboBox(parent),mLineEdit(new LineEdit)
{
    setEditable(false);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

ComboBox::ComboBox(const QString&text,QWidget*parent):QComboBox(parent)
{
    addItem(text);
    setEditable(false);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

ComboBox::ComboBox(const QStringList&texts,QWidget*parent):QComboBox(parent)
{
    addItems(texts);
    setEditable(false);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

void ComboBox::setAlignment(Qt::Alignment align)
{
    mLineEdit->setAlignment(align);
    QStandardItemModel * model = qobject_cast<QStandardItemModel*>(this->model());
    for (int row = 0; row < model->rowCount(); ++row)
    {
        QStandardItem * item = model->item(row);
        item->setTextAlignment(align);
    }
}

void ComboBox::toggleLineEdit()
{
        mLineEdit->setAlignment(Qt::AlignCenter);
        mLineEdit->setReadOnly(true);
        QFont font = mLineEdit->font(); // 让combobox显示正常的字体,因为替换了代理
        font.setFamily(DefaultFontFamily);
        font.setPointSize(DefaultFontSize);
        mLineEdit->setFont(font);
        setLineEdit(mLineEdit);
}
