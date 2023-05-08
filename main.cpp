#include "widget.h"
#include <QApplication>
Widget*w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ros::init(argc, argv, "imu_app");
    w = new Widget();
    w->show();

    return a.exec();
}
