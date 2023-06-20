// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5

//![0]
ListView {
    id: listview
    width: 600; height: 820
    required model// MyModel是外部定义的模型
    ScrollBar.vertical: ScrollBar { }

    delegate: Rectangle {

        width: listview.width; height: 25
        Text { text: "name: "+parent.name+" color: "+parent.color }
    }
}
//![0]
