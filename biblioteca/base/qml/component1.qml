import QtQuick

Item {
    Image {
        id: component1
        source: ""
        //anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        height:  parent.width * (0.0875)
        width:  parent.width * (0.0875)
    }

    Connections{
        target: controllStaticImg
        function onSourceChanged(s){
            component1.source = s;
        }

        function onAlturaChanged(i){
            component1.height = i;
        }

        function onLarguraChanged(i){
            component1.width = i;

        }

        function onOpacityChanged(i){
            component1.opacity = i;
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

}
