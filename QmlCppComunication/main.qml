import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qml - Cpp Communication Example")

    Item {
        id: root
        anchors.fill: parent

        Item {
            id: sendPanel
            height: sendBtn.height
            anchors { left: root.left; right: root.right; }

            TextInput {
                id: input
                text: "Enter message..."
                height: sendBtn.height
                anchors { left: sendPanel.left; right: sendBtn.left; }
                Rectangle {
                    anchors.fill: input
                    color: "transparent"
                    border.width: 1
                }
            }

            Button {
                id: sendBtn
                text: "Send"
                width: 100
                anchors.right: sendPanel.right
                onClicked: {
                    Message.message = input.text
                }
            }
        }

        TextInput {
            id: output
            text: "Message received: " + Message.message
            readOnly: true
            height: sendBtn.height
            anchors { top: sendPanel.bottom; left: root.left; right: root.right; }
            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.width: 1
            }
        }

        TextInput {
            id: counter
            text: "Changed: " + Message.counter
            readOnly: true
            anchors { top: output.bottom; left: root.left; right: root.right; }
            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.width: 1
            }
        }
    }
}
