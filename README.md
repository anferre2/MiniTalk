# 📨 Minitalk

The **Minitalk** project is a communication program built using **UNIX signals**.  
It allows a **client** to send messages to a **server** process, character by character, using only signals.

---

## 🚀 Project Overview

- **Goal:** Implement interprocess communication using only `SIGUSR1` and `SIGUSR2`.  
- **Components:**
  - **Server**: waits for messages from the client.  
  - **Client**: encodes and sends a string message to the server using signals.  
- **Encoding:**  
  - Each bit of a character is sent as a signal.  
  - `SIGUSR1` → bit `1`  
  - `SIGUSR2` → bit `0`

---

## 📋 Features

- Send any ASCII string from client → server.  
- Messages are **rebuilt bit by bit** on the server side.  
- Server prints the received message on standard output.  
- Handles multiple characters and entire strings.  
- Memory management ensures messages are freed after being printed.

---

▶️ Usage Example

Start the server: 

`./server`

Displays the PID of the server.

Run the client: 

`./client <server_pid> "Hello World!"`

<server_pid> → replace with the number shown by the server.

"Hello World!" → the message you want to send.

The server prints the received message:

`Hello World!`

👨‍💻 Author

André Lima
