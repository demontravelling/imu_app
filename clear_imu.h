// Generated by gencpp from file odom_module/clear_imu.msg
// DO NOT EDIT!


#ifndef ODOM_MODULE_MESSAGE_CLEAR_IMU_H
#define ODOM_MODULE_MESSAGE_CLEAR_IMU_H

#include <ros/service_traits.h>


#include <odom_module/clear_imuRequest.h>
#include <odom_module/clear_imuResponse.h>


namespace odom_module
{

struct clear_imu
{

typedef clear_imuRequest Request;
typedef clear_imuResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct clear_imu
} // namespace odom_module


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::odom_module::clear_imu > {
  static const char* value()
  {
    return "cb827c3bb8c63dd8876ad66cc7f94518";
  }

  static const char* value(const ::odom_module::clear_imu&) { return value(); }
};

template<>
struct DataType< ::odom_module::clear_imu > {
  static const char* value()
  {
    return "odom_module/clear_imu";
  }

  static const char* value(const ::odom_module::clear_imu&) { return value(); }
};


// service_traits::MD5Sum< ::odom_module::clear_imuRequest> should match
// service_traits::MD5Sum< ::odom_module::clear_imu >
template<>
struct MD5Sum< ::odom_module::clear_imuRequest>
{
  static const char* value()
  {
    return MD5Sum< ::odom_module::clear_imu >::value();
  }
  static const char* value(const ::odom_module::clear_imuRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::odom_module::clear_imuRequest> should match
// service_traits::DataType< ::odom_module::clear_imu >
template<>
struct DataType< ::odom_module::clear_imuRequest>
{
  static const char* value()
  {
    return DataType< ::odom_module::clear_imu >::value();
  }
  static const char* value(const ::odom_module::clear_imuRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::odom_module::clear_imuResponse> should match
// service_traits::MD5Sum< ::odom_module::clear_imu >
template<>
struct MD5Sum< ::odom_module::clear_imuResponse>
{
  static const char* value()
  {
    return MD5Sum< ::odom_module::clear_imu >::value();
  }
  static const char* value(const ::odom_module::clear_imuResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::odom_module::clear_imuResponse> should match
// service_traits::DataType< ::odom_module::clear_imu >
template<>
struct DataType< ::odom_module::clear_imuResponse>
{
  static const char* value()
  {
    return DataType< ::odom_module::clear_imu >::value();
  }
  static const char* value(const ::odom_module::clear_imuResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ODOM_MODULE_MESSAGE_CLEAR_IMU_H