import QtQuick


Item {
    anchors.fill: parent
    Image {
        id: ponteiroId
        source: ""
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        height: parent.width * 0.35
        width: parent.width * 0.1
        transform: Rotation{
            id: rtPonteiro
            origin.x: ponteiroId.width * 0.5;
            origin.y: ponteiroId.height;
            angle: controllPonteiro.getAngulo();
            axis { x: 0; y: 0; z: 1 }

        }
        Component.onCompleted: {
            forceActiveFocus();
        }

        Keys.onPressed: (event)=>{
            console.log("Pressionbou")
            if(event.key === Qt.Key_Space){
                 //rtPonteiro.origin.x= controllPonteiro.getOriginX()  //ponteiroId.width * 0.5;
                 //rtPonteiro.origin.y= controllPonteiro.getOriginY()//ponteiroId.height;
                 rtPonteiro.angle += controllPonteiro.getAngulo()
            }
            else if(event.key === Qt.Key_E){
                 //rtPonteiro.origin.x= controllPonteiro.getOriginX()  //ponteiroId.width * 0.5;
                 //rtPonteiro.origin.y= controllPonteiro.getOriginY()//ponteiroId.height;
                 rtPonteiro.angle -= controllPonteiro.getAngulo()
            }
        }


    }
    /*Connections{
        target: controllRelogio;

        function onTimeHChange(){
            console.log("Serviço por fora");
            rtPonteiro.angle = controllRelogio.getAnguloHora();

        }
    }*/
    Connections{
        target: controllPonteiro
        function onValuesofRotationChanged(list){
            console.log("valor anguo: ",list[0])
            rtPonteiro.origin.x=list[1];
            rtPonteiro.origin.y=list[2];
            rtPonteiro.angle +=list[0];
        }


        function onSourceChanged(s){
            console.log("entrou em sorce chang");
            ponteiroId.source = s;
        }

        function onAlturaChanged(i){
            ponteiroId.height = i;

        }

        function onLarguraChanged(i){
            ponteiroId.width = i;

        }

        function onOpacityChanged(i){
            ponteiroId.opacity = i;
        }

        function onAnguloChanged(a){
            rtPonteiro.angle = a-90;

        }
        function onAxisXChanged(r){
            rtPonteiro.axis.x = r;
        }
        function onAxisYChanged(r){
            rtPonteiro.axis.y = r;
        }
        function onAxisZChanged(r){
           rtPonteiro.axis.z = r;
        }
        function onOriginXChanged(val){
           rtPonteiro.origin.x= val;
        }
        function onOriginYChanged(val){
           rtPonteiro.origin.y= val;
        }


    }
}
