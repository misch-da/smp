#include <QApplication>

#include <ui/mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto window = std::make_shared<MainWindow>();
    window->show();

    return a.exec();
}