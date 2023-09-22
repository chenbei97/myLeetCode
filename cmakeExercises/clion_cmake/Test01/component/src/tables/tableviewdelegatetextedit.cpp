#include "../../inc/tables/tableviewdelegatetextedit.h"

QWidget *TableViewDelegateTextEdit::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    TextEdit * textEdit = new TextEdit(parent);
    textEdit->hideTitle();
    textEdit->clearText();
    //textEdit->setReadOnly(true);
    return textEdit;
}

void TableViewDelegateTextEdit::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.model()->data(index,Qt::EditRole | Qt::DisplayRole).toString();
    TextEdit * textEdit = static_cast<TextEdit*>(editor);
    textEdit->setText(text);
}

void TableViewDelegateTextEdit::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{ // 双击的时候才触发这个函数
    TextEdit *textEdit = static_cast<TextEdit*>(editor);
    model->setData(index, textEdit->text(), Qt::EditRole);
}

void TableViewDelegateTextEdit::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

bool TableViewDelegateTextEdit::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
//        auto model = index.model();
//        auto  v = model->data(index, Qt::DisplayRole);
//        if (v.isValid())
//        {
//            TextEdit * dlg = new TextEdit;
//            dlg->hideTitle();
//            dlg->setAttribute(Qt::WA_DeleteOnClose);
//            dlg->resize(800,600);
//            dlg->setText(v.toString());
//            dlg->show();
//        }
//        event->accept();
    }
    return QStyledItemDelegate::editorEvent(event,model,option,index);
}
