#include <QApplication>
#include "gui/MainWindow.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
