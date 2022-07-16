#ifndef FORMDOC_H
#define FORMDOC_H

#include <QWidget>

// 不同于多窗口设计提到的QFormDoc,移除了工具栏,只提供一些公共函数便于访问
// 因为工具栏主窗口设计了,可以操作本窗口
namespace Ui {
class FormDoc;
}

class FormDoc : public QWidget
{
    Q_OBJECT
private:
    QString mCurrentFile; //当前文件
    bool    mFileOpened; //文件是否打开
public: // 提供给主窗口使用的公共函数,这样可以直接操作子窗口的plaintext组件
    void    loadFromFile(QString& aFileName); //打开文件
    QString currentFileName() const;//返回当前文件名
    bool    isFileOpened() const;//文件已经打开
    void    setEditFont();//设置字体
    void    textCut(); //cut
    void    textCopy(); //copy
    void    textPaste(); //paste
public:
    explicit FormDoc(QWidget *parent = nullptr);
    ~FormDoc();

private:
    Ui::FormDoc *ui;
};

#endif // FORMDOC_H
