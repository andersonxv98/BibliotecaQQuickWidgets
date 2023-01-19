import QtQuick

Item {
   id: exercicios
    visible: false
    Rectangle{
        anchors.fill: parent
        gradient: Gradient{
        GradientStop { position: 0.0; color: "#110063" }
        GradientStop { position: 1.1; color: "black" }
    }
    ListModel{
        id: modelo
    }

    onVisibleChanged: {
        if(visible){
            forceActiveFocus()
        }
        else{

            modelo.clear()
        }
    }

    Keys.onPressed:   (event)=> {
            if (event.key === Qt.Key_Backspace || event.key === Qt.Key_Back) {
                materias_est.registLog("retornou da lista de exercicios de Materias, backspace ou return")
                exercicios.visible = false
                exercicios.focus = false
                exercicios.parent.parent.children[0].children[0].visible = true

            }
        }

    Component {
            id: contactDelegate
                Column {
                    Rectangle{
                        x:(lv.width - (lv.width  * 0.95)) / 2
                        width:  lv.width * 0.95
                        height: lv.height * 0.2
                        //color: "lightblue"
                        radius: 10
                        border.color: "black"
                        gradient: Gradient{
                            GradientStop { position: 0.0; color: "#110063" }
                            GradientStop { position: 1.1; color: "#5FF5B4"}
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
                                console.log("teste")
                                console.log("Exercicio", name)
                                materias_est.showExercicioResolucao(name)
                                showResolution(name);
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

        function onMateriaExercicios(exercicioid){
            console.log("entrou em exercicio appended qml")
            var m_ = {"name": exercicioid}
            modelo.append(m_)
        }

        function onExercicioResolved(idexercicio){
            console.log("entrou em on exercicioremoved qml")
            var m_ = {"name": idexercicio}
            /*for(var i=0; i< modelo.length; i++){
                if(modelo[i].name = idexercicio){
                    modelo.remove(i);
                    break;
                }
            }*/
            modelo.clear()
        }
        }
    }

    function showResolution(materia){
        exercicios.visible = false
        parent.parent.children[2].children[0].visible= true;

    }
}
