import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id:itemRetangulo
        Rectangle{
            id: retangulo
            width: 800
            height: 600
            transform : Rotation {
                id: rotacaoRetangulo
                origin.x: 0; origin.y: 0; axis { x: 0; y: 0; z: 0 } angle: 0 }

            Component.onCompleted:{
                let largura = controllador.getLargura();
                console.log("VALOR largura: ", largura);
            }

            TapHandler {
           /* onTapped:
                retangulo.color = controllador.getCor();
            */}

        Connections{
            target: controllador
            function onCorChanged(s){
                console.log( "Conteceu"+ s);
               retangulo.color = s;

            }

            function onLarguraChanged(i){
               retangulo.width = i;

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
                console.log(list_g)
                console.log(list_g[0])

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

            function addGradient(list_g){
                /*gradientRet = Gradient {
                   GradientStop{position: list_g[0], color:list_g[1]}

                }*/
            }
        }

        }
}


