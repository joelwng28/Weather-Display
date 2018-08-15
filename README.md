# Weather-Display
Embedded Systems Project
Lab 4 Report
Samuel Zhang (shz96), Zi Zhou Wang (zw3948)
Saadallah
2/19/2018

Objectives
The objectives of this lab was to implement a system that connects to the internet via an IEEE 802.11 - Wifi module, CC3100. We would use DNS to convert name to IP address, and configure a smart object that can retrieve data from a weather server using TCP. We also had to design a smart object that can store data onto an internet server using TCP.  Finally, we would implement a web server to log data from out smart object. There were 2 primary things that we had to accomplish: pull weather data down from openweathermap.org, and push data on to an EE445L server.  The weather data was obtained through a socket connection, and the resulting JSON was parsed to find the current temperature for the desired city (Austin in this case).  Pushing data onto the server was similar, and the on-board ADC was sampled so the data could be sent through a web socket to the server.  This whole process of gathering inputs from sensors, doing optional computations on the data locally, and sending the data off onto a server is what the Internet of Things is all about.
Measurement Data
Percentage of lost packets: Unknown, Because we are working in the application layer while TCP and packet losses are handled in the transportation layer, a percentage of packets would be lost however, those lost packets would be resent as a result of TCP, making it impossible for us to detect the amount of packets lost through the application layer. 
Minimum, maximum, and average times from 10 transmissions to openweathermap.org and Minimum, maximum, and average times from 10 transmissions to our server:

Analysis and Discussion
1) In the client server paradigm, explain the sequence of internet communications sent from client to server and from server to client as the client saves data on the server. Assume the client already is connected to the wifi AP and the client knows the IP address of the server.
The client connects to the server and then sends a request. The server then reads the request, processes it, and sends a response back to the client.
 
2) What is the purpose of the DNS?
The DNS translates domain names into IP addresses so that the computer can understand where you want to go.
 
3) What is the difference between UDP and TCP communication? More specifically when should we use UDP and when should we use TCP?
TCP is a connection oriented protocol while UDP is connectionless. TCP is thus better for information that requires high reliability such as file transfers, whereas UPD is better for cases where losing a piece of information is tolerable, such as streaming music or video.
 



