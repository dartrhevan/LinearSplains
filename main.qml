import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")
    Text
    {
        text: "Линейная сплайн-интерполяция"
        font.bold: true
        font.pixelSize : 18
        id: title
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TextField {
        width: 100
        height: 30
        placeholderText: "x"
        anchors.top: title.bottom
        anchors.topMargin: 10
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 10
    }

    TextField {
        width: 100
        height: 30
        placeholderText: "y"
        id: te
        anchors.topMargin: 10
        anchors.top: title.bottom
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 10
    }

    Button {
        width: 150
        height: 30
        id: addBut
        text: "Добавить точку"
        anchors.top: te.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text {
        text: "Точки"
        font.bold: true
        id: points
        anchors.top: addBut.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: pointsList.horizontalCenter
    }
    ListView {
        width: parent.width / 2
        model: 20
        id: pointsList
        anchors.top: points.bottom
        anchors.topMargin: 10
        delegate: ItemDelegate {
            text: "Item " + (index + 1)
            width: parent.width
        }
    }

    ScrollView {
        width: parent.width / 2
        anchors.top: addBut.bottom
        anchors.topMargin: 10
        anchors.left: pointsList.right
        Text
        {
            font.bold: true
            text: "Функция"
            id: funcTitle
            anchors.horizontalCenter: parent.horizontalCenter
        }
        TextField {
            width: parent.width
            height: 30
            anchors.top: funcTitle.bottom
            id: x
            placeholderText: "x"
            anchors.topMargin: 10
            anchors.bottomMargin: 10
        }
        Button {
            id: calcButton
            width: parent.width
            text: "Рассчитать"
            anchors.top: x.bottom
            height: 30
            anchors.topMargin: 10
            anchors.bottomMargin: 10
        }
        Text {
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            text: "Значение"
            id: resTitle
            anchors.left: parent.left
            anchors.top: calcButton.bottom
        }
        Text {
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            id: res
            anchors.top: calcButton.bottom
            anchors.left: resTitle.left
        }
        Text {
            anchors.topMargin: 10
            id: resFunc
            anchors.top: res.bottom
            anchors.left: parent.left
        }
    }

}

