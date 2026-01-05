#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      tempSensor("Temperature"),
      pressureSensor("Pressure"),
      tempAlarm(90.0, 120.0),
      pressureAlarm(50.0, 80.0),
      running(false)
{
    srand(time(0));

    QWidget* central = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    // --- Dashboard layout ---
    QHBoxLayout* dashboardLayout = new QHBoxLayout();

    // --- Temperature Gauge ---
    QVBoxLayout* tempLayout = new QVBoxLayout();
    tempGauge = new QDial();
    tempGauge->setRange(0, 150);
    tempGauge->setNotchesVisible(true);
    tempLCD = new QLCDNumber();
    tempLCD->setDigitCount(5);
    tempBar = new QProgressBar();
    tempBar->setRange(0, 150);
    tempStateLabel = new QLabel("Temp State: NORMAL");

    tempLayout->addWidget(new QLabel("Temperature"));
    tempLayout->addWidget(tempGauge);
    tempLayout->addWidget(tempLCD);
    tempLayout->addWidget(tempBar);
    tempLayout->addWidget(tempStateLabel);

    // --- Pressure Gauge ---
    QVBoxLayout* pressureLayout = new QVBoxLayout();
    pressureGauge = new QDial();
    pressureGauge->setRange(0, 100);
    pressureGauge->setNotchesVisible(true);
    pressureLCD = new QLCDNumber();
    pressureLCD->setDigitCount(5);
    pressureBar = new QProgressBar();
    pressureBar->setRange(0, 100);
    pressureStateLabel = new QLabel("Pressure State: NORMAL");

    pressureLayout->addWidget(new QLabel("Pressure"));
    pressureLayout->addWidget(pressureGauge);
    pressureLayout->addWidget(pressureLCD);
    pressureLayout->addWidget(pressureBar);
    pressureLayout->addWidget(pressureStateLabel);

    dashboardLayout->addLayout(tempLayout);
    dashboardLayout->addLayout(pressureLayout);

    mainLayout->addLayout(dashboardLayout);

    // --- Buttons ---
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    startButton = new QPushButton("Start");
    stopButton = new QPushButton("Stop");
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(stopButton);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(central);
    setWindowTitle("Industrial Dashboard Simulator");

    // --- Timer ---
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUI);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopSimulation);
}

void MainWindow::startSimulation() {
    running = true;
    timer->start();
}

void MainWindow::stopSimulation() {
    running = false;
    timer->stop();
}

void MainWindow::updateGaugeColor(QLabel* label, SystemState state) {
    QString color;
    switch(state) {
        case SystemState::NORMAL: color = "green"; break;
        case SystemState::WARNING: color = "orange"; break;
        case SystemState::ERROR: color = "red"; break;
    }
    label->setStyleSheet("QLabel { color : " + color + "; font-weight: bold; font-size: 14px; }");
}

void MainWindow::updateUI() {
    if (!running) return;

    // --- Simuler capteurs ---
    double tempValue = 50 + rand() % 100;
    double pressureValue = 20 + rand() % 80;

    tempSensor.setValue(tempValue);
    pressureSensor.setValue(pressureValue);

    // --- Check états ---
    SystemState tempState = tempAlarm.checkSensor(tempSensor);
    SystemState pressureState = pressureAlarm.checkSensor(pressureSensor);

    // --- Update gauges ---
    tempGauge->setValue(static_cast<int>(tempValue));
    tempLCD->display(tempValue);
    tempBar->setValue(static_cast<int>(tempValue));
    tempStateLabel->setText("Temp State: " + QString::fromStdString(tempAlarm.stateToString(tempState)));
    updateGaugeColor(tempStateLabel, tempState);

    pressureGauge->setValue(static_cast<int>(pressureValue));
    pressureLCD->display(pressureValue);
    pressureBar->setValue(static_cast<int>(pressureValue));
    pressureStateLabel->setText("Pressure State: " + QString::fromStdString(pressureAlarm.stateToString(pressureState)));
    updateGaugeColor(pressureStateLabel, pressureState);
}
