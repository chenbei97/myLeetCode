#include <csv/csvexport.h>

void CSVExport::writeTable(const char* header,const char* content)
{
    clear(); // 先清理
    // 检查格式,内容必须有逗号分割,\n换行符结束
    QString conten(content);
    if (conten.right(1) !="\n")
    {
        QMessageBox::critical(Q_NULLPTR,tr("错误"),tr("内容输入文本必须包含换行符,且用逗号分开各项!"));
        return;
    }

    QString head(header);
    if (head.right(1) !="\n")
    {
          head = head + QStringLiteral("\n"); // 支持表头没有换行结束符
    }
    mTableHeader = head;
    mTableContent = conten;

    // 这里解析出内容的行列数(不包括表头)
    QStringList rowStr = conten.split("\n"); // 首先按照换行符分割
    mrows = rowStr.size()-1; // 得到行数,减去1是因为最后1个字符是\n,分割后最后1项是空字符串
    mcols = rowStr[0].split(",").size(); // 得到列数,至少会有1行可以[0]计算,逗号不是最后1项,所以不会产生空字符串无需-1

    exportCsv();
}

void CSVExport::writeTable(const QString & header,const QString & content)
{
        writeTable(header.toStdString().c_str(),content.toStdString().c_str());
}

void CSVExport::writeTable(const QString & header,TableContent func)
{
    if (func == Q_NULLPTR) {
        QMessageBox::critical(Q_NULLPTR,tr("错误"),tr("表格内容的函数指针不允许为空!"));
         return;
    }
    QString content = func();
    writeTable(header.toStdString().c_str(),content.toStdString().c_str());
}


