#define Phoenix_No_WPI // remove WPI dependencies
#include "ctre/Phoenix.h"
#include "ctre/phoenix/cci/Unmanaged_CCI.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include <chrono>
#include <thread>

int main() {
	c_RegisterCANbus("can0");
        c_SetPhoenixDiagnosticsStartTime(-1); // diagnostic server disabled with -1

        TalonSRX tal(11);

        while (true) {
                tal.Set(ControlMode::PercentOutput, 0.1);
                c_FeedEnable(20);
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }

        return 0;
}

