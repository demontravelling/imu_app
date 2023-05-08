#include "widget.h"
#include "ui_widget.h"
double angle;
double speed;

void  IMUCB(const sensor_msgs::Imu & msg )
{
//    std::cout << "yaw角度:   " << tf::getYaw(msg.orientation) / 3.14159 * 180 << std::endl;
//    std::cout << "yaw角速度: "<< msg.angular_velocity.z << std::endl;

    angle = tf::getYaw(msg.orientation) / 3.14159 * 180;
    speed = msg.angular_velocity.z;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ptr_nh_ = std::make_shared<ros::NodeHandle>();
    this->imu_sub_ = ptr_nh_->subscribe("/imu_mplus",1000,IMUCB);

    imu_clear_pub_ = ptr_nh_->advertise<std_msgs::Int8>("/set_imu_clear", 1000);


    imu_clear_client = ptr_nh_->serviceClient<odom_module::clear_imu>("/imu_clear_serv");

    static ros::AsyncSpinner spinner(1);
    spinner.start();

    connect(&timer,SIGNAL(timeout()),this,SLOT(time_up()));
    timer.start(10);

    this->setWindowTitle("IMU DATA");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
//    std_msgs::Int8 msg;
//    imu_clear_pub_.publish(msg);
    odom_module::clear_imu::Request req;
    odom_module::clear_imu::Response resp;


    ros::service::waitForService("/imu_clear_serv", ros::Duration(5.0));
    imu_clear_client.call(req,resp);
    std::cout << "清零反馈： " << (int)resp.is_success << std::endl;

}

void Widget::time_up()
{
    ui->lcd_yaw->display(angle);
    ui->lcd_yaw_speed->display(speed);
}
