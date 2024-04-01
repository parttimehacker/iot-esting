# iot-testbed
A collection of test application to evaluate sensors and other computers. 
## Description: 
This is my latest **Internet of Things** project that contains test or demonstration applications for C/C++ applications. My home automation system contains environment sensors, motion sensors, LED clocks, light switches, emergency sirens, a django web server, interfaces to Adafruit.io and a mosquitto MQTT broker

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![PyPI - Python Version](https://img.shields.io/pypi/pyversions/Django)
![Development](https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Screenshots](#screenshots)
* [Architecture](#architecture)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)
## General Information
- *Provide general information about your project here.*
  - This is a collection of IOT test or demonstrations need for my **DIYHA** projects. I've used OOP, MVC, and MTV concepts in my DIYHA system.
- *What problem does it (intend to) solve?*
  - Each IOT project can be used as a template for further work.
- *What is the purpose of your project?*
  - Evaluate sensors like the BME680, photo resistors, OLED displays, interfacing with I2C and more related to IOT.
- *Why did you undertake it?*
  - This was a fun project to learn about python, Raspberry Pi, Arduino processors, hardware and more.
<!-- You don't have to answer all the questions - just the ones relevant to your project. -->
## Technologies Used
- Arduino IDE version 2
- A variety of hardware and supporting software libraries
## Features
List the ready features here:
- BME680 
- Reports on status and diagnostic information for the host raspberry pi server.
- Code passes pylint with a score of 10.0
## Screenshots
Not applicable.
<!-- ![Example screenshot](./diyhadiagram.png)-->
<!-- If you have screenshots you'd like to share, include them here. -->
## Architecture
Each test application has it own unique architecture. Many of the C/C++ application follow the normal setup() and loop() design common to Arduino applications.
<!-- 
![Example screenshot](./diyhadiagram.png)
<!-- If you have screenshots you'd like to share, include them here. -->
## Setup
Clone the repository, followed by installation of the dependencies. The last step is to decide on automation.
### Clone the repository 
```
git clone [https://github.com/parttimehacker/diyha3-asset.git](https://github.com/parttimehacker/iot-testbed.git)
cd diyha3-asset
```
### Install dependencies
TBD
## Usage
TBD
## Implementation Status
![Status](https://progress-bar.dev/80/?title=progress)
## Room for Improvement
Include areas you believe need improvement / could be improved. Also add TODOs for future development.

Room for improvement:
- Further refactoring to more generalize the class

To do:
- Integrate into other DIYHA applications and repositories
- Develop a new installation process for seperate repositories
## Acknowledgements
Give credit here.
- My "do it yourself home automation" system leverages the work from the Eclipse IOT Paho project. https://www.eclipse.org/paho/
- Many thanks to...
- Adafruit supplies most of my hardware. http://www.adafruit.com
- I use the PyCharm development environment https://www.jetbrains.com/pycharm/
## Contact
Created by [@parttimehacker](http://parttimehacker.io/) - feel free to contact me!
### Repository Stats
![Your Repository’s Stats](https://github-readme-stats.vercel.app/api?username=parttimehacker&show_icons=true)
### Repository Languages
![Your Repository's Stats](https://github-readme-stats.vercel.app/api/top-langs/?username=parttimehacker&theme=blue-green)
### HITS
![Hits](https://hitcounter.pythonanywhere.com/count/tag.svg?url=https://github.com/parttimehacker)
<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
