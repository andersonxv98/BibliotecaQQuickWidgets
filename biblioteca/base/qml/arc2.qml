import QtQuick

Item {
    anchors.fill: parent

    /*id:cavasItemId
    anchors.horizontalCenter:  parent.horizontalCenter
    anchors.verticalCenter:  parent.verticalCenter
*/
        Canvas {
            id: canvasId
            //anchors.horizontalCenter:  parent.horizontalCenter
            //anchors.verticalCenter:  parent.verticalCenter
            anchors.fill: parent

            property double mod: 4
            property int altura: parent.height
            property int largura: parent.width
            property double val_end: 1.5
            property double val_init: 2
            property double originX: largura / 2
            property double originY: altura
            property double size: largura/ mod
            property double init: Math.PI * val_init
            property double end: Math.PI * val_end
            property bool anticlockwise: false
            property string color: "blue"

            transform: Rotation{
                id: rtCanvas

            }

            onPaint: {

                var ver_oburaco = controllCanvas2.getBuraco();
                if(ver_oburaco){
                    var  ctx = canvasId.getContext("2d");
                    ctx.reset();
                    ctx.beginPath();
                    ctx.strokeStyle = color
                    ctx.arc(originX, originY, size, init, end)// anticlockwise);
                    ctx.lineWidth = size
                    ctx.stroke();
                }
                else{
                    let ctx = getContext("2d");
                    ctx.reset();



                    ctx.beginPath();
                    ctx.fillStyle = color;
                    ctx.moveTo(originX, originY);
                    // arc(originX, originY, size, (val init), (val end), bool anticlockwise)
                    ctx.arc(originX, originY,  size* 1.5, init, end, anticlockwise);
                    ctx.lineTo(originX, originY);
                    ctx.fill();
                }

            }
        }

        Connections{
            target: controllCanvas2


            function onBuracoChanged(f){
                canvasId.requestPaint();
            }
            function onSizeModificadorChanged(val){
                canvasId.mod = val;
                canvasId.requestPaint();
            }

            function onInitChanged(val){
                console.log("valor init", val);
                    canvasId.val_init = val;
                canvasId.requestPaint();
            }
            function onEndChanged(val){
                console.log("valor end", val);
                canvasId.val_end = val;
                canvasId.requestPaint();
            }
            function onAnticlockwiseChanged(val){
                canvasId.anticlockwise = val;
                canvasId.requestPaint();
            }
           function onCorChanged(cor){
               console.log("VALOR COR QML ARC 2", cor);
                canvasId.color = cor;
               canvasId.requestPaint();
           }
           function onAlturaChanged(i){
               console.log("valor altura qml: ", i)
               canvasId.parent.height = i;
               canvasId.requestPaint();
               //cavasItemId.o
           }

           function onLarguraChanged(i){
               canvasId.parent.width = i;
               canvasId.requestPaint();

           }

           function onOpacityChanged(i){
               canvasId.opacity = i;
               canvasId.requestPaint();
           }

           function onAnguloChanged(a){
               rtCanvas.angle = a-90;
           }
           function onAxisXChanged(r){
               rtCanvas.axis.x = r;
           }
           function onAxisYChanged(r){
               rtCanvas.axis.y = r;
           }
           function onAxisZChanged(r){
              rtCanvas.axis.z = r;
           }
           function onOriginXChanged(o){
              canvasId.originX= o;
               canvasId.requestPaint();
           }
           function onOriginYChanged(o){
              canvasId.originY= o;
               canvasId.requestPaint();
           }

        }
}
