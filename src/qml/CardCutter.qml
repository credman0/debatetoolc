import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.13
import QtQuick.Controls.Material 2.13
Item {
    ColumnLayout {
        anchors.fill: parent
        
        ComboBox {
            textRole: "text"
            editable: true
            model: ListModel {
                id: model
                ListElement { text: "Banana"; color: "Yellow" }
                ListElement { text: "Apple"; color: "Green" }
                ListElement { text: "Coconut"; color: "Brown" }
            }
            onAccepted: {
                if (find(currentText) === -1) {
                    model.append({text: editText})
                    currentIndex = find(editText)
                }
            }
        }
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
