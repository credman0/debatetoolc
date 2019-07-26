import QtQuick 2.13
import QtQuick.Window 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.13
import QtQuick.Controls.Material 2.12

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
            SplitView.preferredWidth: 240
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
        Item {
            ColumnLayout {
                anchors.fill: parent
                Pane {
                    
                    Material.elevation: 3
                    Layout.fillWidth: true
                    Layout.margins: 5
                    GridLayout {
                        anchors.fill: parent
                        columns: 3
                        ColumnLayout{
                            Label {
                                text: "Author"
                                
                                
                            }
                            TextField {
                                    selectByMouse: true
                                
                            }
                        }
                        ColumnLayout{
                            Label {
                                text: "Date"
                                
                                
                            }
                            TextField {
                                
                                    selectByMouse: true
                            }
                        }
                        ColumnLayout{
                            Layout.fillWidth: true
                            Label {
                                text: "Other Cite Info"
                                
                                Layout.fillWidth: true
                                
                            }
                            RowLayout {
                                Layout.fillWidth: true
                                Label {
                                    text: "("
                                }
                                TextArea {
                                    Layout.fillWidth: true
                                    wrapMode: TextEdit.Wrap
                                    selectByMouse: true
                                }
                                Label {
                                    text: ")"
                                    
                                }
                            }
                        }
                    }
                }
                Pane {
                    
                    Material.elevation: 6
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 5
                    ScrollView {
                        anchors.fill: parent
                        TextArea {
                            wrapMode: TextEdit.Wrap
                            selectByMouse: true
                        }
                    }
                }
            }
        }
    }
    
}
