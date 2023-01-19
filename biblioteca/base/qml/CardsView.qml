import QtQuick
import QtQuick.Controls

Item {
    anchors.fill: parent
    property int cont: 0;

    ListModel{

        id: modell


    }


    SwipeView {
        id: view

        //interactive: currentIndex
        currentIndex: 1;
        anchors.fill: parent
        focus: true;

        transform : Rotation {
            id: swrt
            origin.x: 0; origin.y: 0; axis { x: 0; y: 0; z: 0 } angle: 0 }




        onCurrentIndexChanged: {

            console.log("currentindice: ", currentIndex);


            if(currentIndex > 1){
              //  console.log("next")
                var l = swControll.getNext();
               // console.log(l);
                modell.append({name: l[0], background: l[1], url: l[2]})
                if(modell.count >2){
                    modell.remove(0);
                }
            }
            else{
                if(currentIndex < 1){
                    console.log(modell.rowCount());
                }
            }
        }

        Keys.onPressed: (event)=>{
           // console.log("Pressionbou")
            if(event.key === Qt.Key_Space){

                swControll.getNext();
            }
            else if(event.key === Qt.Key_E){

            }
        }

        Repeater{
                   model: modell
                 delegate:  Rectangle{

                       color: model.background
                       Text {
                           anchors.top:parent.top
                           anchors.horizontalCenter: parent.horizontalCenter
                           text: model.name
                           font.pointSize:  20;

                       }
                       Image {
                           anchors.horizontalCenter: parent.horizontalCenter
                           anchors.verticalCenter: parent.verticalCenter
                           source: model.url
                       }
                   }

               }

    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Connections{
        target: swControll;

        function updateItens(l){
            return;
        }
        function onNextChanged(l){
           // console.log("quantidade de  itens  atual: ", modell.count );

           modell.append({name: l[0], background: l[1], url: l[2]})
            if(modell.count > 1){
                view.setCurrentIndex(1);
            }
            return;
        }




        function onRmvItem(idItem){
            view.removeItem(idItem);
        }


        function onHorizontalChanged(h){
            view.horizontal = h;
        }

        function onVerticalChanged(v){
            view.vertical = v;
        }

        function onOrientationChanged(ori){
            view.orientation= ori;
        }

        function onInteractiveChanged(i){
            view.interactive = i;
        }

        function onAlturaChanged(i){
            view.height = i;
        }

        function onLarguraChanged(i){
            view.width = i;

        }

        function onOpacityChanged(i){
            view.opacity = i;
        }

        function onAnguloChanged(a){
            swrt.angle = a-90;

        }
        function onAxisXChanged(r){
            swrt.axis.x = r;
        }
        function onAxisYChanged(r){
            swrt.axis.y = r;
        }
        function onAxisZChanged(r){
           swrt.axis.z = r;
        }
        function onOriginXChanged(o){
           swrt.origin.x= o;
        }
        function onOriginYChanged(o){
           swrt.origin.y= o;
        }
    }
}
