import QtQuick

Item {
    id: materias
     //visible: false
    Rectangle{
        anchors.fill: parent
        gradient: Gradient{
        GradientStop { position: 0.0; color: "#110063" }
        GradientStop { position: 1.1; color: "black" }

    }
     ListModel{
         id: modelo
     }

     Component {
             id: contactDelegate
                 Column {
                     Rectangle{
                         x:(lv.width - (lv.width  * 0.95)) / 2
                         width:  lv.width * 0.95
                         height: lv.height * 0.2
                         color: coloral
                         radius: 10
                         border.color: "black"
                         gradient: Gradient{
                         GradientStop { position: 0.0; color: "#110063" }
                         GradientStop { position: 1.1; color: coloral}
                         orientation: Gradient.Horizontal
                         }
                         Text {
                             anchors.verticalCenter: parent.verticalCenter
                             anchors.horizontalCenter: parent.horizontalCenter
                             text:  name
                             font.pointSize: 30
                             color: "white"
                         }
                         TapHandler{

                             onTapped: {
                                 if(activia){
                                     console.log("teste")
                                     console.log("Materia", name)
                                     materias_est.showExercicios(name)
                                     showResolution(name);
                                 }

                             }
                         }
                     }
                 }
     }

     ListView{
         id: lv
         anchors.fill: parent
         spacing: 5
         model: modelo
         delegate: contactDelegate
     }

     Connections{
         target: materias_est
         function onMateriaAppended(exercicioid, qtd){
             console.log("entrou em materia appended qml")

             var colorali = "gray";
             var activia = false //nao te abandona
             if(qtd > 0){
                colorali = "#5FF5B4"
                activia = true;
             }

              var m_ = {"name": exercicioid, "coloral": colorali, "activia": activia}
             modelo.append(m_)
         }
     }
    }
     function showResolution(materia){
         materias.visible = false
         parent.parent.children[1].children[0].visible= true; //dumpItemTree()
         //enchiridium.getmateriasDaMateria(materia);

     }
}
