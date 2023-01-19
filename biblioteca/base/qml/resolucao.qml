import QtQuick

Item {
    anchors.fill: parent
    property int n_child: 0
    MouseArea {
            id: myMArea
            anchors.left: parent.left
            y: parent.parent.parent.children[2].children[0].children[0].height +  parent.parent.parent.children[2].children[0].children[0].y
             hoverEnabled: true
             height: parent.height * 0.70
             width: parent.width * 0.9

   Rectangle{
        id: campoResolucao
        anchors.fill: parent
       color: "pink"
       border.color: "black"
       border.width: 5
       radius: 20



               }
   Rectangle{
       id: campoTarget
        height: 50
        width: 50
      color: "gray"
      opacity: 0.5
      border.color: "black"
      border.width: 5
      radius: 20
      visible: false


   }
    }
   Rectangle{
       id: btnCalcular
       height: campoResolucao.height /3
       width: parent.width * 0.1
       color: "lightgreen"
       anchors.top: myMArea.top
       anchors.left: myMArea.right
       border.color: "black"
       border.width: 5
       radius: 20
       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           anchors.verticalCenter: parent.verticalCenter
           id: txt_btnCalcular
           text: qsTr("Calcular")
           font.pointSize: 20
       }

       TapHandler{
            onTapped: {

               var vt = [];
                var operador;
                var lt_aux = 0;
                var ltY_aux = 0;
                var posiXResult = 0;
                var posiYResult = 0;

               var arr_obj = campoResolucao.children;
                 for(var k=0; k< arr_obj.length; k++){
                     //console.log("item position x: ", arr_obj[k].x, "texto: ",arr_obj[k].text)
                     //console.log("texto: ", arr_obj[k].text,"end")
                     if(parseFloat(arr_obj[k].text)){
                         if(arr_obj[k].x > lt_aux || arr_obj[k].y > ltY_aux){
                             vt.push(arr_obj[k].text);
                             lt_aux = arr_obj[k].x
                             ltY_aux = arr_obj[k].y
                         }
                         else{
                             var aux_obj = vt[0]
                             vt[0] = arr_obj[k].text
                             vt[1] = aux_obj
                         }

                     }
                     else{
                         operador = arr_obj[k].text
                         posiXResult = arr_obj[k].x
                         posiYResult = arr_obj[k].y
                     }
                     campoResolucao.children[k].destroy()
                 }
              var resultado = enchiridium.calcular(vt[0],vt[1], operador);
                 materias_est.registLog("Clicou em Calcular, Resultado do calculo: "+ resultado)

                 criarComponent(resultado, campoResolucao, posiXResult, posiYResult)
            }
       }

   }

   Rectangle{
       id: btn_enviar
       height: campoResolucao.height /3
       width: parent.width * 0.1
       color: "lightblue"
       anchors.top: btn_reset.bottom
       anchors.left:  myMArea.right
       border.color: "black"
       border.width: 5
       radius: 20
       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           anchors.verticalCenter: parent.verticalCenter
           id: txtBtn_enviar
           text: qsTr("Enviar")
           font.pointSize: 20
       }

       TapHandler{
            onTapped: {
                console.log("Send - man")
                materias_est.registLog("Clicou em Enviar exercicio")
                var result =  enchiridium.getResultadoNoMask();
                console.log("Valor No mask:  ", result);
                materias_est.registResult(result)
            }
       }
   }

   Rectangle{
       id: btn_reset
       height: campoResolucao.height / 3
       width: parent.width * 0.1
       color: "yellow"
       anchors.top: btnCalcular.bottom
       anchors.left:   myMArea.right
       border.color: "black"
       border.width: 5
       radius: 20
       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           anchors.verticalCenter: parent.verticalCenter
           id: txtBtn_reset
           text: qsTr("Reiniciar")
           font.pointSize: 20
       }

       TapHandler{
            onTapped: {
                console.log("reset - man")
                //campoResolucao.dumpItemTree()
                campoResolucao.color = "pink"
               var arr = campoResolucao.children;
               for(var g =0; g < arr.length; g++){
                                //console.log("destruindo: ", arr[g]);
                                //console.log("myArea: ", myMArea)
                                arr[g].destroy()
                }
                materias_est.registLog("Clicou em resetar exercicio")
            }
       }

   }




    Connections{
        target: enchiridium

        function onCorrectResult(){
                campoResolucao.color = "lightgreen"
        }
    }
    Connections{
        target: materias_est
    }

    function criarComponent(resultado, pai, posicaoX, posicaoY){
        Qt.createQmlObject(`import QtQuick
                           import QtQuick.Controls
                           import QtQuick.Layouts

                            Text{
                                 id: componente
                                 text: "${resultado}"
                                 font.pointSize: 30

                                 x: ${posicaoX}
                                 y: ${posicaoY}
                                 onXChanged: {
                                             var last = 0;
                                             if(x+width  < parent.width && x > 0){
                                                // console.log("ai dento!")
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
                                               //var obj_vinc_vt = parent.parent.children[0].children
                                                  var d1 = 99999
                                                  var arr_obj = parent.parent.children[0].children;
                                                  for(var hj=0; hj < arr_obj.length; hj++){
                                                      console.log("entrou loop: ", hj)
                                                      if(arr_obj[hj]!= componente){
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
                                              //console.log("valor y: ",y  ," valor parent.y: ", parent.y)
                                               var last = parent.height - height;
                                             if(y > 0 && y+height < parent.height){
                                                // console.log("dentro y")
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
                                                     if(arr_obj[hj]!= componente){
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

                                                 if(x >= obj_vinc.x + obj_vinc.width){
                                                     console.log("direita")
                                                     materias_est.registLog("item: "+ text +"  á direita de:  "+ obj_vinc.text)
                                                     x = obj_vinc.x + obj_vinc.width
                                                     y = obj_vinc.y
                                                 }
                                                 else if(x+width <= obj_vinc.x){
                                                     console.log("esquerda")
                                                     x  = obj_vinc.x  - width
                                                     y = obj_vinc.y
                                                     materias_est.registLog("item: "+ text +"  á esquerda de:  "+ obj_vinc.text)
                                                 }
                                                 else if(y+height >= obj_vinc.y){
                                                  console.log("bot")
                                                     x  = obj_vinc.x
                                                     y = obj_vinc.y + obj_vinc.height
                                                     materias_est.registLog("item: "+ text +"  em baixo de:  "+ obj_vinc.text)
                                                 }
                                                 else{
                                                  console.log("top")
                                                     x  = obj_vinc.x
                                                     y = obj_vinc.y - height
                                                    materias_est.registLog("item: "+ text +"  em cima de:  "+ obj_vinc.text)
                                                 }
                                                 parent.parent.parent.children[1].visible = false
                                             }

                            }
                                  Component.onCompleted:{
                                      //console.log("resolucao x: ",parent.x)
                                      //console.log("resolucao y: ",parent.y)
                                  }
                              Connections{
                                  target: enchiridium;
                                  }

                                   Connections{
                                      target: materias_est
                                   }
                            }
                           `,pai)
    }
}
