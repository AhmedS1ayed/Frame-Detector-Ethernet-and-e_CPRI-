# Frame-Detector-Ethernet-and-e_CPRI-
## This Project is concerned with determining the type and details of the frame. <br />

#### Note : the following UML doesn't Represent the code 100% as there were lots of refactoring and clean coding to it <br /> 

#### Note : (N-M) = No. of Ecpri Frame Packets in the input where N is the number of BasicFrame = EthernetFrame . <br /> 
#### since we will instantiate BasicFrame no matter what and process it and when we find out that it is Ecpri not just Ethernet then we copy the processed values to new instance of EcpriFrame. <br /> 

#### so we can say M represent the number of not instantiated EcpriFrame. <br /> 
![Assignment 1 (mod)](https://user-images.githubusercontent.com/93644109/218083026-10238e12-5c7c-4baf-8a02-b143e72a46ff.jpg)
