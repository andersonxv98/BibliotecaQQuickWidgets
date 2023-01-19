import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Item {
    anchors.fill: parent

    Rectangle{
        id: screenMain
        width: parent.width
        height: parent.height
        color: "#363636"

        Component.onCompleted: {
            forceActiveFocus()
        }


        Keys.onPressed:   (event)=> {
                if (event.key === Qt.Key_Space || event.key == Qt.Key_Return) {
                    console.log("enter, on login window")
                    doLogin()

                }
            }

        Rectangle{
            width: getWidth()
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            radius: 10
            gradient: Gradient{
                GradientStop { position: 0.0; color: "#110063" }
                GradientStop { position: 1.1; color: "black" }
            }
            Image{
                width: parent.height / 4
                height:    width
                id: logoId
                //color: "black"
                y: getRelativeSizeByHeigthRoot(0.03)
                anchors.horizontalCenter: parent.horizontalCenter

                source: "qrc:/logo-anglo.png"
            }
            Rectangle{
                id: camposId
                anchors.top: logoId.bottom
                anchors.topMargin: screenMain.height * 0.05
                color: "transparent"
                width: parent.width * 0.90
                x: parent.width * 0.1 /2
                height: parent.height /5
                //radius: 50

                Rectangle{
                    id: user
                    width: parent.width
                    height: parent.height /2
                    color: "transparent"

                    Text {

                        id: raLabel
                        text: qsTr("RA:  ")
                        font.pointSize: 20
                        //anchors.verticalCenter: parent.verticalCenter
                        color: "white"
                       // anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Rectangle{
                        height: raLabel.height
                         width: parent.width - raLabel.width
                        anchors.right:  parent.right
                        anchors.bottom: raLabel.bottom
                        color: "black"
                        radius: 10
                        border.color: "white"
                        TextInput{
                            id: raTb
                            width: parent.width
                            height: parent.height
                             text:  "1"
                            //placeholderText: "12345323"
                            font.pointSize: 20
                            color: "white"
                            selectedTextColor : "black"
                            selectionColor: "white"
                            maximumLength: 10
                            horizontalAlignment: TextInput.AlignHCenter
                            cursorVisible: false
                            //radius: 10
                        }

                    }
                    Rectangle{
                        id: line
                        width: parent.width
                        height: 5
                        color: "transparent"
                        anchors.top:  raLabel.bottom
                    }
                    Text {
                        id: passLabel
                        text: qsTr("SENHA:  ")
                        font.pointSize: 20
                        anchors.top:  line.bottom
                        color: "white"
                        //anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Rectangle{
                        height: passLabel.height
                        width: parent.width - passLabel.width
                        color: "black"
                        anchors.right:  parent.right
                        anchors.bottom: passLabel.bottom
                        radius: 10
                        border.color: "white"

                        TextInput{
                            id: passTb
                            text:  "1234"
                            height: parent.height
                            width: parent.width
                            maximumLength: 12
                            //placeholderText: "******"
                            echoMode: TextInput.Password
                            font.pointSize: 20
                            color: "white"
                            selectedTextColor : "black"
                            selectionColor: "white"
                            wrapMode: TextInput.NoEcho
                            horizontalAlignment: TextInput.AlignHCenter
                            cursorVisible: false

                        }
                    }
                }
                /*Rectangle{
                    id: password
                    width: parent.width
                    height: parent.height /2
                    anchors.top: user.bottom
                    color: "transparent"

                }*/

                Rectangle{
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: parent.height /5
                    color: "#02518A"
                    radius: 10
                    //border.color: "#d97c75"
                    //border.width: 10
                    Text{
                        text: "Login"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter:  parent.horizontalCenter
                        font.pointSize: 20
                        color: "white"

                    }
                    TapHandler{
                        id: loginTap
                        onTapped: {
                        console.log("Yameteeee")
                            doLogin()
                        }
                    }
                    Connections{
                        target: materias_est
                    }
                }
            }

        }


    }

    Connections{
        target: login
    }


    function getWidth(){
        var w = screenMain.width
        var h  = screenMain.height
        if(w > h){
            w =w/3
        }
        return w;
    }

    function getRelativeSizeByHeigthRoot(percent){
         var h  = screenMain.height
        return (percent * h);
    }


    function doLogin(){
        var auth = login.login(raTb.text, passTb.text);
        if(auth){
             screenMain.parent.parent.parent.children[1].children[0].visible = true; //dumpItemTree()
            screenMain.visible = false
            screenMain.focus = false;
            materias_est.doRequest()
        }
    }

}
