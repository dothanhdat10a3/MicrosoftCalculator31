import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ToDo 1.0


Window {
    width: 320
    height: 505
    visible: true
    title: qsTr("MS CALCULATOR")
    Number{
        id: numberClass
    }
    Rectangle{
        id: recttest
        width:100
        height:100
        x: 0
        y:400
        color:"red"
        Text{
            id: texttest
            anchors.fill:parent
            text:numberClass.getIndexHex
        }
    }


    property var numberHex
    property var numberDec
    property var numberOct
    property var numberBin

    function arrHex(){
        a="";
        for(var i=0;i<2;i++)
          a += numberHex[i]+'';

           return a;
       }


    Text{
        id:programNameText
        anchors.left: parent.left
        anchors.top: parent.top
        text: "Programmer"
        color: "black"
        font.pixelSize: 20
        font.family: "Open Sans Regular"
        fontSizeMode: Text.Fit

    }
    Rectangle{
        id: expressionArea
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: programNameText.bottom
        height: 30
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
    }

    //resultArea
    Rectangle {

        id: resultArea
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: expressionArea.bottom
        height: 40
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
        Text {
            id: resultText
            anchors.leftMargin: buttons.implicitMargin
            anchors.rightMargin: buttons.implicitMargin
            anchors.fill: parent
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.TopRight
            text: "0"
            color: "black"
            font.pixelSize: 25
            font.family: "Arial"
            fontSizeMode: Text.Fit
        }
    }
    //hexResult
    Rectangle {
        id: hexResult
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: resultArea.bottom
        height:23.5
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
        Rectangle{
            id:hex
            x:0
            y:0
            height: hexResult.height
            width: hexResult.height*2
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: hexadecimal
                text: "HEX"
                anchors.centerIn: hex
                color: "black"
                font.pixelSize: 10
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        Rectangle{
            id:hexValue
            anchors.left: hex.right
            height: hexResult.height
            width:hexResult.width-hex.width
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {

                id: hexadecimalValue
                text: a
                anchors.left: hexValue.left
                anchors.leftMargin: 5

                color: "black"
                font.pixelSize: 12
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        MouseArea
        {
            anchors.fill: hexResult
            onClicked: {
                hex.color = "#D3D3D3"
                hexValue.color= "#D3D3D3"
                // Qt.quit();
            }
        }

    }
    //DecResult
    Rectangle {
        id: decResult
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: hexResult.bottom
        height:23.5
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
        Rectangle{
            id:dec
            x:0
            y:0
            height: decResult.height
            width: decResult.height*2
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: decadecimal
                text: "DEC"
                anchors.centerIn: dec
                color: "black"
                font.pixelSize: 10
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        Rectangle{
            id:decValue
            anchors.left: dec.right
            height: decResult.height
            width:decResult.width-dec.width
            border.color: "black"
            border.width: 1
            color: "red"
            Text {
                id: decimalValue
                text: numberDec[0]+''+numberDec[1]
                anchors.left: decValue.left
                anchors.leftMargin: 5
                color: "black"
                font.pixelSize: 12
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        MouseArea
        {
            anchors.fill: decResult
            onClicked: {
                dec.color = "#D3D3D3"
                decValue.color= "#D3D3D3"
                // Qt.quit();
            }
        }

    }

    //octResult
    Rectangle {
        id: octResult
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: decResult.bottom
        height:23.5
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
        Rectangle{
            id:oct
            x:0
            y:0
            height: octResult.height
            width: octResult.height*2
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: octal
                text: "OCT"
                anchors.centerIn: oct
                color: "black"
                font.pixelSize: 10
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        Rectangle{
            id:octValue
            anchors.left: oct.right
            height: octResult.height
            width:octResult.width-oct.width
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: octalValue
                text: numberOct[0]+''+numberOct[1]+''+numberOct[2]
                anchors.left: octValue.left
                anchors.leftMargin: 5
                color: "black"
                font.pixelSize: 12
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        MouseArea
        {
            anchors.fill: octResult
            onClicked: {
                oct.color = "#D3D3D3"
                octValue.color= "#D3D3D3"
                // Qt.quit();
            }
        }
    }
    //binResult
    Rectangle {
        id: binResult
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: octResult.bottom
        height:23.5
        border.color: "black"
        border.width: 1
        color: "#E8E8E8"
        Rectangle{
            id:bin
            x:0
            y:0
            height: binResult.height
            width: binResult.height*2
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: binary
                text: "BIN"
                anchors.centerIn: bin
                color: "black"
                font.pixelSize: 10
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        Rectangle{
            id:binValue
            anchors.left: bin.right
            height: binResult.height
            width:binResult.width-bin.width
            border.color: "black"
            border.width: 1
            color: "#E8E8E8"
            Text {
                id: binaryValue
                text: numberBin[0]
                anchors.left: binValue.left
                anchors.leftMargin: 5
                color: "black"
                font.pixelSize: 12
                font.family: "Arial"
                fontSizeMode: Text.Fit
            }
        }
        MouseArea
        {
            anchors.fill: binResult
            onClicked: {
                bin.color = "#D3D3D3"
                binValue.color= "#D3D3D3"
                // Qt.quit();
            }
        }

    }
/*
    //StackView
    Rectangle{
    id: multiview
    anchors.top:binResult.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    height:315
    border.color: "black"
    border.width: 1
    color: "#E8E8E8"

    }
    */
}
