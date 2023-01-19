import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
          // id: item${idTexto}
           anchors.fill: parent
        Rectangle{
               anchors.fill: parent
               color: "Yellow"
        Text {
            anchors.fill: parent
            //id: ${idTexto}
            height: 10
            width: 10
            text: "texte" //controllSubtxt${idTexto}.getText();
            font.family: "Helvetica"
        }

    }

 /*  Connections{
       //target: controllSubtxt${idTexto};
       function onTextChanged(s){
           ${idTexto}.text = s;
       }

       function onFontSizeChanged(s){
           ${idTexto}.font.pointSize = s;
       }

       function onFontFamilyChanged(s){
           ${idTexto}.font.family = s;
       }

       function onCorChanged(s){
           ${idTexto}.color = s;
       }

       function onAlturaChanged(i){
           ${idTexto}.height = i;
       }

       function onLarguraChanged(i){
           ${idTexto}.width = i;

       }

       function onOpacityChanged(i){
           ${idTexto}.opacity = i;
       }

   }*/

}
