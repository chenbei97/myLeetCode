#ifndef SPICOMMAND_H
#define SPICOMMAND_H
#include <QString>
#include <QMap>
namespace SPIC {
  typedef enum class spiCommand
  {
    // SOURce子系统
    SOUR_FUNC_GET, // 查询和设定电源工作模式
    SOUR_FUNC_SET_VOLT,
    SOUR_FUNC_SET_CURR,

    SOUR_FUNC_MODE_GET,//查询和设定电源功能模式
    SOUR_FUNC_MODE_SET_FIX,
    SOUR_FUNC_MODE_SET_LIST,
    SOUR_FUNC_MODE_SET_BATT,
    SOUR_FUNC_MODE_SET_SOL,
    SOUR_FUNC_MODE_SET_CARP,

    // 优先CC模式输出电流当前值、最小、最大和默认值查询和设置
    SOUR_CURR_GET_VAL,    SOUR_CURR_SET_VAL,// CV模式命令失效
    SOUR_CURR_GET_MIN,    SOUR_CURR_SET_MIN,
    SOUR_CURR_GET_MAX,   SOUR_CURR_SET_MAX,
    SOUR_CURR_GET_DEF,    SOUR_CURR_SET_DEF,
    SOUR_CURR_GET_LIM_POS,    SOUR_CURR_SET_LIM_POS, // CV模式改用此命令,读取和设置电流的PS值
    SOUR_CURR_GET_LIM_NEG,    SOUR_CURR_SET_LIM_NEG,// CV模式改用此命令,读取和设置电流的EL值


    // 优先CV模式输出电压当前值、最小、最大和默认值查询和设置
    SOUR_VOLT_GET_VAL,    SOUR_VOLT_SET_VAL,// CC模式命令失效
    SOUR_VOLT_GET_MIN,    SOUR_VOLT_SET_MIN,
    SOUR_VOLT_GET_MAX,    SOUR_VOLT_SET_MAX,
    SOUR_VOLT_GET_DEF,    SOUR_VOLT_SET_DEF,

    SOUR_VOLT_GET_LIM_POS,SOUR_VOLT_SET_LIM_POS,// CC模式改用此命令,读取和设置电压的PS值
    SOUR_VOLT_GET_LIM_NEG,SOUR_VOLT_SET_LIM_NEG,// CC模式改用此命令,读取和设置电压的EL值


    // 优先CP模式输出功率当前值、上限和下限值查询和设置
    SOUR_POW_GET_VAL,    SOUR_POW_SET_VAL,  // CC/CV模式下失效
    SOUR_POW_GET_MIN,    SOUR_POW_SET_MIN,
    SOUR_POW_GET_MAX,    SOUR_POW_SET_MAX,

    SOUR_POW_GET_LIM_POS,SOUR_POW_SET_LIM_POS, // CC/CV模式改用此命令,读取和设置功率的PS值
    SOUR_POW_GET_LIM_NEG,SOUR_POW_SET_LIM_NEG,// CC/CV模式改用此命令,读取和设置功率的EL值


    // 优先CR模式电源内阻当前值、最小、最大和默认值查询和设置
    SOUR_RES_GET_VAL,    SOUR_RES_SET_VAL,
    SOUR_RES_GET_MIN,    SOUR_RES_SET_MIN,
    SOUR_RES_GET_MAX,    SOUR_RES_SET_MAX,
    SOUR_RES_GET_DEF,    SOUR_RES_SET_DEF,


    // MEASure子系统
    // 查询电压、电流、功率当前测量平均值以及内阻测量值
    MEAS_VOLT_AVAE,
    MEAS_CURR_AVAE,
    MEAS_POW_AVAE,
    MEAS_RES_AVAE,
  } spiCE;

