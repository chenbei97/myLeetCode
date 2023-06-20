// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QGuiApplication>
#include <QList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "dataobject.h"

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    const QStringList colorList = {"red", "green", "blue", "yellow"};

    const QStringList moduleList = {"Core", "GUI", "Multimedia", "Multimedia Widgets", "Network",
                                    "QML", "Quick", "Quick Controls", "Quick Dialogs",
                                    "Quick Layouts", "Quick Test", "SQL", "Widgets", "3D",
                                    "Android Extras", "Bluetooth", "Concurrent", "D-Bus",
                                    "Gamepad", "Graphical Effects", "Help", "Image Formats",
                                    "Location", "Mac Extras", "NFC", "OpenGL", "Platform Headers",
                                    "Positioning", "Print Support", "Purchasing", "Quick Extras",
                                    "Quick Timeline", "Quick Widgets", "Remote Objects", "Script",
                                    "SCXML", "Script Tools", "Sensors", "Serial Bus",
                                    "Serial Port", "Speech", "SVG", "UI Tools", "WebEngine",
                                    "WebSockets", "WebView", "Windows Extras", "XML",
                                    "XML Patterns", "Charts", "Network Authorization",
                                    "Virtual Keyboard", "Quick 3D", "Quick WebGL"};

    QList<QObject *> dataList; // 创建这么多对象，颜色随机的，名称是moduleList
    for (const QString &module : moduleList)
        dataList.append(new DataObject("Qt " + module, colorList.at(rand() % colorList.length())));

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setInitialProperties({{ "model", QVariant::fromValue(dataList) }}); // 设置初始性质，模型名称"model"
//![0]

    view.setSource(QUrl("qrc:/objectlistmodel/view.qml"));
    view.show();

    return app.exec();
}



