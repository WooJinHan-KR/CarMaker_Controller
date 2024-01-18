Longitudinal, Lateral Controller for CarMaker

Language : C
Sensor : Camera RSI, Lidar RSI
CarMaker Version : 12.0.1


To Use Camera RSI Sensor Client in CarMaker

1.  copy rsd-client-camera.c and rsds-client-camera.h to src or src_cm4/src_tm4sl(depends on the used environment)
2.  Modify User.c

```c
User.c
#include "rsds-client-camera.h"
...
int User_Init (void) {
...
RSDS_Init();
...
}
int User_TestRun_Start_atEnd (void) {
...
RSDS_Start();
...
}
void User_Cleanup (void) {
 ...
RSDS_Exit();
 ...
}

```
3.  Modiy Makefile

```

OBJS =	CM_Main.o CM_Vehicle.o User.o IO.o rsds-client-camera.o

```

4.  Build User.c
In MSYS 2023

```
cd :C/CM_Projects/{Your_ProjectFoldername}/src/
make
```

5.  Connect with CarMaker
* CarMakerGUI > Application > Configuration/Status
* Click the Folder ICON
* choose file on C:/CM_Projects/{Your_ProjectFolder}/src/CarMaker.win64.exe
* OK
* Start & Connect
* If you edit some code and finish to build, Disconnect CarMaker.win64.exe and reconnect

