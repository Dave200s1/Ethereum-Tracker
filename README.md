![Alt text](ethereum.png "Optional title")

# Ethereum-Tracker 

![PlatformIO](https://img.shields.io/badge/PlatformIO-00B4CC?style=for-the-badge&logo=PlatformIO&logoColor=white)
![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Wokwi](https://img.shields.io/badge/Wokwi-7A3EAB?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAABHNCSVQICAgIfAhkiAAAAX5JREFUOI2Nk79KA0EQxr9Z7y5qYxQkFhaCvY1PIMQqT2B5b2BjJ4gvYGEniE8QwVJsbKxEwUJQ0NgkcDZ3u3sW3mU3l3gX+MDMfDPf/DuRnYX3HlJK5HmOoigQY0SapsiyDFJKOOegtQYRYbfbQSmFsiyhlEJd1wCA4XAIYwystWia5h8wxqCqKmRZhq7r4JxD0zSo6xrD4RBt20IIAe89AEBKiRACQghwzkEpBQBIkgT7/R5xPp8jxojZbIb1eo0QAmKMmE6nWC6XqKoK0+kUy+US3nvEGD+BiAhEhLZtMZlMsNvtQERwzoGIQEQ4HA4Yj8c4Ho8gInjvQURfABGBc47r9YrxeIzL5fIDEBFu1yvGoxGu1yuICM65H8AYAxHh8XhgNBrh+Xz+ABHh+XxiOBzieb+DiGCM+QastVBK4X6/YzAY4PV6fQOv1wuDwQD3+x1KayilvgHvPbquw2QywWaz+QY2mw2m0ym6roP3/j9ARFBK4XQ6YT6f43Q6gYiglPqp/wX+AG0XH3qmo73EAAAAAElFTkSuQmCC&logoColor=white)

![npm bundle size (version)](https://img.shields.io/badge/version-0.0.1-darkblue)  ![npm bundle size (version)](https://img.shields.io/badge/language-c++-red)  ![npm bundle size (version)](https://img.shields.io/badge/framework-arduino-lightblue) 
## Overview
This repository contains an Ethereum Tracker project designed to display real-time Ethereum (ETH) prices in USD ($) on a 2.8" TFT display using an ESP32 development board. The project fetches live Ethereum price data from the CoinGecko API and showcases it alongside an ASCII art representation of the Ethereum logo. It is configured using the PlatformIO IDE and utilizes the Arduino framework.

**Important Note:** 
When connecting to WiFi keep in mind that this project utilizes the Wokwi environment , if you implement this on a bare-metal machine, use your own ssid and password. Furthermore
if you want to display other currencies feel free to do so, CoinGecko supports various currencies.

## Used Technologie

- Basic ESP32 configuration with PlatformIO
- Arduino framework 
- SPI Protocol
- Full color 240x320 2.8" LCD-TFT display 

![Alt text](Ethereum_Tracker.png "Optional title")

## Prerequisites

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO IDE](https://platformio.org/install/ide?install=vscode)
- ESP32 development board
- Wokwi License (community)
- Basic knowledge of C++ programming
- 
## Icons
  * https://www.flaticon.com/free-icon/coin_15208017?term=ethereum&page=1&position=15&origin=search&related_id=15208017
