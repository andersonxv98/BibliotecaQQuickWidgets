import QtQuick

Item {
    anchors.fill: parent


    Rectangle{
        id: areaEnunciado
        width: parent.width * 0.9
        height: parent.height * 0.2
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter:  parent.horizontalCenter
        color: "orange"
        border.color: "black"
        border.width: 5
        radius: 20
        Column{
            id: colunaId
        Row{
            id: rowLine


}
        }

    }
    Connections{
        target: enchiridium

        function onEnunciadoChanged(enun){
            var soma_tamanho = 0;
            var rid = rowLine;
            var idRow = 0;
            var l= 0 ;

            for(var i= 0; i< enun.length; i++){
                var texto = enun[i][0];
                var tipo = enun[i][1];
                var dragbleeItem = true;
                //console.log("valor tipo: ", tipo)
                if(tipo === "false"){
                    dragbleeItem = false;
                }
                putLabelOnRow(texto, rid, i, dragbleeItem, tipo, l);

              var posicao_deQuebra= i;
            //console.log("ROW Childs: ",colunaId.children[idRow].children[l].text)
            soma_tamanho+= colunaId.children[idRow].children[l].width

            //console.log("Valores", colunaId.children[idRow].children[l].width)
                l++;
                if(soma_tamanho > areaEnunciado.width){
                    //console.log("Ultima palabra: ",colunaId.children[idRow].children[l-1].text)
                    colunaId.children[idRow].children[l-1].destroy()
                    idRow += 1;
                    Qt.createQmlObject(`
                                       import QtQuick
                                      import QtQuick.Controls
                                      import QtQuick.Layouts
                                       Row{
                                           id: row${idRow}

                                        Component.onCompleted:{
                                            console.log("carregou new Row: ")
                                       }
                                       }
                                       `,colunaId)

                    rid = colunaId.children[idRow]
                    i--;
                    soma_tamanho = 0 ;
                    l= 0;
                    //console.log("Valor Rid: ", rid);

                }
            }
        }
    }

    Connections{
       target: materias_est
    }

    function putLabelOnRow(label, rid, i, dragbleeItem, trueValue, l){
        var margin = "";
        if(l == 0){
            margin = "  ";
        }

        console.log("valor posso arrastar?", dragbleeItem)
        Qt.createQmlObject(`
                           import QtQuick
                          import QtQuick.Controls
                          import QtQuick.Layouts

                           Text{
                                id: enum${i}
                                text: "${margin+label}"
                                font.pointSize: 20

                                DragHandler{
                                  enabled: ${dragbleeItem}
                                   onCanceled:{
                                    console.log("soltou")
                                    var camporesol = areaEnunciado.parent.parent.parent.children[0].children[0].children[0].children[0]

                                    Qt.createQmlObject(\`
                                              import QtQuick
                                             import QtQuick.Controls
                                             import QtQuick.Layouts

                                              Text{
                                                   id: componente${i}
                                                   text: "${label}"
                                                   font.pointSize: 30

                                                    x:  areaEnunciado.parent.parent.parent.children[0].children[0].children[0].mouseX
                                                    y: areaEnunciado.parent.parent.parent.children[0].children[0].children[0].mouseY

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
                                                                //var obj_vinc_vt = parent.parent.children[0].children
                                                                   var d1 = 99999
                                                                   var arr_obj = parent.parent.children[0].children;
                                                                   for(var hj=0; hj < arr_obj.length; hj++){
                                                                       console.log("entrou loop: ", hj)
                                                                       if(arr_obj[hj]!= componente${i}){
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
                                                                   var arr_obj = parent.parent.children;
                                                                   for(var hj=0; hj < arr_obj.length; hj++){
                                                                       console.log("entrou loop: ", hj)
                                                                       if(arr_obj[hj]!= componente${i}){
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
                                                                       console.log("direita")
                                                                       materias_est.registLog("item: "+ text +"  á direita de:  "+ obj_vinc.text)
                                                                       if(y < obj_vinc.y){
                                                                            console.log("canto superior direito")
                                                                           x = obj_vinc.x + obj_vinc.width
                                                                           y = obj_vinc.y - height
                                                                        }
                                                                        else if(y > obj_vinc.y + obj_vinc.height){
                                                                            console.log("canto inferior direito")
                                                                           x = obj_vinc.x + obj_vinc.width
                                                                           y = obj_vinc.y + obj_vinc.height
                                                                        }
                                                                       else{
                                                                           x = obj_vinc.x + obj_vinc.width
                                                                           y = obj_vinc.y
                                                                        }
                                                                   }
                                                                   else if(x+width < obj_vinc.x){
                                                                       console.log("esquerda")
                                                                       if(y < obj_vinc.y){
                                                                            console.log("canto superior esquerdo")
                                                                           x = obj_vinc.x - width
                                                                           y = obj_vinc.y - height
                                                                        }
                                                                        else if(y > obj_vinc.y + obj_vinc.height){
                                                                            console.log("canto inferior esquerdo")
                                                                           x = obj_vinc.x - width
                                                                           y = obj_vinc.y + height
                                                                        }
                                                                       else{
                                                                           x  = obj_vinc.x  - width
                                                                           y = obj_vinc.y
                                                                        }


                                                                   }
                                                                   else if(y+height > obj_vinc.y){
                                                                    console.log("bot")
                                                                       x  = obj_vinc.x
                                                                       y = obj_vinc.y + obj_vinc.height
                                                                       materias_est.registLog("item: "+ text +"  em baixo de:  "+ obj_vinc.text)
                                                                   }
                                                                   else if(y+height < obj_vinc.y){
                                                                    console.log("top")
                                                                       x  = obj_vinc.x
                                                                       y = obj_vinc.y - height
                                                                      materias_est.registLog("item: "+ text +"  em cima de:  "+ obj_vinc.text)
                                                                   }

                                                                   else{

                                                                    }
                                                                parent.parent.parent.children[1].visible = false
                                                               }

                                              }
                                                    Component.onCompleted:{
                                                                    //areaEnunciado.parent.parent.parent.children[0].children[0].children[0].dumpItemTree()
                                                                    areaEnunciado.parent.parent.parent.children[0].children[0].children[0].dumpItemTree()
                                                        //console.log("campo.MareaX: ",areaEnunciado.parent.parent.parent.children[0].children[0].children[0].mouseX)
                                                        //console.log("campo.Mareay: ",areaEnunciado.parent.parent.parent.children[0].children[0].children[0].mouseY)
                                                        //handlerCp${i}.canceled
                                                    }
                                                Connections{
                                                    target: enchiridium;
                                                    }
                                                   Connections{
                                                      target: materias_est
                                                   }
                                              }

                                              \`,areaEnunciado.parent.parent.parent.children[0].children[0].children[0].children[0]);

                                    enum${i}.x =  parent.parent.children[${l-1}].x+ parent.parent.children[${l-1}].width
                                    enum${i}.y =  parent.parent.children[${l-1}].y

                           }
                           }
                           }

                           `,rid);
       // colunaId.dumpItemTree()

    }


}
