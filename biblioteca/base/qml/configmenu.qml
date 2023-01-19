import QtQuick
import QtQuick.Dialogs
import Qt.labs.platform
import QtQuick.Controls
Item {
    anchors.fill: parent

     /*FileDialog {
         id: colorDialog
         title: "Please choose a color"
         onAccepted: {
             console.log("You chose: " + colorDialog.color)
             Qt.quit()
         }
         onRejected: {
             console.log("Canceled")
             Qt.quit()
         }
         Component.onCompleted: visible = true
     }*/




    Rectangle{
        anchors.fill: parent
        color: "black"
        Text {
            id: conf
            text: qsTr("Configurações")
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 30
            color: "white"
        }

        Rectangle{
            width: parent.width * 0.1
            height: parent.height * 0.1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: "pink"
            TapHandler{
                onTapped: {
                    console.log("brincks")
                }
            }
        }
    }
}
