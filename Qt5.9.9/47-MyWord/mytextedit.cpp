#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget*parent):QTextEdit(parent),mDocSaved(false)
{
        setAttribute(Qt::WA_DeleteOnClose); // 子窗口关闭时销毁当前实例
        setFont(QFont("Times New Roman",12)); // 默认跟随窗口字体
}

// 1. 获取文档窗口标题
QString MyTextEdit::getCurDocName()
{
      return QFileInfo(mCurDocPath).fileName();
}

// 2. 新建文档
void MyTextEdit::newDoc()
{
     static int docID = 1; // 窗口编号从1开始,静态的只初始化1次
     mCurDocPath = tr("Word 文档%1").arg(docID++); // 文档路径
     setWindowTitle(mCurDocPath + QStringLiteral("[*]"));
     // QTextDocument的信号contentsChanged()在插入或删除文本或应用格式时就会发射该信号
     connect(document(),&QTextDocument::contentsChanged,this,[=]{
          // 如果文档处于未保存状态则在窗口标题栏显示*号,要求标题有个[*]占位符
          setWindowModified(document()->isModified()); // 借助继承的API实现
     });
}

// 3.  加载文档内容
bool MyTextEdit::loadDoc(const QString & docName)
{
    if (!docName.isEmpty())
    {
        if (!QFile::exists(docName)) return false;
        QFile doc(docName);
        if (!doc.open(QFile::ReadOnly)) return false;
        QByteArray text = doc.readAll();
        QTextCodec *text_codec = Qt::codecForHtml(text);
        QString str = text_codec->toUnicode(text);
        if (Qt::mightBeRichText(str))
        {
            this->setHtml(str);
        } else {
            str = QString::fromLocal8Bit(text);
            this->setPlainText(str);
        }
        setCurDoc(docName);
        connect(document(), &QTextDocument::contentsChanged, this,[=]{setWindowModified(document()->isModified());});
        return true;
    }
    else return false;
}

// 4. 保存文档
bool MyTextEdit::saveDoc()
{
    if (!mDocSaved) return saveAsDoc(); //如果未保存过就保存为新的
    else return saveDoc(mCurDocPath); // 如果已有说明只需要覆盖文件即可
}

// 5. 另存为文档
bool MyTextEdit::saveAsDoc()
{
    QString docName = QFileDialog::getSaveFileName(this, tr("另存为"), // 调用保存文件的对话框自动保存为html文档
                mCurDocPath, tr("HTML 文档 (*.htm *.html);;所有文件 (*.*)"));
    if (docName.isEmpty()) return false;
    else return saveDoc(docName);
}

// 6. 保存的实际操作函数 private
bool MyTextEdit::saveDoc(const QString& docName)
{
    QString name = docName; // 大小写不区分
    if (!(name.endsWith(".htm", Qt::CaseInsensitive) || name.endsWith(".html", Qt::CaseInsensitive)))
    {
        name += ".html";//默认保存为 HTML 文档
    }
    QTextDocumentWriter writer(name);
    bool success = writer.write(this->document());
    if (success) setCurDoc(name);
    return success;
}

// 7. 设置对齐
void MyTextEdit::setDocAlignment(int alignType)
{
    // 左对齐、居中对齐、右对齐和两端对齐
    if (alignType == 1) this->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    else if (alignType == 2) this->setAlignment(Qt::AlignHCenter);
    else if (alignType == 3) this->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    else if (alignType == 4) this->setAlignment(Qt::AlignJustify);
}

// 8. 设置字体字号
void MyTextEdit::setDocFormat(const QTextCharFormat &fmt)
{
      qDebug()<<"called";
      QTextCursor tcursor = this->textCursor(); // 获取文本鼠标对象
      // 选中光标下的单词然后设置格式fmt
      if (!tcursor.hasSelection()) tcursor.select(QTextCursor::WordUnderCursor);
      tcursor.mergeCharFormat(fmt);
      // 通过在编辑器光标上调用 QTextCursor::mergeCharFormat 将修饰符中指定的属性合并为当前字符格式
      this->mergeCurrentCharFormat(fmt);
}

// 9. 设置段落格式
void MyTextEdit::setDocParagraphStyle(int pStyle)
{
    QTextCursor tcursor = this->textCursor();
    if (pStyle != 0)
    {
        QTextListFormat::Style sname = QTextListFormat::ListDisc; // 为列表提供格式信息
        // 列表决定了每个项目的缩进和样式，项目的缩进是一个整数值
        // 它使每个项目从左边距偏移一定量，该值使用 indent() 读取并使用 setIndent() 设置
        switch (pStyle)
        {
            default:
            case 1: // QTextListFormat::Style描述了用于装饰列表项的符号
                sname = QTextListFormat::ListDisc; // 实心圆
                break;
            case 2:
                sname = QTextListFormat::ListCircle; // 空心圆
                break;
            case 3:
                sname = QTextListFormat::ListSquare;// 实心正方形
                break;
            case 4:
                sname = QTextListFormat::ListDecimal;// 按升序排列的十进制值
                break;
            case 5:
                sname = QTextListFormat::ListLowerAlpha;//按字母顺序排列的小写拉丁字符
                break;
            case 6:
                sname = QTextListFormat::ListUpperAlpha;//按字母顺序排列的大写拉丁字符
                break;
            case 7:
                sname = QTextListFormat::ListLowerRoman;//小写罗马数字（仅支持最多 4999 个项目）
                break;
            case 8:
                sname = QTextListFormat::ListUpperRoman;//大写罗马数字（仅支持最多 4999 个项目）
                break;
        }
        // 指示文档上的一组编辑操作的开始，从撤消/重做的角度来看，该操作应显示为单个操作
        tcursor.beginEditBlock();
        QTextBlockFormat tBlockFmt = tcursor.blockFormat();
        QTextListFormat tListFmt;
        if (tcursor.currentList())//如果光标位置（）在作为列表一部分的块内，则返回当前列表；否则返回 0
        {
            tListFmt = tcursor.currentList()->format();//#include <QtWidgets>
        } else {
            tListFmt.setIndent(tBlockFmt.indent() + 1);
            tBlockFmt.setIndent(0);
            tcursor.setBlockFormat(tBlockFmt);
        }
        tListFmt.setStyle(sname);
        tcursor.createList(tListFmt);
        tcursor.endEditBlock();
    } else {
        QTextBlockFormat tbfmt;
        tbfmt.setObjectIndex(-1);
        tcursor.mergeBlockFormat(tbfmt);
    }
}


// 10. 关闭窗口事件
void MyTextEdit::closeEvent(QCloseEvent *e)
{
     promptSaveDoc()?e->accept():e->ignore(); // 已保存接收未保存拒绝
}

// 11. 点击关闭文档时的确认保存
bool MyTextEdit::promptSaveDoc()
{
    if (!document()->isModified()) return true; // 如果没有修改过返回true
    QMessageBox::StandardButton result;
    result = QMessageBox::warning(this, tr("我的文档"), tr("文档'%1'已被更改,保存吗?").arg(getCurDocName()), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (result == QMessageBox::Save) return saveDoc();
    else if (result == QMessageBox::Cancel) return false;
    return true;
}

// 12. 设置当前文档
void MyTextEdit::setCurDoc(const QString &docName)
{
    mCurDocPath = QFileInfo(docName).canonicalFilePath();
    mDocSaved = true;//文档已经被保存过
    document()->setModified(false);//文档未被改动
    setWindowModified(false);//窗口不显示被改动标识
    setWindowTitle(getCurDocName() + "[*]");//设置文档名为子窗口标题
}
