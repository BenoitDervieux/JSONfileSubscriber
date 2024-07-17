# JSONfileSubscriber

## Overview

JSONfileSubscriber is a project designed for ESP32 microcontrollers utilizing SPIFFS, aimed at facilitating dynamic configuration updates through a web interface. The project employs a subscriber pattern to propagate changes from a JSON configuration file to a system, specifically designed for integration with Lesklights.com.

## Project Goals

The primary objective of this project is to enable real-time modification of system settings via a web server hosted on ESP32. Users can interact with the system using HTTP GET or POST methods, primarily adjusting parameters like effect name, brightness, and speed during testing phases.

Changes made through the web interface are persistently recorded in a `config.json` file. This file serves as a centralized repository, maintaining the latest application state for future reference.

## System Architecture

### Web Interface (Webserver)

The ESP32 hosts a web interface that allows users to modify system settings. This interface serves as the entry point for sending configuration updates.

### Configuration Handling

Changes initiated via the web interface are captured and stored in the `config.json` file on SPIFFS. This file acts as a snapshot of the application's current state, ensuring that settings adjustments are retained across power cycles and reboots.

### Subscriber Pattern

The system implements a subscriber pattern where components, representing LED stripes in this context, subscribe to updates from the `config.json` file. This pattern ensures that changes in system settings are promptly reflected in the operation of physical LED strips.

## Considerations

One consideration in the project is determining the optimal timing for writing changes to the `config.json` file. This decision hinges on whether to write changes immediately upon user interaction or defer updates until the program is stopped or restarted. The project will explore both approaches to determine the most robust solution for handling abrupt program interruptions.

