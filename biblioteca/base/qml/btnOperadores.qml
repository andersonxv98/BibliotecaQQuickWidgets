import QtQuick
import QtQuick.Controls
Item {
    anchors.fill: parent
     property int contadorId: 0
    Rectangle{
        id:campoPeradores
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 3
        width: parent.width * 0.9
        height: parent.height * 0.08
        color: "transparent"
        Row{
            spacing: 2
            anchors.fill: parent
            //spacing: 10

            Rectangle{
            //anchors.fill: parent
            color: "pink"
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    id: name
                    text: qsTr("somar(+)")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 20
                }
                DragHandler{
                    target: name
                    onCanceled:  {
                        console.log("somar")

                        addOperatorInResolution("+ ")
                    }
                }
            }
            Rectangle{
            color: "pink"
           // anchors.fill: parent
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: name2
                    text: qsTr("sub(-)")
                    font.pointSize: 20
                }
                DragHandler{
                    target: name2
                    onCanceled:  {
                        console.log("subtrair")

                        addOperatorInResolution("- ")
                    }
                }


            }
            Rectangle{
            color: "pink"
           // anchors.fill: parent
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: name3
                    text: qsTr("mult(*)")
                    font.pointSize: 20
                }
                DragHandler{
                    target: name3
                    onCanceled:  {
                        console.log("multiplicar")
                        campoPeradores.parent.parent.parent.children[0].children[0].children[0].dumpItemTree()

                        addOperatorInResolution("* ")
                    }

                }               
            }
            Rectangle{
            color: "pink"
            //anchors.fill: parent
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: name4
                    text: qsTr("div(/)")
                    font.pointSize: 20
                }
                DragHandler{
                    target: name4
                    onCanceled:  {
                        console.log("dividir")

                        addOperatorInResolution("/ ")

                    }
                }

            }
            Rectangle{
            color: "pink"
            //anchors.fill: parent
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: name5
                    text: qsTr("exp(^)")
                    font.pointSize: 20
                }
                DragHandler{
                    target: name5
                    onCanceled:  {
                        console.log("expoente")

                        addOperatorInResolution("^ ")

                    }
                }

            }
            Rectangle{
            color: "pink"
            //anchors.fill: parent
            width: parent.width / 6
            height: parent.height
            border.color: "black"
            border.width: 5
            radius: 20
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: name6
                    text: qsTr("rad(√)")
                    font.pointSize: 20
                }
                DragHandler{
                    target: name6
                    onCanceled:  {
                        console.log("radiciação")
                        addOperatorInResolution("√ ")

                    }
                }
            }


    }


    }


     Connections{
        target: enchiridium
     }

     Connections{
        target: materias_est
     }

     function addOperatorInResolution(sinal){

         var camporesol =  name.parent.parent.parent.parent.parent.parent.children[0].children[0].children[0].children[0];
         Qt.createQmlObject(`import QtQuick
                            import QtQuick.Controls
                            import QtQuick.Layouts

                             Text{
                                  id: operador${contadorId}
                                  text: "${sinal}"
                                  font.pointSize: 30

                                x: campoPeradores.parent.parent.parent.children[0].children[0].children[0].mouseX
                                y: campoPeradores.parent.parent.parent.children[0].children[0].children[0].mouseY
                            onXChanged: {

                                        var last = 0;
                                        if(x+width  < parent.width && x > 0){

                                           last =  x;
                                         }
                                         else{
                                            if(x <= 0){
                                                 last = 0
                                             }
                                             else{
                                                 last =  parent.width - width
                                             }
                                            x = last
                                          }
                                      if(parent.parent.children[0].children.length > 1){
                                        parent.parent.children[1].visible = true
                                        var d1 = 99999
                                        var arr_obj = parent.parent.children[0].children;
                                        for(var hj=0; hj < arr_obj.length; hj++){
                                            console.log("entrou loop: ", hj)
                                            if(arr_obj[hj]!=operador${contadorId}){
                                                var d2 = (((arr_obj[hj].x - x)**2) + ((arr_obj[hj].y - y)**2)) ** 1/2
                                                console.log("valor d1: ", d1 , "   valor d2:  ", d2)
                                                if(d2 < 0){
                                                    d2  = d2 * -1}
                                                if(d2 < d1){
                                                    d1 = d2
                                                    console.log("entrou na condição")
                                                    var obj_vinc = arr_obj[hj]
                                                    console.log("objeto: ", obj_vinc)
                                                }
                                            }
                                        }


                                       if(x > obj_vinc.x + obj_vinc.width){

                                           if(y < obj_vinc.y){

                                               parent.parent.children[1].x = obj_vinc.x + obj_vinc.width
                                               parent.parent.children[1].y = obj_vinc.y - height
                                            }
                                            else if(y > obj_vinc.y + obj_vinc.height){

                                               parent.parent.children[1].x = obj_vinc.x + obj_vinc.width
                                               parent.parent.children[1].y = obj_vinc.y + obj_vinc.height
                                            }
                                           else{
                                               parent.parent.children[1].x = obj_vinc.x + obj_vinc.width
                                               parent.parent.children[1].y = obj_vinc.y
                                            }
                                       }
                                       else if(x+width < obj_vinc.x){

                                           if(y < obj_vinc.y){

                                               parent.parent.children[1].x = obj_vinc.x - width
                                               parent.parent.children[1].y = obj_vinc.y - height
                                            }
                                            else if(y > obj_vinc.y + obj_vinc.height){

                                               parent.parent.children[1].x = obj_vinc.x - width
                                               parent.parent.children[1].y = obj_vinc.y + height
                                            }
                                           else{
                                               parent.parent.children[1].x  = obj_vinc.x  - width
                                               parent.parent.children[1].y = obj_vinc.y
                                            }


                                       }
                                       else if(y+height > obj_vinc.y){

                                           parent.parent.children[1].x  = obj_vinc.x
                                           parent.parent.children[1].y = obj_vinc.y + obj_vinc.height

                                       }
                                       else if(y+height < obj_vinc.y){

                                           parent.parent.children[1].x  = obj_vinc.x
                                           parent.parent.children[1].y = obj_vinc.y - height

                                       }
                                    }

                                }
                            onYChanged: {

                                          var last = parent.height - height;
                                        if(y > 0 && y+height < parent.height){

                                            last =  y;

                                         }
                                        else{
                                            if(y <= 0){
                                                 last = 0
                                             }
                                             else{
                                                 last =  parent.height - height
                                             }
                                            y = last
                                         }
                                }
                                 DragHandler{
                                    onCanceled: {
                                            var d1 = 99999
                                            var arr_obj = parent.parent.children//dumpItemTree()
                                            for(var hj=0; hj < arr_obj.length; hj++){
                                                console.log("entrou loop: ", hj)
                                                if(arr_obj[hj]!= operador${contadorId}){
                                                    console.log("encontrou item q não é  operador")
                                                    var d2 = (((arr_obj[hj].x - x)**2) + ((arr_obj[hj].y - y)**2)) ** 1/2
                                                    console.log("valor d1: ", d1 , "   valor d2:  ", d2)
                                                    if(d2 < 0){
                                                        d2  = d2 * -1}

                                                    if(d2 < d1){
                                                        d1 = d2
                                                        console.log("entrou na condição")
                                                        var obj_vinc = arr_obj[hj]
                                                        console.log("objeto: ", obj_vinc)
                                                    }
                                                }
                                            }
                                            console.log("log obj vinc", obj_vinc)
                                            //x = obj_vinc.x+ obj_vinc.width
                                            //y = obj_vinc.y -5///+ obj_vinc.height
                                            if(text.includes("───")){
                                                text= "/"
                                            }
                                            if(x >= obj_vinc.x + obj_vinc.width){
                                                console.log("direita")
                                                x = obj_vinc.x + obj_vinc.width
                                                y = obj_vinc.y
                                               materias_est.registLog("item: "+ text +"  á direita de:  "+ obj_vinc.text)
                                            }
                                            else if(x+width <= obj_vinc.x){
                                                console.log("esquerda")
                                                x  = obj_vinc.x  - width
                                                y = obj_vinc.y
                                               materias_est.registLog("item: "+ text +"  á esquerda de:  "+ obj_vinc.text)
                                            }
                                            else if(y+height >= obj_vinc.y){
                                             console.log("bot")
                                                if(text.includes("/")){
                                                    text= "───"
                                                }
                                                x  = obj_vinc.x
                                                y = obj_vinc.y + obj_vinc.height

                                               materias_est.registLog("item: "+ text +"  em baixo de:  "+ obj_vinc.text)
                                            }
                                            else{
                                             console.log("top")
                                                if(text.includes("/")){
                                                    text= "───"
                                                }
                                                x  = obj_vinc.x
                                                y = obj_vinc.y - height

                                               materias_est.registLog("item: "+ text +"  em cima de:  "+ obj_vinc.text)
                                            }
                                            parent.parent.parent.children[1].visible = false
                                        }
                                 }
                            TapHandler{
                                onDoubleTapped: {
                                   materias_est.registLog("removeu objeto: "+ text)
                                    operador${contadorId}.destroy();
                                }
                            }

                            }
                            `,camporesol);

     }



}
