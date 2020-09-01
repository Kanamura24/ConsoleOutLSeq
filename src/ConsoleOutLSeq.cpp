// -*- C++ -*-
/*!
 * @file  ConsoleOutLSeq.cpp
 * @brief Console Out Component (TimedLongSeq)
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleOutLSeq.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consoleoutlseq_spec[] =
  {
    "implementation_id", "ConsoleOutLSeq",
    "type_name",         "ConsoleOutLSeq",
    "description",       "Console Out Component (TimedLongSeq)",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ConsoleOutLSeq::ConsoleOutLSeq(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleOutLSeq::~ConsoleOutLSeq()
{
}



RTC::ReturnCode_t ConsoleOutLSeq::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOutLSeq::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleOutLSeq::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOutLSeq::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOutLSeq::onExecute(RTC::UniqueId ec_id)
{
    if(m_inIn.isNew()) {
    m_inIn.read();
    std::cout << m_in.data.length() << " datas received." << std::endl;
    for(int i = 0;i < m_in.data.length();i++) {
      std::cout << "Data is " << m_in.data[i] << std::endl;
    }
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOutLSeq::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutLSeq::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleOutLSeqInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleoutlseq_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleOutLSeq>,
                             RTC::Delete<ConsoleOutLSeq>);
  }
  
};


