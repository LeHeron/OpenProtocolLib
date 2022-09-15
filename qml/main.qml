import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Window {
	id: window
	width: 1024
	height: 512
	visible: true
	title: qsTr("Hello World")
	Material.theme: Material.Dark;

	function clearResponse() {
		responseField.text = ""
	}

	Connections {
		target: gui
		function onUpdateResponse(mid, indexValue, paramValue) {

			responseField.text = "MID: " + mid
			for (var i = 0; i < indexValue.length; i++)
				responseField.text += "\ni: " + indexValue[i] + " = <" +  paramValue[i] + ">"
		}
	}

	Pane {
		anchors.fill: parent
		focusPolicy: Qt.ClickFocus
	}

	ColumnLayout {
		spacing: 20
		width: parent.width

		Status {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 50}

		MidSender {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 60}
		MidSender {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 60}

		Row {
			spacing: 20
			Label {
				text: "Response:"
			}



			Button {
				text: "Clear"
				onClicked: clearResponse()
			}
		}
		TextArea {
			id: responseField
			width: parent.width
			Layout.fillHeight: true
			placeholderText: "No response received yet"
			readOnly: true
			selectByMouse: true
			//wrapMode:
		}

	}
}
