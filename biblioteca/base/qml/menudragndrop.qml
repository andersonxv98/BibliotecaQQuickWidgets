import QtQuick

Item {
    anchors.fill: parent
    visible: false
    property bool cont: false
    Rectangle{
        anchors.fill: parent
        color: "transparent"
        Loader{
                anchors.fill: parent
               source: "qrc:/materiais.qml"
            }
        Loader{
             anchors.fill: parent
           source: "qrc:/exercicioslistamateria.qml"
        }
        Loader{
          anchors.fill: parent
          source: "qrc:/dragNDop.qml"
         }

    onVisibleChanged: {
        if(visible == true && cont == false){
            //console.log("olha visivel depois do login")
            cont = true;
        }
    }

    Connections{
        target: materias_est
    }
    }
}
