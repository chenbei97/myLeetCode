#include <csv/csvexport.h>

CSVExport::CSVExport()
{
        QDir debugDir= QDir::current();
        debugDir.cdUp();
        mWorkDir = debugDir.path();
        //qDebug()<<"mWorkdir = "<<mWorkDir;

        mrows = mcols = 0;
}

QStringList CSVExport::tableHeader() const
{
    QStringList ret = mTableHeader.split(',');
    ret.removeLast(); // 去掉换行符
    return  ret;
}

QStringList CSVExport::tableContent() const
{
    return mTableContent.split('n');
}

int CSVExport::row() const
{
    return mrows;
}

int CSVExport::col() const
{
    return mcols;
}

void CSVExport::clear()
{
    mrows = 0;
    mcols = 0;
    mTableHeader.clear();
    mTableContent.clear();
}

int CSVExport::error(ErrorCode error)
{
    int ret = 0;
    switch (error) {
            case ErrorCode::Empty:
                    ret = msg(tr("警告"),tr("导出的CSV没有表头和内容,导出可能为空文件,是否继续执行?"));
                    break;
             case ErrorCode::EmptyHeader:
                    ret = msg(tr("警告"),tr("导出的CSV没有表头,是否继续执行?"));
                    break;
            case ErrorCode::EmptyContent:
                    ret = msg(tr("警告"),tr("导出的CSV没有内容,是否继续执行?"));
                    break;
    }
    return ret;
}

int CSVExport::msg(const QString & title, const QString & text,ErrorLevel level)
{
    int ret = 0; // 默认返回0
    QMessageBox::StandardButton result;
    switch (level) {
        case ErrorLevel::Information:
                result = QMessageBox::information(Q_NULLPTR,title,text,QMessageBox::Apply|QMessageBox::Ignore);
                break;
        case ErrorLevel::Warning:
                result = QMessageBox::warning(Q_NULLPTR,title,text,QMessageBox::Apply|QMessageBox::Ignore);
                break;
        case ErrorLevel::Critical:
                result = QMessageBox::critical(Q_NULLPTR,title,text,QMessageBox::Apply|QMessageBox::Ignore);
                break;
        case ErrorLevel::Question:
                result= QMessageBox::question(Q_NULLPTR,title,text,QMessageBox::Apply|QMessageBox::Ignore);
                break;
    }
    if (result == QMessageBox::Apply) ret = 1; // 表示用户仍然无视消息选择了要执行
    return ret;
}
