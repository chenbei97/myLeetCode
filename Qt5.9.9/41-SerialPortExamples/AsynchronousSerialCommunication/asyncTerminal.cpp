#include "asyncTerminal.h"
#include "ui_asyncTerminal.h"

asyncTerminal::asyncTerminal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::asyncTerminal)
{
        ui->setupUi(this);
        this->init();
        this->initConnections();
}

asyncTerminal::~asyncTerminal()
{
        delete ui;
        delete mConfig;
        delete mPort;
}



