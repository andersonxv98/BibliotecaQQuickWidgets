import QtQuick

Item {
    anchors.fill:parent
    Rectangle{
        id: btn
        height:100
        width: 100
        //color: "red"
        transform : Rotation {
            id: rotacaobtn
            origin.x: 0; origin.y: 0; axis { x: 0; y: 0; z: 0 } angle: 0 }

        Loader{
            anchors.fill: parent
            source: "qrc:/customlabel.qml"
        }
        TapHandler{
            onTapped: {
                btn.color = btnctrl.getCor();
            }
        }
    }
    Connections{
        target: btnctrl
        function onCorChanged(s){
           // console.log( "Conteceu"+ s);
           btn.color = s;

        }

        function onLarguraChanged(i){
           btn.width = i;

        }

        function onAlturaChanged(i){
            btn.height = i;
        }

        function onOpacityChanged(i){
            btn.opacity = i;
        }

        function onBordaCorChanged(cor){
            btn.border.color = cor;
        }
        function onBordaWidthChanged(val){
            btn.border.width = val;
        }
        function onRadiusChanged(r){
            btn.radius= r;
        }
        function onGradientsChanged(list_g){
            console.log(list_g)
            console.log(list_g[0])

        }
        function onAnguloChanged(a){
            rotacaobtn.angle = a;
        }

        function onAxisXChanged(r){
            rotacaobtn.axis.x = r;
        }
        function onAxisYChanged(r){
            rotacaobtn.axis.y = r;
        }
        function onAxisZChanged(r){
            rotacaobtn.axis.z = r;
        }
        function onOriginXChanged(o){
            rotacaobtn.origin.x= o;
        }
        function onOriginYChanged(o){
            rotacaobtn.origin.y= o;
        }


    }

}
