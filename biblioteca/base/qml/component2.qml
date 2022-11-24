import QtQuick

Item {
    Image {
        id: component2
        source: ""
        //anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        height: 0.0875 * parent.width * 0.5
        width:  0.0875 * parent.width * 0.5
    }
    Connections{
        target: controllStaticImg2
        function onSourceChanged(s){
            console.log("ENtrou conection controll Component 2 setSource: ", s);
            component2.source = s;
        }

        function onAlturaChanged(i){
            component2.height = i;
        }

        function onLarguraChanged(i){
            component2.width = i;

        }

        function onOpacityChanged(i){
            component2.opacity = i;
        }
/*
        function onAnguloChanged(a){
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
        }
*/

    }
}
