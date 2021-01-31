import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Templates 2.15
import Qt.labs.animation 1.0

Window {
    width: 640
    height: 480
    visible: true
    color: "#241d2b"
    title: qsTr("Hello World")

    Grid {
        id:grid_vaia
        x: 10; y: 10
        width: 418
        height: 418
        property bool defineColor: true
            rows: 10; columns: 10; spacing: 2

            Repeater { model: 100
                       Rectangle { width: 40; height: 40
                                   color: "white"


                                   MouseArea{
                                       anchors.fill: parent
                                       TapHandler{
                                           id:tapped
                                           onTapped: reply(index)


                                       }

                                   }
                                   function reply(n){
                                       var x = uiBridge.showLog(n)
                                       if(x>0){
                                          ghuti.visible = true
                                          draw(x)
                                      }
                                   }

                                   Rectangle {
                                       id: ghuti
                                       visible: false
                                       radius: width*0.5
                                       anchors.fill: parent
                                       anchors.rightMargin: 5
                                       anchors.leftMargin: 5
                                       anchors.bottomMargin: 5
                                       anchors.topMargin: 5
                                       //anchors.fill: parent
                                       color: "red"
                                   }



            }
        }


        /*MouseArea {
            anchors.fill: parent
            onClicked: console.log(Length)
        }*/


    }
    function getX(){

        if(uiBridge.countRet() % 10 !=0 ){
            return uiBridge.countRet() % 10  -1
        }
        else return 9
    }
    function getY(){

        var x = Math.ceil((uiBridge.countRet() / 10))-1
        console.log(x)
        return x
    }

    function draw(a){
        var newObject = Qt.createQmlObject('import QtQuick 2.0; Rectangle {color: "black"; width: 30; height: 30;radius: width*0.5;anchors.rightMargin: 5;
                                       anchors.leftMargin: 5;
                                       anchors.bottomMargin: 5;
                                       anchors.topMargin: 5;anchors.fill: parent}',
                                                        grid_vaia.children[a],
                                           "dynamicSnippet1");




}
    Item {
        function myQmlFunction(msg) {
            console.log("Got message:", msg)
            return "some return value"
        }
    }

    Text {
        id: text1
        x: 485
        y: 166
        width: 114
        height: 36
        color: "#fcf6f6"
        text: qsTr("Com win")
        font.pixelSize: 22
    }
}
