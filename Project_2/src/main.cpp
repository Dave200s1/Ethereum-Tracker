#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Define SPI pins
#define TFT_CS   5   // Chip Select
#define TFT_DC   02  // Data/Command
#define TFT_RST  04  // Reset 

// TFT Initialisieren hardware SPI
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// WLAN Einstellungen
const char* ssid = "Wokwi-GUEST";
const char* password = "";


// API URL fuer Ethereum preis
const String apiUrl = "https://api.coingecko.com/api/v3/simple/price?ids=ethereum&vs_currencies=usd"; //USD



// Ethereum logo in ASCII
const char* ethLogo[] = {
  "    /\\    ",
  "   /  \\   ",
  "  /    \\  ",
  " /      \\ ",
  "/        \\",
  "|   /\\   |",
  "|  /  \\  |",
  "| /    \\ |",
  "|/      \\|",
  "|\\      /|",
  "| \\    / |",
  "|  \\  /  |",
  "|   \\/   |",
  "\\        /",
  " \\      / ",
  "  \\    /  ",
  "   \\  /   ",
  "    \\/    "
};

void displayLogoAndText();

void setup() {
  // Display initialisieren
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  // Texteinstellungen für den WiFi-Verbindungsstatus
  tft.setTextSize(2);
  tft.setCursor(10, 10);

  // Connectionstring
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");


  unsigned long startTime = millis();
  bool connected = false;

  while (millis() - startTime < 20000) { // 20-second timeout
    if (WiFi.status() == WL_CONNECTED) {
      connected = true;
      break;
    }
    delay(500); // alle 0.5 Seconden pruefen
  }

  // (Display)Bereinigung und Status anzeigen lassen
  tft.fillScreen(ILI9341_BLACK);
  if (connected) {
    Serial.println("Connected!");
    tft.setTextColor(ILI9341_GREEN);
    tft.println("Connected to WiFi");
    displayLogoAndText(); //  Ethereum data
  } else {
    Serial.println("Failed!");
    tft.setTextColor(ILI9341_RED);
    tft.println("Could not connect");
  }
}

void loop() {
  // Aktualisierung des Wechselkurses in Minutentakt
  delay(60000);
  displayLogoAndText();
}

void displayLogoAndText() {
  
  // bereinigen
  tft.fillScreen(ILI9341_BLACK);

  // welcome text anzeigen
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Welcome to the");
  tft.println("Ethereum Tracker");

  // Display Ethereum logo
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  for (int i = 0; i < 18; i++) {
    tft.setCursor(180, 40 + i * 8); // Adjusted position
    tft.println(ethLogo[i]);
  }

  // Abrufen und Anzeigen des Wechselkurses
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(apiUrl);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      // JSON Response ( Ethereum price)
      int start = payload.indexOf("\"usd\":") + 6;
      int end = payload.indexOf("}", start);
      String ethPrice = payload.substring(start, end);

      // Wechselkurses unterhalb des Logos positionieren
      tft.setTextColor(ILI9341_ORANGE);
      tft.setTextSize(2);
      tft.setCursor(10, 160); // Position einstellen
      tft.print("ETH/USD: ");
      tft.println(ethPrice);
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

}



