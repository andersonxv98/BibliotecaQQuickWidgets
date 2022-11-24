import QtQuick

Item {

    Image {
        id: componente1
        source: ""
       // anchors.horizontalCenter: imagemId.horizontalCenter
       // anchors.verticalCenter:   imagemId.verticalCenter
    }

    Connections{
        target: controllStaticImg
        function onSourceChanged(s){
            componente1.source = s;

        }

        function onAlturaChanged(i){
            componente1.height = i;
            //childimg.height = imagemId.height * 0.35;
            //componente2.height =imagemId.height * 0.10
        }

        function onLarguraChanged(i){
            componente1.width = i;
            //childimg.width = imagemId.width * 0.05 ;
            //componente2.width =imagemId.width * 0.10
            //childimg.anchors.centerIn =  imagemId.Center
        }

        function onOpacityChanged(i){
            componente1.opacity = i;
        }

        function onAnguloChanged(a){
            componente1.angle = a;

        }
        function onAxisXChanged(r){
            componente1.axis.x = r;
        }
        function onAxisYChanged(r){
            componente1.axis.y = r;
        }
        function onAxisZChanged(r){
           componente1.axis.z = r;
        }
        function onOriginXChanged(o){
           componente1.origin.x= o;
        }
        function onOriginYChanged(o){
           componente1.origin.y= o;
        }



    }

     anchors.horizontalCenter: imagemId.horizontalCenter
     anchors.verticalCenter:   imagemId.verticalCenter

}
