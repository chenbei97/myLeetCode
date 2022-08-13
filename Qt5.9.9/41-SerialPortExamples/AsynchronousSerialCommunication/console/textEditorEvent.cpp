#include "terminalTextEditor.h"
#include <QPainter>
#include <QTime>
#include <QDebug>

// 1. 上下文菜单事件
void terminalTextEditor::contextMenuEvent(QContextMenuEvent *e)
{
       // QPlainTextEdit::contextMenuEvent(e); // 如果不想定义自己的菜单事件,可以直接转交给父类的菜单事件处理方法
       // 这里不希望出现菜单事件,就可以不转交,只是写入文本编辑监控器
        QString reason = "Other";
        switch (e->reason())
        {
                case QContextMenuEvent::Mouse : reason = "Mouse";break;
                case QContextMenuEvent::Keyboard : reason = "Keyboard";break;
                default:break;
        }
        QString info = " contextMenuEvent is called, reason is " + reason + ", the function is disabled!";
        emit eventInformation(QTime::currentTime().toString()+info);
}


//  2. 显示事件
void terminalTextEditor::showEvent(QShowEvent *e)
{

       QString info = " showEvent is called, the function works fine!";
       emit eventInformation(QTime::currentTime().toString()+info);
}

// 3. 绘制事件
void terminalTextEditor::paintEvent(QPaintEvent *e)
{
    QRect rect = e->rect();
    int x  = rect.x(), y = rect.y();
    int height = rect.height(), width = rect.width();

    QString info1 = "paintEvent is called, the function works fine!\n";
    QString info2 = QString("paintRect's width is %1,height is %2 (x,y) is (%3,%4)").arg(width).arg(height).arg(x).arg(y);
    emit eventInformation(info1+info2); // 此事件持续被调用,会刷屏
    QPlainTextEdit::paintEvent(e); // 不转交无法显示文字
}

//  4. 键盘按下事件
void terminalTextEditor::keyPressEvent(QKeyEvent *e)
{
        QString info1 = " keyPressEvent is called. ";
        QString info2;
        switch (e->key())
        {
            case Qt::Key_Backspace: info2 = "current key is backspace";break;
            case Qt::Key_Left:info2 = "current key is ←";break;
            case Qt::Key_Right:info2 = "current key is →";break;
            case Qt::Key_Up:info2 = "current key is ↑";break;
            case Qt::Key_Down:info2 = "current key is ↓";break;
            case Qt::Key_Enter: info2 = "current key is enter";break;
            case Qt::Key_Shift: info2 = "current key is shift";break;
            case Qt::Key_Tab:info2 = "current key is tab";break;
            case Qt::Key_Alt:info2 = "current key is alt";break;
            case Qt::Key_Space:info2 = "current key is space";break;
            //...还可以加
            default:
                info2 = "current key is "+e->text();
                emit forwardKeyInput(e->text().toLocal8Bit()); // 除了上述键,正常26个字母和数字键以及标点符号都是可以发送的
                break;
        }
        emit eventInformation(QTime::currentTime().toString()+info1+info2);
        QPlainTextEdit::keyPressEvent(e); // 不转交无法显示文字
}

// 5. 键盘松开事件
void terminalTextEditor::keyReleaseEvent(QKeyEvent *e)
{
    QString info = " keyReleaseEvent is called.";
    emit eventInformation(QTime::currentTime().toString()+info);
    Q_UNUSED(e); // 似乎没有影响,不转交也没啥
}

// 6. 鼠标双击事件
void terminalTextEditor::mouseDoubleClickEvent(QMouseEvent *e)
{
        QString info1 = " mouseDoubleClickEvent is called. Clicked position is ";
        QString info2 = QString("(%1,%2)").arg(e->x()).arg(e->y());
        emit eventInformation(QTime::currentTime().toString()+info1+info2);
        // QPlainTextEdit::mouseDoubleClickEvent(e);
        Q_UNUSED(e);// 希望鼠标光标位置永远在文本之后,防止鼠标的点击导致消息不是按顺序append所以把事件禁止
}

// 7. 鼠标单击事件
void terminalTextEditor::mousePressEvent(QMouseEvent *e)
{
        QString button = "RightButton operation.\n";
        if (e->button() == Qt::LeftButton) button = "LeftButton operation.\n";
        QString info1 = " mousePressEvent is called. "+button;
        QString info2 = QString("\t\tClicked position is (%1,%2).").arg(e->x()).arg(e->y());
        emit eventInformation(QTime::currentTime().toString()+info1+info2);
        //QPlainTextEdit::mousePressEvent(e);
        Q_UNUSED(e); // 希望鼠标光标位置永远在文本之后,防止鼠标的点击导致消息不是按顺序append所以把事件禁止
}

// 8. 鼠标松开事件
void terminalTextEditor::mouseReleaseEvent(QMouseEvent *e)
{
        emit eventInformation(QTime::currentTime().toString()+" mouseReleaseEvent is called.");
        //Q_UNUSED(e);
        QPlainTextEdit::mouseReleaseEvent(e);
}

// 9. 鼠标移动事件
void terminalTextEditor::mouseMoveEvent(QMouseEvent *e)
{
    QString info = " mouseMoveEvent is called.";
    QString pos = QString::asprintf("mouse pos is (%d,%d)",e->pos().x(),e->pos().y());
    emit eventInformation(QTime::currentTime().toString()+info+pos);
    QPlainTextEdit::mouseMoveEvent(e);
    //Q_UNUSED(e);
}