  static QMap<spiCommand, QString> SPICS = {
    // SOURce子系统
    {spiCE::SOUR_FUNC_GET,"SOUR:FUNC?"}, // 电源工作模式查询和设置
    {spiCE::SOUR_FUNC_SET_VOLT,"SOUR:FUNC VOLT"},
    {spiCE::SOUR_FUNC_SET_CURR,"SOUR:FUNC CURR"},

    {spiCE::SOUR_FUNC_MODE_GET,"SOUR:FUNC:MODE?"},// 电源功能模式查询和设置
    {spiCE::SOUR_FUNC_MODE_SET_FIX,"SOUR:FUNC:MODE FIX"},
    {spiCE::SOUR_FUNC_MODE_SET_LIST,"SOUR:FUNC:MODE LIST"},
    {spiCE::SOUR_FUNC_MODE_SET_BATT,"SOUR:FUNC:MODE BATT"},
    {spiCE::SOUR_FUNC_MODE_SET_SOL,"SOUR:FUNC:MODE SOL"},
    {spiCE::SOUR_FUNC_MODE_SET_CARP,"SOUR:FUNC:MODE CARP"},

    // 优先CC模式输出电流当前值、最小、最大和默认值查询和设置
    {spiCE::SOUR_CURR_GET_VAL,"SOUR:CURR?"},    {spiCE::SOUR_CURR_SET_VAL,"SOUR:CURR "},// CV模式命令失效
    {spiCE::SOUR_CURR_GET_LIM_POS,"SOUR:CURR:LIM:POS?"},    {spiCE::SOUR_CURR_SET_LIM_POS,"SOUR:CURR:LIM:POS "},// CV模式改用此命令,读取和设置电流的PS值
    {spiCE::SOUR_CURR_GET_LIM_NEG,"SOUR:CURR:LIM:NEG?"},    {spiCE::SOUR_CURR_SET_LIM_NEG,"SOUR:CURR:LIM:NEG "},// CV模式改用此命令,读取和设置电流的EL值
    {spiCE::SOUR_CURR_GET_MIN,"SOUR:CURR? MIN"},    {spiCE::SOUR_CURR_SET_MIN,"SOUR:CURR MIN"},
    {spiCE::SOUR_CURR_GET_MAX,"SOUR:CURR? MAX"},    {spiCE::SOUR_CURR_SET_MAX,"SOUR:CURR MAX"},
    {spiCE::SOUR_CURR_GET_DEF,"SOUR:CURR? DEF"},    {spiCE::SOUR_CURR_SET_DEF,"SOUR:CURR DEF"},


    // 优先CV模式输出电压当前值、最小、最大和默认值查询和设置
    {spiCE::SOUR_VOLT_GET_VAL,"SOUR:VOLT?"},    {spiCE::SOUR_VOLT_SET_VAL,"SOUR:VOLT "},// CC模式命令失效
    {spiCE::SOUR_VOLT_GET_LIM_POS,"SOUR:VOLT:LIM:POS?"},    {spiCE::SOUR_VOLT_SET_LIM_POS,"SOUR:VOLT:LIM:POS "},// CC模式改用此命令,读取和设置电压的PS值
    {spiCE::SOUR_VOLT_GET_LIM_NEG,"SOUR:VOLT:LIM:NEG?"},    {spiCE::SOUR_VOLT_SET_LIM_NEG,"SOUR:VOLT:LIM:NEG "},// CC模式改用此命令,读取和设置电压的PS值
    {spiCE::SOUR_VOLT_GET_MIN,"SOUR:VOLT? MIN"},    {spiCE::SOUR_VOLT_SET_MIN,"SOUR:VOLT MIN"},
    {spiCE::SOUR_VOLT_GET_MAX,"SOUR:VOLT? MAX"},    {spiCE::SOUR_VOLT_SET_MAX,"SOUR:VOLT MAX"},
    {spiCE::SOUR_VOLT_GET_DEF,"SOUR:VOLT? DEF"},    {spiCE::SOUR_VOLT_SET_DEF,"SOUR:VOLT DEF"},


    // 优先CP模式输出功率当前值、上限和下限值查询和设置
    {spiCE::SOUR_POW_GET_VAL,"SOUR:POW?"},    {spiCE::SOUR_POW_SET_VAL,"SOUR:POW "},
    {spiCE::SOUR_POW_GET_MIN,"SOUR:POW:LIM? MIN"},    {spiCE::SOUR_POW_SET_MIN,"SOUR:POW:LIM MIN"},
    {spiCE::SOUR_POW_GET_MAX,"SOUR:POW:LIM? MAX"},    {spiCE::SOUR_POW_SET_MAX,"SOUR:POW:LIM MAX"},
    {spiCE::SOUR_POW_GET_LIM_POS,"SOUR:POW:LIM:POS?"},    {spiCE::SOUR_POW_SET_LIM_POS,"SOUR:POW:LIM:POS "},  // CC/CV模式改用此命令,读取和设置功率的PS值
    {spiCE::SOUR_POW_GET_LIM_NEG,"SOUR:POW:LIM:NEG?"},    {spiCE::SOUR_POW_SET_LIM_NEG,"SOUR:POW:LIM:NEG "}, // CC/CV模式改用此命令,读取和设置功率的EL值


    // 优先CR模式电源内阻当前值、最小、最大和默认值查询和设置
    {spiCE::SOUR_RES_GET_VAL,"SOUR:RES?"},    {spiCE::SOUR_RES_SET_VAL,"SOUR:RES "},
    {spiCE::SOUR_RES_GET_MIN,"SOUR:RES? MIN"},    {spiCE::SOUR_RES_SET_MIN,"SOUR:RES MIN"},
    {spiCE::SOUR_RES_GET_MAX,"SOUR:RES? MAX"},    {spiCE::SOUR_RES_SET_MAX,"SOUR:RES MAX"},
    {spiCE::SOUR_RES_GET_DEF,"SOUR:RES? DEF"},    {spiCE::SOUR_RES_SET_DEF,"SOUR:RES DEF"},


    // MEASure子系统
    // 查询电压、电流、功率当前测量平均值以及内阻测量值
    {spiCE::MEAS_VOLT_AVAE,"MEAS:VOLT?"},
    {spiCE::MEAS_CURR_AVAE,"MEAS:CURR?"},
    {spiCE::MEAS_POW_AVAE,"MEAS:POW?"},
    {spiCE::MEAS_RES_AVAE,"MEAS:RES?"}
  };
  static const QString& spic(const spiCE& spic)
  {
    return SPICS[spic];
  }
} // END NAMESPACE SPIC
#endif // SPICOMMAND_H
