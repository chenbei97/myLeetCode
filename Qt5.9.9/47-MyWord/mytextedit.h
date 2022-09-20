#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QFileInfo>
#include <QTextCodec>
#include <QMessageBox>
#include <QPrinter>
#include <QCloseEvent>
#include <QtWidgets>

// QMdiArea的中心区域组件是QTextEdit
// 为了实现多文档的操作管理,需要重载QTextEdit来实现自定义的功能

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget*parent = Q_NULLPTR);
    QString  mCurDocPath; // 当前文档路径
    QString getCurDocName(); // 获取当前文档名称
    void newDoc(); // 新建文档
    bool loadDoc(const QString & docName);//根据文档名称加载文档内容
    bool saveDoc(); // 保存文档
    bool saveAsDoc(); // 另存为文档
    void setDocAlignment(int alignType); // 设置文档对齐方式
    void setDocFormat(const QTextCharFormat &fmt); // 设置文档字体和字号
    void setDocParagraphStyle(int pStyle); // 设置文档段落标号和编号
protected:
    void closeEvent(QCloseEvent * e);
private:
    bool saveDoc(const QString& docName); // 保存文档的具体操作
    bool promptSaveDoc(); // 关闭未保存的文档时提示先保存
    bool mDocSaved; // 文档是否已保存
    void setCurDoc(const QString & docName); // 设置当前文档
};

#endif // MYTEXTEDIT_H
