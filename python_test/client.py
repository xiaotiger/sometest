import socket
while 1 :
    sc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sc.connect(("127.0.0.1", 8199))
    sc.send("client....")
    print "send ok"
    recv_data = sc.recv(1024)
    print "recv_data", recv_data
    sc.close()
