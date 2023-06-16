import QtQuick

Item {
    width: 400; height: 100

    Text {
        textFormat: Text.RichText; font.pointSize: 24
        text: "欢迎访问<a href=\"https://qter.org\">Qt开源社区</a>"
        onLinkActivated: (link)=> console.log(link + " link activated");
    }
}

