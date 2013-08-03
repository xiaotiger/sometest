import socket
import select
import time

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serversocket.bind(("0.0.0.0", 8199))
serversocket.listen(1)
serversocket.setblocking(0)

epoll = select.epoll();
epoll.register(serversocket.fileno(), select.EPOLLIN)

def do_work(inputbuff) :
    return "time :" + str(time.time()) + "  get :" + inputbuff

try :
    connections = {}; requests = {}; responses = {}
    while True :
        events = epoll.poll(1)
        for fileno, event in events :
            if fileno == serversocket.fileno() :
                connection, address = serversocket.accept()
                connection.setblocking(0)
                epoll.register(connection.fileno(), select.EPOLLIN)
                print "new conn:", connection.fileno
                connections[connection.fileno()] = connection
            elif event&select.EPOLLIN :
                data = connections[fileno].recv(1024) 
                requests[fileno] = data
                print "epollin:", data
                if data :
                    print "modify to out"
                    responses[fileno] = do_work(requests[fileno])
                    epoll.modify(fileno, select.EPOLLOUT)
                else :
                    print "unregister"
                    epoll.unregister(fileno)
                    connections[fileno].close()
                    del connections[fileno]
                    del requests[fileno]

            elif event&select.EPOLLOUT :
                print "epollout", fileno
                bytewritten = connections[fileno].send(responses[fileno])
                epoll.modify(fileno, select.EPOLLIN)
            elif event&select.EPOLLHUP:
                print fileno, "over"
                epoll.unregister(fileno)
                connections[fileno].close()
                del connections[fileno]
                del requests[fileno]
                del responses[fileno]
finally :
    epoll.unregister(serversocket.fileno())
    epoll.close()
    serversocket.close()

