import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    anchors.fill: parent
    id:itemRetangulo
        Rectangle{
            anchors.fill: parent
            anchors.bottomMargin: parent.height *  0.1
            id: retangulo
            //width: 0
            //height: 0
            color: "RED"
            transform : Rotation {
                id: rotacaoRetangulo
                origin.x: 0; origin.y: 0; axis { x: 0; y: 0; z: 0 } angle: 0 }

            Component.onCompleted:{
                //let largura = controllador.getLargura();
               // console.log("VALOR largura: ", largura);
            }

            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/imagem.qml"
                 anchors.fill: retangulo
            }
            /*TapHandler {
            onTapped:
                retangulo.color = controllador.getCor();
            }*/
            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/component2.qml"
                 anchors.fill: retangulo

            }
            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/arc0.qml"
                anchors.fill: retangulo

            }
            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/Arc.qml"
                anchors.fill: retangulo
           }
            Loader{

                source: "qrc:/Anderson/biblioteca/base/qml/arc2.qml"
                anchors.fill: retangulo

            }
            Loader{

                source: "qrc:/Anderson/biblioteca/base/qml/arc3.qml"
                anchors.fill: retangulo

            }



            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/marcadores.qml"
                 anchors.fill: retangulo
            }
            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/ponteiro.qml"
                anchors.fill: retangulo

            }

            Loader{
                source: "qrc:/Anderson/biblioteca/base/qml/component1.qml"
                 anchors.fill: retangulo

            }

        Connections{
            target: controllador
            function onCorChanged(s){
                //console.log( "Conteceu"+ s);
               retangulo.color = s;

            }

            function onLarguraChanged(i){
               retangulo.width = i;
                console.log("mudou largura", i);

            }

            function onAlturaChanged(i){
                retangulo.height = i;
            }

            function onOpacityChanged(i){
                retangulo.opacity = i;
            }

            function onBordaCorChanged(cor){
                retangulo.border.color = cor;
            }
            function onBordaWidthChanged(val){
                retangulo.border.width = val;
            }
            function onRadiusChanged(r){
                retangulo.radius= r;
            }
            function onGradientsChanged(list_g){
                //console.log(list_g)
                //console.log(list_g[0])

            }
            function onAnguloChanged(a){
                rotacaoRetangulo.angle = a;
            }

            function onAxisXChanged(r){
                rotacaoRetangulo.axis.x = r;
            }
            function onAxisYChanged(r){
                rotacaoRetangulo.axis.y = r;
            }
            function onAxisZChanged(r){
                rotacaoRetangulo.axis.z = r;
            }
            function onOriginXChanged(o){
                rotacaoRetangulo.origin.x= o;
            }
            function onOriginYChanged(o){
                rotacaoRetangulo.origin.y= o;
            }


        }

        }
}


