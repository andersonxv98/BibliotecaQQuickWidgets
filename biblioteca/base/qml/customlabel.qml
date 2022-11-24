import QtQuick

Item {
    anchors.fill: parent
    Text {
        id: ctText
        text:"customizado"
        transform: Rotation{
            id: rtText

        }

    }
    Connections{
        target: controlltext

        function onTextChanged(s){
            ctText.text = s;
        }

        function onFontSizeChanged(s){
            ctText.font.pointSize = s;
        }

        function onFontFamilyChanged(s){
            ctText.font.family = s;
        }

        function onCorChanged(s){
            ctText.color = s;
        }

        function onAlturaChanged(i){
            ctText.height = i;
        }

        function onLarguraChanged(i){
            ctText.width = i;

        }

        function onOpacityChanged(i){
            ctText.opacity = i;
        }

       /* function onAnguloChanged(a){
            rtText.angle = a;

        }
        function onAxisXChanged(r){
            rtText.axis.x = r;
        }
        function onAxisYChanged(r){
            rtText.axis.y = r;
        }
        function onAxisZChanged(r){
           rtText.axis.z = r;
        }
        function onOriginXChanged(o){
           rtText.origin.x= o;
        }
        function onOriginYChanged(o){
           rtText.origin.y= o;
        }*/
    }
}
