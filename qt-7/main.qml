import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.15
import QtGamepad 1.0
import QtQuick.Shapes 1.14
import Qt.labs.animation 1.0



Window {
    width: 640
    height: 480
    visible: true
    color: "#292a35"
    property string property0: "none.none"
    visibility: none.none
    title: qsTr("Hello World")

    /*Item {
        id: root


        Rectangle {
            id: rectangle
            x: 40
            y: 20
            width: 120
            height: 120
            color: "red"

            TapHandler {
                onTapped: circle.r -= 10
            }
        }
    }
    function createRect(){
        var i;
        for (i = 0; i < 100; i++) {

        }
    }


    */
        function getGrid(i){
            var row = Math.ceil(i / 10)
            var coloumn = i % 10

            if(coloumn === 0)
            {
                coloumn = 10
            }

            console.log(row,coloumn)
        }
        function foo() {

            if( typeof foo.counter == 'undefined' ) {
                foo.counter = 0;
            }
            foo.counter++;
            return foo() ;
        }

        Grid {
            x: 10; y: 10
            width: 418
            height: 417
            rows: 10; columns: 10; spacing: 2


            Repeater { model: 100
                property int globalForJs: 0
                       Rectangle { width: 40; height: 40
                                   color: "white"


                                   TapHandler {
                                       onTapped: circleImage.visible = true

                                   }
                                   /*Text {
                                       id:text
                                           text: index+1
                                           visible: false
                                          font.pointSize: 20
                                          anchors.centerIn: parent }*/

                                     Image {
                                         visible: false
                                         height: 35
                                         width:35
                                         id: circleImage
                                         source:  "images/ghuti.png"
                                         anchors.centerIn: parent // the CircleCollider has its origin in the top-left
                                     }
                                     Image {
                                         visible: false
                                         height: 35
                                         width:35
                                         id: circleImage2
                                         source:  "images/ghuti2.png"
                                         anchors.centerIn: parent // the CircleCollider has its origin in the top-left
                                     }




                       }
            }
        }


}

