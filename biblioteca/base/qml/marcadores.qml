import QtQuick

Item {

    id : itemMarcadores
    anchors.fill: parent

    property variant vet_: controllMarcadores.getLista()
    Rectangle{

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        //anchors.bottomMargin: 10
        id:espacoRet
        width: 0
        height: 0

    Component.onCompleted: {
        var ar_marcadores =vet_; // [0] idRetangulo, [1]idTexto, [2]idImg
        console.log("VALOR ARC MARCADORES VET",ar_marcadores);



        for(var cont=0; cont < ar_marcadores.length; cont++){

            let stririm  = ar_marcadores[cont];//.toString();
            conection_cMarcadores.onMarcadorCreated(stririm);

        }



    }


    }

    transform: Rotation{
        id: rtEpacoRet
        origin.x: controllMarcadores.getOriginX();
        origin.y: controllMarcadores.getOriginY();
        angle: controllMarcadores.getAngulo();
        axis { x: 0; y: 0; z: 1 }

    }
    Connections{
        id: conection_cMarcadores
        target: controllMarcadores
        function onClearMarcadoreSignal(){
            // espacoRet.children.();
        }
        function onListaChanged(lista){
            console.log("entrou  em OnlistaChange");         
            itemMarcadores.vet_ =controllMarcadores.getLista();        
        }
        function onCorChanged(s){
           // console.log( "Conteceu"+ s);
           espacoRet.color = s;

        }

        function onLarguraChanged(i){
           espacoRet.width = i;

        }

        function onAlturaChanged(i){
            espacoRet.height = i;
        }

        function onOpacityChanged(i){
            espacoRet.opacity = i;
        }

        function onBordaCorChanged(cor){
            espacoRet.border.color = cor;
        }
        function onBordaWidthChanged(val){
            espacoRet.border.width = val;
        }
        function onRadiusChanged(r){
            espacoRet.radius= r;
        }

        function onAnguloChanged(a){
            rtEpacoRet.angle = a;
        }

        function onAxisXChanged(r){
            rtEpacoRet.axis.x = r;
        }
        function onAxisYChanged(r){
            rtEpacoRet.axis.y = r;
        }
        function onAxisZChanged(r){
            rtEpacoRet.axis.z = r;
        }
        function onOriginXChanged(o){
            rtEpacoRet.origin.x= o;
        }
        function onOriginYChanged(o){
            rtEpacoRet.origin.y= o;
        }


        function onMarcadorCreated(id){

            let idRetangulo =  id;
            let idTexto = "txt"+id;
            let idImg = "img"+id;
            let marcador_ = "controllMarcadores"+idRetangulo;

            Qt.createQmlObject(`
                    import QtQuick
                   import QtQuick.Controls
                   import QtQuick.Layouts

                    Item {
                               id: item${idRetangulo}
                               anchors.fill: parent

                   Rectangle{
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.verticalCenter
                       id:  espacoRet${idRetangulo}
                       width: 0
                       height: itemMarcadores.width /3
                       color: "transparent"
                        Text {
                            id: ${idTexto}
                            text: controllSubtxt${idTexto}.getText();
                             anchors.horizontalCenter: parent.horizontalCenter
                             anchors.top: ${idImg}.bottom
                            font.family: "Helvetica"
                                font.pointSize: itemMarcadores.width * 0.03
                        }
                       Image {
                           anchors.horizontalCenter: parent.horizontalCenter
                           anchors.top: parent.top
                           id: ${idImg}
                           source: controllSubimg${idImg}.getSource();
                           height: 0.08 * itemMarcadores.height;
                           width: 0.1 * itemMarcadores.width;
                       }
                     }


                               transform: Rotation{
                                   id: rtEpacoRet${idRetangulo}
                                   origin.x: 0;
                                   origin.y: 0;
                                   angle: 0;
                                   axis { x: 0; y: 0; z: 1 }

                               }
                               Connections{
                                   target: controllSubimg${idImg}
                                   function onSourceChanged(s){
                                       console.log("Controll img singal received", s);
                                       ${idImg}.source = s;
                                   }

                                   function onAlturaChanged(i){
                                        console.log("Mudou Altura da imagem");
                                       ${idImg}.height = i;
                                   }

                                   function onLarguraChanged(i){
                                       ${idImg}.width = i;

                                   }

                                   function onOpacityChanged(i){
                                       ${idImg}.opacity = i;
                                   }

                                  /* function onAnguloChanged(a){
                                       rtImge.angle = a;

                                   }
                                   function onAxisXChanged(r){
                                       rtImge.axis.x = r;
                                   }
                                   function onAxisYChanged(r){
                                       rtImge.axis.y = r;
                                   }
                                   function onAxisZChanged(r){
                                      rtImge.axis.z = r;
                                   }
                                   function onOriginXChanged(o){
                                      rtImge.origin.x= o;
                                   }
                                   function onOriginYChanged(o){
                                      rtImge.origin.y= o;
                                   }*/


                               }

                               Connections{
                                   target: controllSubtxt${idTexto}
                                   function onTextChanged(s){
                                       ${idTexto}.text = s;
                                   }

                                   function onFontSizeChanged(s){
                                       ${idTexto}.font.pointSize = s;
                                   }

                                   function onFontFamilyChanged(s){
                                       ${idTexto}.font.family = s;
                                   }

                                   function onCorChanged(s){
                                       ${idTexto}.color = s;
                                   }

                                   function onAlturaChanged(i){
                                       ${idTexto}.height = i;
                                   }

                                   function onLarguraChanged(i){
                                       ${idTexto}.width = i;

                                   }

                                   function onOpacityChanged(i){
                                       ${idTexto}.opacity = i;
                                   }

                               }


                               Connections{
                                   target: ${marcador_}
                                   function onCorChanged(s){
                                      // console.log( "Conteceu"+ s);
                                      espacoRet${idRetangulo}.color = s;

                                   }
                                   function onAnchorChanged(b){
                                        if(b){
                                        ${idTexto}.anchors.top = espacoRet${idRetangulo}.top
                                        ${idImg}.anchors.top= ${idTexto}.bottom;

                                        }
                                        else{
                                               ${idTexto}.anchors.top = ${idImg}.bottom;
                                               ${idImg}.anchors.top= espacoRet${idRetangulo}.top;
                                            }
                                   }
                                   function onLarguraChanged(i){
                                      espacoRet${idRetangulo}.width = i;

                                   }

                                   function onAlturaChanged(i){
                                       espacoRet${idRetangulo}.height = i;

                                   }

                                   function onOpacityChanged(i){
                                       espacoRet${idRetangulo}.opacity = i;
                                   }

                                   function onBordaCorChanged(cor){
                                       espacoRet${idRetangulo}.border.color = cor;
                                   }
                                   function onBordaWidthChanged(val){
                                       espacoRet${idRetangulo}.border.width = val;
                                   }
                                   function onRadiusChanged(r){
                                       espacoRet${idRetangulo}.radius= r;
                                   }

                                   function onAnguloChanged(a){
                                        console.log("VALOR ANGULO CONTROL DINAMIC", a-90);
                                        //console.log("VALOR DO ID DESSE ANGUKIO: ", idRetangulo)
                                        rtEpacoRet${idRetangulo}.angle = a- 90;

                                   }

                                   function onAxisXChanged(r){
                                       rtEpacoRet${idRetangulo}.axis.x = r;
                                   }
                                   function onAxisYChanged(r){
                                       rtEpacoRet${idRetangulo}.axis.y = r;
                                   }
                                   function onAxisZChanged(r){
                                       rtEpacoRet${idRetangulo}.axis.z = r;
                                   }
                                   function onOriginXChanged(o){
                                       rtEpacoRet${idRetangulo}.origin.x= o;
                                   }
                                   function onOriginYChanged(o){
                                       rtEpacoRet${idRetangulo}.origin.y= o;
                                   }

                               }

                               }

                    `,
                    espacoRet);
            return;

        }

    }
}
