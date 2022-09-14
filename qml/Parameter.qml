import QtQuick 2.15
import QtQuick.Controls 1.4 as OldCtrl
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ColumnLayout {
	property alias spinBoxValue: spinBox.value
	property alias parameterValue: parameterField.text

	function destroyItem() {
		destroy()
	}

	width: childrenRect.width

	RowLayout {
		Text {
			text: qsTr("Parameter")
			color: "white"
		}

		OldCtrl.Button {
			Layout.alignment: Qt.AlignRight
			text: ""
			onClicked: destroyItem()

			style: ButtonStyle {
				background: Rectangle {
					implicitWidth: 20
					implicitHeight: 20
					radius: 15
					color: control.pressed ? "#222222" : "#2A2626"
					Text {
						id: st_text
						anchors.centerIn: parent
						text: "-"
						font.bold: true
						font.pixelSize: 12
						color: "red"
					}
				}
			}
		}

	}

	Row {
		spacing: 10

		OldCtrl.SpinBox {
			id: spinBox
			style: SpinBoxStyle {
				selectedTextColor: "#CF6679"
				selectionColor: "white"
				background: Rectangle {
					implicitWidth: 50
					implicitHeight: 40
					color: "#322f2f";
					border.color: "#121212"
					border.width: 1
					radius: 4
				}
				textColor: "white";
			}

		}

		TextField {
			id: parameterField
			placeholderText: qsTr("Parameter value")
			validator: RegularExpressionValidator{
				regularExpression: /^[1-9]*/
			}
		}
	}
}

