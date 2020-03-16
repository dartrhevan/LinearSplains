import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 350
    height: 400
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
        id: xf
        objectName: "xf"
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
        id: yf
        objectName: "yf"
        anchors.topMargin: 10
        anchors.top: title.bottom
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 10
    }

    Button {
        width: 150
        height: 30
        id: addBut
        onClicked: handler.addButtonClick()

            //pointsList.a//(xf.text + " " + yf.text)

        text: "Добавить точку"
        anchors.top: xf.bottom
        anchors.rightMargin: 10
        anchors.topMargin: 10
        anchors.right: parent.horizontalCenter
    }

    Button {
        width: 150
        height: 30
        id: solveBut
        onClicked: handler.solveButtonClick()

        text: "Рассчитать"
        anchors.top: xf.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.left: parent.horizontalCenter
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
        height: parent.height - y
        id: pointsList
        anchors.top: points.bottom
        anchors.topMargin: 10
        model: myModel
        delegate: ItemDelegate {
            height: 25
            text: modelData
            onDoubleClicked: handler.deletePoint(modelData)
            width: parent.width
        }
            /*Rectangle {
            height: 25
            width: parent.width
            Text { text: modelData }
        }*/
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
            objectName: "x"
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
            onClicked: handler.calcButtonClick()
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
            objectName: "res"
            anchors.top: calcButton.bottom
            anchors.left: resTitle.right
            anchors.leftMargin: 10
        }
        Text {
            anchors.topMargin: 10
            id: resFunc
            objectName: "resFunc"
            anchors.top: res.bottom
            anchors.left: parent.left
        }
    }

}

