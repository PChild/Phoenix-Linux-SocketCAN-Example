# Phoenix-Linux-SocketCAN-Example

General example using CTRE Phoenix class library on Linux/RaspPi platforms.
## CAN USB Adapter
SocketCAN USB adapter used below.
- Firmware : https://github.com/HubertD/candleLight_fw
- Hardware : https://www.amazon.com/dp/B0BPY5HY6C

# Software Setup
## Initial Setup 
1. Update system:
     -  `sudo apt update`    
     -  `sudo apt upgrade`  
2.	Install CAN tools, git, and cmake:
     - `sudo apt install can-utils git cmake`  
3. Clone this repo into user directory  
4. Navigate into repo 
      - `cd ./Phoenix-Linux-SocketCAN-Example/.`
5.	Chmod shell scripts to allow you to use them:  
      - `chmod +x *.sh`

## CAN adapter hot plugging
1. Edit the network interfaces file: 
    - `sudo nano /etc/network/interfaces`
2. Copy the following lines to the end of the file and save  
    `allow-hotplug can0`    
    `iface can0 can static`     
    `bitrate 1000000`    
    `up /sbin/ip link set $IFACE down`    
    `up /sbin/ip link set $IFACE up type can`s
     
# Validating SocketCan functionality 
1. Make sure you have talons or another CTRE CAN device connected for validation of can network.
2. Use `ifconfig` to display status of the CAN socket.
3. The first network listed should be can0 and should look like this
![can0](https://user-images.githubusercontent.com/51933047/63381988-c6733e80-c367-11e9-91fc-7e2f620fea02.png).  
4. Type `cansend can0 999#DEADBEEF` to send a CAN frame, your talons should now blink orange since a valid CAN message has been seen.
5. Use `candump can0` to see all incoming CAN traffic, which should display all periodic information being sent by a Talon.  
6. You should see a constant stream of messages similar to this:![candump](https://user-images.githubusercontent.com/51933047/63384109-2f5cb580-c36c-11e9-8688-d3fa774eab43.png)
7. To end the stream press `Ctrl+z`.


# Running Socket Can Example: 
1.	Run Build.sh with `./build.sh`.
2.	Run program with `./run.sh`.
3.	You're now running Phoenix on your device. Confirm there are no error messages being sent to console output.
4.	You can stop your Program with `Ctrl+z`.

# Connecting to Diagnostics server:
## Setting up Phoenix Tuner
SSH must be enabled on the Linux machine to field upgrade or modify a device's configuration using Phoenix Tuner.
1. Make sure your device is connected to the same network as the Windows PC you want to run Tuner on. 
2. Run `ifconfig` to find ip address of Linux machine
3. If using Tuner X set ssh credentials in the settings page
4. Enter the Linux machine's IP address or hostname into Phoenix Tuner. 


You can disable the diagnostics server in your program by adding ``c_SetPhoenixDiagnosticsStartTime(-1);`` to the start
of your main method. The line is commented out in the example program.
