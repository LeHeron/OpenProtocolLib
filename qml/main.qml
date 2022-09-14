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

	Connections {
		target: gui
		function onUpdateResponse(response) {
			responseField.text = response
		}
	}


	Pane {
		anchors.fill: parent
		focusPolicy: Qt.ClickFocus
	}

	ColumnLayout {
		spacing: 100
		width: parent.width

		Status {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 50}

		MidSender {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 60}
		MidSender {Layout.alignment: Qt.AlignLeft; Layout.preferredHeight: 60}

		Row {
			spacing: 20
			Label {
				text: "Response:"
			}

			TextField {
				id: responseField
				width: 500
				placeholderText: "No response received yet"
				readOnly: true
			}
		}

	}
}

/*##^##
Designer {
	D{i:0;formeditorZoom:0.75}
}
##^##*/
