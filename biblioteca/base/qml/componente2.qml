import QtQuick

Item {
    Image {
        id: componente2
        source: ""
        anchors.horizontalCenter: imagemId.horizontalCenter
        anchors.verticalCenter:   imagemId.verticalCenter
    }




        Connections{
            target: controllStaticImg2
            function onSourceChanged(s){
                componente2.source = s;

            }
    }
}
