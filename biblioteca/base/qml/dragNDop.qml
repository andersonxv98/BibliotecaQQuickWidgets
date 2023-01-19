import QtQuick

Item {
    id: dragndop
    anchors.fill: parent
    visible:  false


    Loader{
     anchors.fill: parent
     source: "qrc:/resolucao.qml"
    }
    Loader{
     anchors.fill: parent
     source: "qrc:/btnOperadores.qml"
    }
    Loader{
        anchors.fill: parent
        source: "qrc:/enunciado.qml"
    }
    Component.onCompleted: {
        forceActiveFocus()
    }

    onVisibleChanged: {
        if(visible){
            forceActiveFocus()
        }
        else{
            visible = false;
            focus= false
        }
    }


    Keys.onPressed:   (event)=> {
            if (event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
                //console.log("backspace Dag on my doop on my d.... vorta");
                parent.parent.dumpItemTree()
               materias_est.registLog("Retornou do exercicio, backspace ou return");
               var vulpix = dragndop.children[0].children[0].children[0].children[0].children
             for(var h = 0; h <vulpix.length; h++){
                    vulpix[h].destroy();
                              }
            dragndop.visible = false;
              var rows = dragndop.children[2].children[0].children[0].children[0].children
              for(var l = 0; l < rows.length; l++){
                  var objcts = rows[l].children
                  for(var i = 0; i < objcts.length; i++){
                       objcts[i].destroy()
                        }
                 }
             parent.parent.children[0].children[0].visible = true;
                event.accepted = true;
            }
        }


    Connections{
        target: materias_est
    }
}
