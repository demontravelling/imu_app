#ifndef WIDGET_H
#define WIDGET_H
#include <iostream>

#include <QWidget>
#include <QTimer>

#include <ros/ros.h>
#include <tf/tf.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Int8.h>
#include "clear_imu.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
//---------------------ros---------------------
    std::shared_ptr<ros::NodeHandle> ptr_nh_;
    ros::Subscriber imu_sub_;
    ros::Publisher imu_clear_pub_;
    ros::ServiceClient imu_clear_client;
//---------------------callback-------------------
    friend void IMUCB(const sensor_msgs::Imu & msg);
private slots:
    void on_pushButton_clicked();
    void time_up();

private:
    Ui::Widget *ui;
    QTimer timer;
};

#endif // WIDGET_H
