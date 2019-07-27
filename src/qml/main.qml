import QtQuick 2.13
import QtQuick.Window 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.13
import QtQuick.Controls.Material 2.13

ApplicationWindow
{
    visible: true
    width: 1280
    height: 720
    title: "Debate"
    
    Material.theme: Material.Light
    Material.accent: Material.Purple
    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Open..." }
            MenuItem { text: "Close" }
        }
        
        Menu {
            title: "Edit"
            MenuItem { text: "Cut" }
            MenuItem { text: "Copy" }
            MenuItem { text: "Paste" }
        }
    }
    SplitView {
        anchors.fill: parent
        Item {
            SplitView.preferredWidth: 360
            ColumnLayout {
                anchors.fill: parent
                Row {
                    Button {
                        text: "<"
                    }
                    Button {
                        text: ">"
                    }
                }
                Pane {
                    Material.elevation: 3
                    Layout.margins: 3
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
            
            
        }
        Page {
            header: TabBar {

                id: bar

                width: parent.width

                TabButton {

                    text: qsTr("Create Card Text and Cite")

                }

                TabButton {

                    text: qsTr("Underline, Highlight, and Set Tags")

                }

            }
            
            
            SwipeView {
                anchors.fill: parent
                width: parent.width

                currentIndex: bar.currentIndex

                CardEditor {}
                
                CardCutter {}
            }
        }
    }
    
}
