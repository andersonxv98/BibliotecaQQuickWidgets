import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Item {
    Image {
        id: imagemId
        source: ""

    }


    Connections{
        target: controllimg
        function onSourceChanged(s){
            console.log("Controll img singal received", s);
            imagemId.source = s;
        }

        function onAlturaChanged(i){
            imagemId.height = i;
        }

        function onLarguraChanged(i){
            imagemId.width = i;

        }

        function onOpacityChanged(i){
            imagemId.opacity = i;
        }

        function onAnguloChanged(a){
            rtImge.angle = a-90;

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
        }


    }





}
