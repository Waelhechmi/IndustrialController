#pragma once
#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QProgressBar>
#include <QDial>
#include <QPushButton>
#include <QTimer>
#include "../core/Sensor.hpp"
#include "core/AlarmManager.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void updateUI();
    void startSimulation();
    void stopSimulation();

private:
    // Gauges
    QDial* tempGauge;
    QProgressBar* tempBar;
    QLCDNumber* tempLCD;

    QDial* pressureGauge;
    QProgressBar* pressureBar;
    QLCDNumber* pressureLCD;

    // Voyants
    QLabel* tempStateLabel;
    QLabel* pressureStateLabel;

    // Boutons
    QPushButton* startButton;
    QPushButton* stopButton;

    QTimer* timer;

    // Logique capteurs
    Sensor tempSensor;
    Sensor pressureSensor;
    AlarmManager tempAlarm;
    AlarmManager pressureAlarm;
    bool running;

    void updateGaugeColor(QLabel* label, SystemState state);
};
