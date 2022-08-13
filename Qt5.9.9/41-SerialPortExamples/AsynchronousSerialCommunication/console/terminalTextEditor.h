#ifndef TERMINALTEXTEDITOR_H
#define TERMINALTEXTEDITOR_H

#include <QPlainTextEdit>
class terminalTextEditor : public QPlainTextEdit
{
        Q_OBJECT
public:
        explicit terminalTextEditor(QWidget*parent = nullptr);
        void appendText(const QByteArray& s);
protected:
        void contextMenuEvent(QContextMenuEvent *e) override;
        void showEvent(QShowEvent *) override;
        void paintEvent(QPaintEvent *e) override;
        void keyPressEvent(QKeyEvent *e) override;
        void keyReleaseEvent(QKeyEvent *e) override;
        void mousePressEvent(QMouseEvent *e) override;
        void mouseDoubleClickEvent(QMouseEvent *e) override;
        void mouseReleaseEvent(QMouseEvent *e) override;
        void mouseMoveEvent(QMouseEvent *e) override;
signals:
        void eventInformation(const QString& s);
        void forwardKeyInput(const QByteArray& s);
};
#endif // TERMINALTEXTEDITOR_H
