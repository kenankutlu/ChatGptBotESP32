#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

const char* api_url = "https://api.openai.com/v1/chat/completions";
const char* api_key = "sk-proj-u0WfrDOn8ExJX";

// Wi-Fi bilgileri
const char* ssid = "***";
const char* password = "******";

void sendToChatGPT(const String& user_input) {
  if (WiFi.status() == WL_CONNECTED) { // Wi-Fi bağlantısı kontrolü
    WiFiClientSecure client;
    HTTPClient http;

    client.setInsecure(); // SSL doğrulamasını devre dışı bırakmak için
    http.begin(client, api_url);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String("Bearer ") + api_key);

    // ChatGPT'ye gönderilecek veri
    String json_data = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"" + user_input + "\"}]}";

    // POST isteği gönder
    int httpResponseCode = http.POST(json_data);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("ChatGPT Yanıtı: " + response);
    } else {
      Serial.print("HTTP Hatası: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Wi-Fi bağlantısı yok!");
  }
}

void setup() {
  // Seri haberleşme için başlatma
  Serial.begin(115200);
  Serial.println("ESP32 Başlıyor...");

  // Wi-Fi'ye bağlanma
  WiFi.begin(ssid, password);
  Serial.print("Wi-Fi'ye bağlanıyor");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi bağlantısı başarılı!");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sendToChatGPT("Merhaba ChatGPT, nasılsın?");
  delay(30000); // 30 saniyede bir sorgu
}
