Qt_Car_Control/
├── main.cpp              // 程序入口
├── MainWindow.cpp        // 主窗口逻辑
├── MainWindow.h          // 主窗口类定义
├── Communication.cpp     // 通信模块
├── Communication.h       // 通信模块类定义
├── CarControl.ui         // 主界面 UI 文件
└── Resources/            // 资源文件（如图片、图标）
STM32_Car_Control/
├── Core/
│   ├── Src/main.c        // 主程序入口
│   ├── Src/gpio.c        // GPIO 初始化
│   ├── Src/usart.c       // 串口通信
├── Drivers/
│   ├── STM32F4xx_HAL_Driver/  // HAL 库
├── ESP8266/
│   ├── esp8266.c         // Wi-Fi 通信模块
├── Sensors/
│   ├── ultrasonic.c      // 超声波传感器
│   ├── dht11.c           // 温湿度传感器
└── Motors/
    ├── l298n.c           // 电机驱动控制