# Projeto IOT_Cp3 — ESP32 + MQTT + Wokwi

## 🔍 Descrição

Este projeto simula um dispositivo IoT utilizando o ESP32, que coleta dados de sensores ambientais (temperatura, umidade, pressão e altitude) e os envia para um broker MQTT. Toda a simulação é realizada na plataforma [Wokwi](https://wokwi.com/), dispensando a necessidade de hardware físico durante o desenvolvimento.

## 🌐 Funcionalidades

- Conexão automática com rede Wi-Fi configurada
- Envio de dados simulados para um broker MQTT
- Mensagens exibidas no Serial Monitor para acompanhamento
- Simulação de sensores e feedback visual com LED

## ⚙️ Tecnologias

- ESP32 DevKit v1
- Arduino (via PlatformIO)
- MQTT com autenticação
- Simulador Wokwi
- Broker local (em servidor Linux)

## Pré-requisitos

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO IDE](https://platformio.org/install/ide?install=vscode)
- Conta no [Wokwi](https://wokwi.com/)
- Broker MQTT (como o [Mosquitto](https://mosquitto.org/) ou serviços online como o [HiveMQ](https://www.hivemq.com/))

## Instalação

1. **Clone o repositório:**

   ```bash
   git clone [https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git](https://github.com/arnaldojr/iot-esp32-wokwi-vscode.git)