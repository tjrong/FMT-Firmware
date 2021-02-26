# Build object lists

DRIVERS = [
    'gps/*.c',
    'hmc5883/*.c',
    'hw_timer/*.c',
    'l3gd20h/*.c',
    'lidar/*.c',
    'lsm303d/*.c',
    'mpu6000/*.c',
    'ms5611/*.c',
    'tca62724/*.c',
    'utils/*.c',
    'mateksys/*.c',
]

DRIVERS_CPPPATH = []

HAL = [
    '*.c',
    'mag/*.c',
    'accel/*.c',
    'barometer/*.c',
    'gps/*.c',
    'fmtio_dev/*.c',
    'gyro/*.c',
    'i2c/*.c',
    'motor/*.c',
    'pin/*.c',
    'rc/*.c',
    'serial/*.c',
    'systick/*.c',
    'tools/*.c',
    'usb/*.c',
    'optical_flow/*.c',
    'spi/spi_core.c',
    'spi/spi_dev.c',
]

HAL_CPPPATH = []

MODULES = [
    '*.c',
    'Calibration/*.c',
    'Console/*.c',
    'FS_Manager/*.c',
    'FTP/*.c',
    'Plant/*.c',
    'Plant/lib/*.c',
    'INS/*.c',
    'INS/lib/*.c',
    'Controller/*.c',
    'Controller/lib/*.c',
    'FMS/*.c',
    'FMS/lib/*.c',
    'IPC/*.c',
    'LED/*.c',
    'Log/*.c',
    'Math/*.c',
    'Mavproxy/*.c',
    'Parameter/*.c',
    'Sensor/*.c',
    'FMTIO/*.c',
    'SysIO/*.c',
    'SysCmd/*.c',
    'System/*.c',
    'Unit_Test/*.c',
    'Utils/*.c',
    'Vehicle/*.c',
    'BuzzerTune/*.c',
    'Filter/*.c',
    'TOML/*.c',
]

MODULES_CPPPATH = [
    'Calibration',
    'INS/lib',
    'Plant/lib',
    'Controller/lib',
    'FMS/lib',
    'FS_Manager',
    'BuzzerTune',
]

TASKS = [
    'vehicle/multicopter/*.c',
    'comm/*.c',
    'logger/*.c',
    'fmtio/*.c',
    'status/*.c',
]

TASKS_CPPPATH = []

LIBS = [
    'cm_backtrace',
    'mavlink',
    'Micro-XRCE-DDS-Client',
    'stm_lib/stm32f4',
]