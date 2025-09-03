# MiniTalk

📡 **MiniTalk** is a project from 42 that implements a simple communication system between two programs — a *server* and a *client* — using **UNIX signals** (`SIGUSR1` and `SIGUSR2`).  
The client sends a string of characters to the server, which receives and prints it in the terminal.

---

## 🛠️ How it works
- The server waits for connections and displays its **PID** in the terminal.  
- The client sends a message to the server’s PID, **bit by bit**, using signals (`SIGUSR1` and `SIGUSR2`).  
- The server rebuilds the characters from the received bits and prints the message.  

---

## 🚀 Compilation
Compile the project using the `Makefile`:

```bash
make

This will generate two executables:

    server

    client

▶️ Usage

    Start the server:

./server

It will display something like:

Server PID: 4242

In another terminal, start the client with the server PID and your message:

./client 4242 "Hello MiniTalk!"

The server will then output:

    Hello MiniTalk!

📑 Project Requirements

    Communication must be done only with UNIX signals (SIGUSR1 and SIGUSR2).

    The client must be able to send any string (ASCII characters).

    The server must handle multiple messages, one after the other.

🧠 Learnings

This project helps understanding:

    Signal handling (sigaction, kill).

    Encoding and decoding messages bit by bit.

    Synchronization between processes.

🏆 Author

👨‍💻 André Ferreira
