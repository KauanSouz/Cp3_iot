#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Dados da rede Wi-Fi
const char* ssid = "Kauan Iphone";
const char* password = "080402";

// Configurações do servidor MQTT
const char* mqttServer = "192.168.15.99";
const int mqttPort = 1883;
const char* mqttUser = "Kauanfiap";
const char* mqttPassword = "kauanfiap@986975987";

// Tópico MQTT
const char* mqttTopic = "equipeX/esp32/sensores";

WiFiClient espClient;
PubSubClient client(espClient);

void conectarMQTT() {
  while (!client.connected()) {
    Serial.println("[MQTT] Conectando ao broker...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword)) {
      Serial.println("[MQTT] Conectado com sucesso!");
    } else {
      Serial.print("[MQTT] Falha na conexão. Código de erro: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void enviarDadosMQTT(float temp, float umi, float pres, float alt) {
  String payload = "{";
  payload += "\"temp\":" + String(temp, 1) + ",";
  payload += "\"umi\":" + String(umi, 1) + ",";
  payload += "\"pres\":" + String(pres, 1) + ",";
  payload += "\"alt\":" + String(alt, 1);
  payload += "}";

  client.publish(mqttTopic, payload.c_str());
  Serial.println("[MQTT] Dados enviados: " + payload);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("[WIFI] Conectando ao Wi-Fi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("[WIFI] Conectado com sucesso!");
  Serial.print("[WIFI] IP local: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqttServer, mqttPort);
  conectarMQTT();
}

void loop() {
  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();

  // Simulação dos dados dos sensores
  float temp = random(200, 350) / 10.0;   // 20.0 a 35.0
  float umi = random(400, 800) / 10.0;    // 40.0 a 80.0
  float pres = random(9800, 10500) / 100.0; // 980.0 a 1050.0
  float alt = random(0, 500);            // 0 a 500 metros

  Serial.println("[SENSOR] Enviando novos dados...");
  enviarDadosMQTT(temp, umi, pres, alt);

  delay(10000); // Envia a cada 10 segundos
}
