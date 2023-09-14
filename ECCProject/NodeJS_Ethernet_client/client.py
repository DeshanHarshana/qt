import socket

def main():
    """Create a TCP socket and connect to the Qt C++ library."""

    host = "127.0.0.1"  # The IP address of the Qt C++ library
    port = 5000  # The port of the Qt C++ library

    # Create a TCP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the Qt C++ library
    sock.connect((host, port))

    # Send some data to the Qt C++ library
    sock.sendall("Hello, world!".encode("utf-8"))

    # Receive data from the Qt C++ library
    data = sock.recv(1024)

    # Close the connection
    sock.close()

if __name__ == "__main__":
    main()
