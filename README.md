# 42-Berlin-minitalk

This is a simple client-server communication program in C that allows the client to send a string to the server using signals. The server, upon receiving the string, will print it. The program uses the concept of signals in C for inter-process communication.

**Languages**

[![My Skills](https://skillicons.dev/icons?i=c)](https://skillicons.dev)

**Features**

- The server is started first and prints its PID upon launch.
- The client takes two parameters: the server PID and the string to send.
- The server displays the received string pretty quickly.
 
**Resources**

- https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/s/sigaction.html
- https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/s/sigaction_struct.html

**Usage**

- Compile and create the executables
  ```
  make
  ```
  For Bonus:
  ```
  make bonus
  ```
- Start the server
  ```
  ./server
  ```
  For Bonus:
  ```
  ./server_bonus
  ```
- Run the client by executing the client executable and passing the server PID and the string to send as arguments
  ```
  ./client <server_pid> <string_to_send>
  ```
  For Bonus:
  ```
  ./client_bonus <server_pid> <string_to_send>
  ```
  Example
  ```
  ./client 12345 "Hello, server! This is a test message."
  ```
  
**Result: :one::two::five: / :one::zero::zero: :heavy_check_mark:**

