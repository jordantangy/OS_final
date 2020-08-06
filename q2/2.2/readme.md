To run the client and server you should go throught the following steps:

1- Open two terminals.
2- In the first terminal : 
    a- write : make server , then press enter.
    b- write : ./server.o , then press enter.
    c - look at the server pid and remember it for the next step

4- In the second terminal :
    a- write : make client , then press enter.
    b- write : ./client.o "server_pid"  "type_of_signal"  "number_of_signals". 
    Here is an example : ./client 1142 2 100 (1142 is the server pid, 2 is the type of signal and 100 is the number of signals we want to send).

5- If you want to send more signals of type SIGINT or SIGUSR1, repeat the step 4 starting from b. 
    When you will send SIGUSR1, the server will terminate and show how many signals SIGINT the server received.

*** If you want to repeat the process from the beginning , write in the command line : make clean, and then start again from step 2 ***