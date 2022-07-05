#ifndef SPICOMMAND_H
#define SPICOMMAND_H
#include <QString>
#include <QMap>
namespace SPIC {
  typedef enum class spiStatus{

    CV_WORK_MODE, // CV和CC工作模式
    CC_WORK_MODE,

    CV_WORK_STATUS, // 工作状态分为CC+,CC-,CP+,CP-和CV
    CC_POS_WORK_STATUS,
    CC_NEG_WORK_STATUS,
    CP_POS_WORK_STATUS,
    CP_NEG_WORK_STATUS,

    ON, // 电源开关状态
    OFF,

    BINARY, // 串口数据处理形式
    HEX,
    ASCII,

    ACCEPTED, // 串口数据成功收到
    FAILED, // 没有收到
    REPEAT, // 重发
  } STATUS;
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

    // 其它枚举值
    // 1)工作模式
    GET_WORK_MODE,//cv和cc
    SET_CV_WORK_MODE,
    SET_CC_WORK_MODE,
    // 2) 工作状态
    GET_WORK_STATUS,// cv,cc+,cc-,cp+,cp-,off/on工作状态
    /*
       仪器状态返回值为在寄存器中所有已启用位的二进制加权值的总和,如101000返回8+32=40
      返回值每个位的含义如下
       位 名称           含义
        0 ACQ-WTG 已触发(指示meter的触发状态)
        1 ARB-WTG 已触发(指示arb的触发状态)
        2 DLOG-WTG 已触发(指示dlog的发状态)
        3 ACQ-Active ACQ已经触发，正在执行
        4 ARB-Active ARB已经触发，正在执行
        5 DLOG-Active DLOG已经触发，正在执行
        6 OFF 仪器on/off为off状态
        7 CC 正向恒流状态
        8 CV  恒压状态
        9 CW 正向恒功率状态
        11 CC- 负向恒流状态
        12 CP- 负向恒功率状态
    */
  } COMMAND;

  static QMap<spiCommand, QString> SPICS = {
    // SOURce子系统
    {COMMAND::SOUR_FUNC_GET,"SOUR:FUNC?"}, // 电源工作模式查询和设置
    {COMMAND::SOUR_FUNC_SET_VOLT,"SOUR:FUNC VOLT"},
    {COMMAND::SOUR_FUNC_SET_CURR,"SOUR:FUNC CURR"},

    {COMMAND::SOUR_FUNC_MODE_GET,"SOUR:FUNC:MODE?"},// 电源功能模式查询和设置
    {COMMAND::SOUR_FUNC_MODE_SET_FIX,"SOUR:FUNC:MODE FIX"},
    {COMMAND::SOUR_FUNC_MODE_SET_LIST,"SOUR:FUNC:MODE LIST"},
    {COMMAND::SOUR_FUNC_MODE_SET_BATT,"SOUR:FUNC:MODE BATT"},
    {COMMAND::SOUR_FUNC_MODE_SET_SOL,"SOUR:FUNC:MODE SOL"},
    {COMMAND::SOUR_FUNC_MODE_SET_CARP,"SOUR:FUNC:MODE CARP"},

    // 优先CC模式输出电流当前值、最小、最大和默认值查询和设置
    {COMMAND::SOUR_CURR_GET_VAL,"SOUR:CURR?"},    {COMMAND::SOUR_CURR_SET_VAL,"SOUR:CURR "},// CV模式命令失效
    {COMMAND::SOUR_CURR_GET_LIM_POS,"SOUR:CURR:LIM:POS?"},    {COMMAND::SOUR_CURR_SET_LIM_POS,"SOUR:CURR:LIM:POS "},// CV模式改用此命令,读取和设置电流的PS值
    {COMMAND::SOUR_CURR_GET_LIM_NEG,"SOUR:CURR:LIM:NEG?"},    {COMMAND::SOUR_CURR_SET_LIM_NEG,"SOUR:CURR:LIM:NEG "},// CV模式改用此命令,读取和设置电流的EL值
    {COMMAND::SOUR_CURR_GET_MIN,"SOUR:CURR? MIN"},    {COMMAND::SOUR_CURR_SET_MIN,"SOUR:CURR MIN"},
    {COMMAND::SOUR_CURR_GET_MAX,"SOUR:CURR? MAX"},    {COMMAND::SOUR_CURR_SET_MAX,"SOUR:CURR MAX"},
    {COMMAND::SOUR_CURR_GET_DEF,"SOUR:CURR? DEF"},    {COMMAND::SOUR_CURR_SET_DEF,"SOUR:CURR DEF"},


    // 优先CV模式输出电压当前值、最小、最大和默认值查询和设置
    {COMMAND::SOUR_VOLT_GET_VAL,"SOUR:VOLT?"},    {COMMAND::SOUR_VOLT_SET_VAL,"SOUR:VOLT "},// CC模式命令失效
    {COMMAND::SOUR_VOLT_GET_LIM_POS,"SOUR:VOLT:LIM:POS?"},    {COMMAND::SOUR_VOLT_SET_LIM_POS,"SOUR:VOLT:LIM:POS "},// CC模式改用此命令,读取和设置电压的PS值
    {COMMAND::SOUR_VOLT_GET_LIM_NEG,"SOUR:VOLT:LIM:NEG?"},    {COMMAND::SOUR_VOLT_SET_LIM_NEG,"SOUR:VOLT:LIM:NEG "},// CC模式改用此命令,读取和设置电压的PS值
    {COMMAND::SOUR_VOLT_GET_MIN,"SOUR:VOLT? MIN"},    {COMMAND::SOUR_VOLT_SET_MIN,"SOUR:VOLT MIN"},
    {COMMAND::SOUR_VOLT_GET_MAX,"SOUR:VOLT? MAX"},    {COMMAND::SOUR_VOLT_SET_MAX,"SOUR:VOLT MAX"},
    {COMMAND::SOUR_VOLT_GET_DEF,"SOUR:VOLT? DEF"},    {COMMAND::SOUR_VOLT_SET_DEF,"SOUR:VOLT DEF"},


    // 优先CP模式输出功率当前值、上限和下限值查询和设置
    {COMMAND::SOUR_POW_GET_VAL,"SOUR:POW?"},    {COMMAND::SOUR_POW_SET_VAL,"SOUR:POW "},
    {COMMAND::SOUR_POW_GET_MIN,"SOUR:POW:LIM? MIN"},    {COMMAND::SOUR_POW_SET_MIN,"SOUR:POW:LIM MIN"},
    {COMMAND::SOUR_POW_GET_MAX,"SOUR:POW:LIM? MAX"},    {COMMAND::SOUR_POW_SET_MAX,"SOUR:POW:LIM MAX"},
    {COMMAND::SOUR_POW_GET_LIM_POS,"SOUR:POW:LIM:POS?"},    {COMMAND::SOUR_POW_SET_LIM_POS,"SOUR:POW:LIM:POS "},  // CC/CV模式改用此命令,读取和设置功率的PS值
    {COMMAND::SOUR_POW_GET_LIM_NEG,"SOUR:POW:LIM:NEG?"},    {COMMAND::SOUR_POW_SET_LIM_NEG,"SOUR:POW:LIM:NEG "}, // CC/CV模式改用此命令,读取和设置功率的EL值


    // 优先CR模式电源内阻当前值、最小、最大和默认值查询和设置
    {COMMAND::SOUR_RES_GET_VAL,"SOUR:RES?"},    {COMMAND::SOUR_RES_SET_VAL,"SOUR:RES "},
    {COMMAND::SOUR_RES_GET_MIN,"SOUR:RES? MIN"},    {COMMAND::SOUR_RES_SET_MIN,"SOUR:RES MIN"},
    {COMMAND::SOUR_RES_GET_MAX,"SOUR:RES? MAX"},    {COMMAND::SOUR_RES_SET_MAX,"SOUR:RES MAX"},
    {COMMAND::SOUR_RES_GET_DEF,"SOUR:RES? DEF"},    {COMMAND::SOUR_RES_SET_DEF,"SOUR:RES DEF"},

    // MEASure子系统
    // 查询电压、电流、功率当前测量平均值以及内阻测量值
    {COMMAND::MEAS_VOLT_AVAE,"MEAS:VOLT?"},
    {COMMAND::MEAS_CURR_AVAE,"MEAS:CURR?"},
    {COMMAND::MEAS_POW_AVAE,"MEAS:POW?"},
    {COMMAND::MEAS_RES_AVAE,"MEAS:RES?"},

    // 其它枚举值
    // 处于CC还是CV模式,
    {COMMAND::GET_WORK_MODE,"SOUR:FUNC?"}, // 等价于SOUR_FUNC_GET
    {COMMAND::SET_CV_WORK_MODE,"SOUR:FUNC: VOLT"}, // <=> SOUR_FUNC_SET_VOLT
    {COMMAND::SET_CC_WORK_MODE,"SOUR:FUNC: CURR"},// <=> SOUR_FUNC_SET_CURR
    {COMMAND::GET_WORK_STATUS,"STAT:OPERA?"},  // 例如101000,会返回8+32=40
  };
  static const QString& spic(const COMMAND& spi)
  {
    return SPICS[spi];
  }
} // END NAMESPACE SPIC
#endif // SPICOMMAND_H
