import socket

HOST = '127.0.0.1'
PORT = 4545

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind((HOST, PORT))
	s.listen()
	while True:
		conn, addr = s.accept()
		print("Connection accepted from ", addr)
		with conn:
			while True:
					data = conn.recv(1024)
					if not data:
						print("Connection closed by peer...")
						break
					print("received", data, "with last char", data[-1], "and length", len(data))
					try:
						conn.sendall(data)
					except:
						print("Exception occured : breaking loop")
						break
