import QtQuick 2.0

Item {
	property alias text: statusIndicator.text
	property alias color: statusText.color

	Connections {
		target: gui
		function onConnected(isConnected) {
			if (isConnected)
			{
				text = "Connected"
				statusIndicator.color = "green"
			}
			else
			{
				text = "Disconnected"
				statusIndicator.color = "red"
			}
		}
	}

	//height: parent.
	width: window.width
	Text {
		id: statusText
		anchors.left: parent.left
		text: qsTr("Status")
		color: "white"
	}

	Text {
		id: statusIndicator
		anchors.right: parent.right
		text: qsTr("Disconnected")
		color: "red"
	}
}
