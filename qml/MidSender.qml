import QtQuick 2.0
import QtQuick.Controls 1.4 as OldCtrl
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Item {
	function createParameter() {
		var component = Qt.createComponent("Parameter.qml");
		var parameter = component.createObject(row, {x: 0, y: 0});

		if (parameter === null) {
			// Error Handling
			console.log("Error creating object");
		}
	}

	function sendMid() {
		var paramIndex = []
		var paramValue = []
		//param.push()


		for (var i = 0; i < row.children.length; i++) {
			paramIndex.push(row.children[i].spinBoxValue)
			paramValue.push(row.children[i].parameterValue)
		}

		gui.sendMid(midSelector.currentText, paramValue, paramIndex)
	}

	Column {
		spacing: 20
		Row {
			spacing: 20

			OldCtrl.Button {
				//anchors.centerIn: parent
				text: ""

				onClicked: sendMid()
				style: ButtonStyle {
					background: Rectangle {
						implicitWidth: 30
						implicitHeight: 30
						radius: 15
						color: control.pressed ? "#222222" : "#2A2626"
						Text {
							id: st_text
							anchors.centerIn: parent
							text: "Send"
							font.bold: true
							font.pixelSize: 12
							color: "green"
						}
					}
				}
			}

			ColumnLayout {
				width: childrenRect.width
				Text {
					text: qsTr("Mid")
					color: "white"
				}
				ComboBox {
					id: midSelector
					width: 200
					model: [
						"0001", "0002", "0003", "0004", "0005",
						"0030", "0031",
						"9999"
					]
				}
			}

			Row  {
				id: row
				spacing: 20
				/*Parameter {}
				Parameter {}*/
			}



			Button {
				anchors.bottom: parent.bottom
				text: "+"
				width: 25
				height: 35
				onClicked: createParameter()
			}
		}
	}

}
