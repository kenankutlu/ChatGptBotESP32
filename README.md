# ChatGPT API Integration with ESP32

This project demonstrates how to connect an ESP32 to OpenAI's ChatGPT API using Wi-Fi. The code sends user input to the API and receives responses, which are printed to the serial monitor.

## Features

- Connects the ESP32 to a Wi-Fi network.
- Sends user input to the OpenAI ChatGPT API.
- Displays ChatGPT's response via the serial monitor.
- Sends queries to ChatGPT every 30 seconds.

---

## Requirements

1. **Hardware**: 
   - ESP32 microcontroller.
2. **Software**:
   - Arduino IDE.
   - Wi-Fi credentials (SSID and password).
   - OpenAI API key.

---

## Installation and Setup

1. **Hardware Setup**:
   - Connect your ESP32 to your computer via USB.

2. **Software Configuration**:
   - Open the code in Arduino IDE.
   - Replace `***` with your Wi-Fi SSID and `******` with your Wi-Fi password.
   - Replace `sk-proj-u0WfrDOn8ExJX` with your actual OpenAI API key.

3. **Upload Code**:
   - Select the appropriate **ESP32 board** from the `Tools` menu in Arduino IDE.
   - Upload the code to your ESP32.

4. **Run the Program**:
   - Open the serial monitor (set to 115200 baud rate).
   - Observe the Wi-Fi connection status and ChatGPT API interactions.

---

## Code Breakdown

### Wi-Fi Connection
The ESP32 connects to a Wi-Fi network using the provided SSID and password:
```cpp
WiFi.begin(ssid, password);
```
The code ensures the device does not proceed until the connection is established.

### Sending Data to ChatGPT
The function `sendToChatGPT` prepares and sends a POST request to the ChatGPT API:
- A JSON payload is created containing the user query.
- The response is printed to the serial monitor.

### API Communication
The following headers are used for authentication and communication:
- `Authorization`: Includes the Bearer token for API authentication.
- `Content-Type`: Indicates JSON data is sent.

### Repeating Queries
The `loop` function sends a query to ChatGPT every 30 seconds:
```cpp
delay(30000); // 30-second delay
```

---

## Notes and Considerations

- **Security**:
  - Use a secure and encrypted connection (`WiFiClientSecure`).
  - Store sensitive information (like API keys) securely.
- **Error Handling**:
  - If the Wi-Fi connection fails or the API request encounters an error, messages are printed to the serial monitor.
- **Rate Limits**:
  - OpenAI's API may impose rate limits. Ensure your requests comply with their terms.

---

## Sample Output

Upon successful execution, you can expect the following in the serial monitor:

```
ESP32 Başlıyor...
Wi-Fi'ye bağlanıyor...
Wi-Fi bağlantısı başarılı!
IP Adresi: 192.168.1.100
ChatGPT Yanıtı: { "id": "...", "object": "chat.completion", "choices": [ ... ] }
```

---

## License

This project is free to use and modify. Ensure compliance with OpenAI's API usage terms.


### Check Out My YouTube Channel!  
For more tech-related content and projects, visit my YouTube channel:  
[Kenan Kutluyum](https://www.youtube.com/@KenanKutluyum)  

Don’t forget to subscribe and stay tuned for more updates! 🎥
