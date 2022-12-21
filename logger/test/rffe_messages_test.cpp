#include "../rffe_messages/include/m_async.h"
#include "../rffe_messages/include/m_int.h"
#include "../rffe_messages/include/m_rxtx.h"
#include "../rffe_messages/include/m_st.h"

void report(bool x, const char* test_name)
{
    printf("Testing %s: ");
    if (x) printf("\e[92mPassed\e[0m\n");
    else {
        printf("\e[91mFailed\e[0m\n");
    }
}

bool t_MsgIcdConnectionRequest()
{
    MsgIcdConnectionRequest obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdConnectionRequestReply()
{
    MsgIcdConnectionRequestReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdKeepAlive()
{
    MsgIcdKeepAlive obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdKeepAliveReply()
{
    MsgIcdKeepAliveReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdInitialConfiguration()
{
    MsgIcdInitialConfiguration obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdInitialConfigurationReply()
{
    MsgIcdInitialConfigurationReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdGetRssi()
{
    MsgIcdGetRssi obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdGetRssiReply()
{
    MsgIcdGetRssiReply obj;
    obj.set(2, 3, 4);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetLogRate()
{
    MsgIcdSetLogRate obj;
    obj.set(3, 4);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetLogRateReply()
{
    MsgIcdSetLogRateReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetTxPower()
{
    MsgIcdSetTxPower obj;
    obj.set(40, 40);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetTxPowerReply()
{
    MsgIcdSetTxPowerReply obj;
    obj.set(4, 20, 20);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetRssiThreshold()
{
    MsgIcdSetRssiThreshold obj;
    obj.set(-84, -87);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetRssiThresholdReply()
{
    MsgIcdSetRssiThresholdReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetAsu()
{
    MsgIcdSetAsu obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetAsuReply()
{
    MsgIcdSetAsuReply obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetBandwidth()
{
    MsgIcdSetBandwidth obj;
    obj.set(1, 0);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetBandwidthReply()
{
    MsgIcdSetBandwidthReply obj;
    obj.set(3);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetIfAttenuation()
{
    MsgIcdSetIfAttenuation obj;
    obj.set(40, 40, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetIfAttenuationReply()
{
    MsgIcdSetIfAttenuationReply obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetAgc()
{
    MsgIcdSetAgc obj;
    obj.set(4, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetAgcReply()
{
    MsgIcdSetAgcReply obj;
    obj.set(3, 4);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdWow()
{
    MsgIcdWow obj;
    obj.set(2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdWowReply()
{
    MsgIcdWowReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSetLcd()
{
    MsgIcdSetLcd obj;
    obj.set("ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789");
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSetLcdReply()
{
    MsgIcdSetLcdReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdGetAsu()
{
    MsgIcdGetAsu obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdGetAsuReply()
{
    MsgIcdGetAsuReply obj;
    obj.set(1, 1, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdInhibitMode()
{
    MsgIcdInhibitMode obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdInhibitModeReply()
{
    MsgIcdInhibitModeReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSyncCheck()
{
    MsgIcdSyncCheck obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSyncCheckReply()
{
    MsgIcdSyncCheckReply obj;
    obj.set(1, -1, 0);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdGetRffeSwAndIcdVersion()
{
    MsgIcdGetRffeSwAndIcdVersion obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdGetRffeSwAndIcdVersionReply()
{
    MsgIcdGetRffeSwAndIcdVersionReply obj;
    obj.set("2.4.234.2353", "24/02/2022", "23423323422234");
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdDebugTx()
{
    MsgIcdDebugTx obj;
    obj.set(1, 1, 8000, 32, 10, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdDebugTxReply()
{
    MsgIcdDebugTxReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdDebugRx()
{
    MsgIcdDebugRx obj;
    obj.set(1, 2, 0, 1, 2, 2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdDebugRxReply()
{
    MsgIcdDebugRxReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdVswrInterrupt()
{
    MsgIcdVswrInterrupt obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdTemperatureInterrupt()
{
    MsgIcdTemperatureInterrupt obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdGenericFailureInterrupt()
{
    MsgIcdGenericFailureInterrupt obj;
    obj.set(1, 2);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdRssiInterrupt()
{
    MsgIcdRssiInterrupt obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdVoltageInterrupt()
{
    MsgIcdVoltageInterrupt obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdSbit()
{
    MsgIcdSbit obj;
    obj.set(1, 2000);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSbitReply()
{
    MsgIcdSbitReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSbitHealthStatus()
{
    MsgIcdSbitHealthStatus obj;
    obj.set(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdIbit()
{
    MsgIcdIbit obj;
    obj.set(1, 8000);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdIbitReply()
{
    MsgIcdIbitReply obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdIbitHealthStatus()
{
    MsgIcdIbitHealthStatus obj;
    obj.set(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdObit()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdObitHealthStatus()
{
    MsgIcdObitHealthStatus obj;
    obj.set(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

/******Implement....*/
bool t_MsgIcdShm()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdShmReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdSha()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdShaReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

bool t_MsgIcdCftBoth()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdCftBothReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdCftUpper()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdCftUpperReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdCftLower()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdCftLowerReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdSapBoth()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSapBothReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdSapUpper()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSapUpperReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdSapLower()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdSapLowerReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdPtsBoth()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdPtsBothReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdPtsUpper()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdPtsUpperReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}


bool t_MsgIcdPtsLower()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}
bool t_MsgIcdPtsLowerReply()
{
    MsgIcdObit obj;
    obj.set(1);
    return obj.decode(obj.data.data(), obj.length) == NOERROR;
}

int main()
{
    printf("Testing Asynchonous Messages...\n");
    report(t_MsgIcdConnectionRequest(), "Connection Request");
    report(t_MsgIcdConnectionRequestReply(), "Connection Request Reply");

    report(t_MsgIcdKeepAlive(), "Keep Alive");
    report(t_MsgIcdKeepAliveReply(), "Keep Alive Reply");

    report(t_MsgIcdInitialConfiguration(), "Initial Configuration");
    report(t_MsgIcdInitialConfigurationReply(), "Initial Configuration Reply");

    report(t_MsgIcdGetRssi(), "Get RSSI");
    report(t_MsgIcdGetRssiReply(), "Get RSSI Reply");

    report(t_MsgIcdSetLogRate(), "Set Lograte");
    report(t_MsgIcdSetLogRateReply(), "Set Lograte Reply");

    report(t_MsgIcdSetTxPower(), "Set TX Power");
    report(t_MsgIcdSetTxPowerReply(), "Set TX Power Reply");

    report(t_MsgIcdSetRssiThreshold(), "Set RSSI Threshold");
    report(t_MsgIcdSetRssiThresholdReply(), "Set RSSI Threshold Reply");

    report(t_MsgIcdSetAsu(), "Set ASU");
    report(t_MsgIcdSetAsuReply(), "Set ASU Reply");

    report(t_MsgIcdSetBandwidth(), "Set Bandwidth");
    report(t_MsgIcdSetBandwidthReply(), "Set Bandwidth Reply");

    report(t_MsgIcdSetIfAttenuation(), "Set IF Attenuation");
    report(t_MsgIcdSetIfAttenuationReply(), "Set IF Attenuation Reply");

    report(t_MsgIcdSetAgc(), "Set AGC");
    report(t_MsgIcdSetAgcReply(), "Set AGC Reply");

    report(t_MsgIcdWow(), "WOW");
    report(t_MsgIcdWowReply(), "WOW Reply");

    report(t_MsgIcdSetLcd(), "Set LCD");
    report(t_MsgIcdSetLcdReply(), "Set LCD Reply");

    report(t_MsgIcdGetAsu(), "Get ASU");
    report(t_MsgIcdGetAsuReply(), "Get ASU Reply");

    report(t_MsgIcdInhibitMode(), "Inhibit Mode");
    report(t_MsgIcdInhibitModeReply(), "Inhibit Mode Reply");

    report(t_MsgIcdSyncCheck(), "Sync Check");
    report(t_MsgIcdSyncCheckReply(), "Sync Check Reply");

    report(t_MsgIcdGetRffeSwAndIcdVersion(), "Get RFFE SW & ICD Version");
    report(t_MsgIcdGetRffeSwAndIcdVersionReply(), "Get RFFE SW & ICD Version Reply");

    report(t_MsgIcdSetLcd(), "Set LCD");
    report(t_MsgIcdSetLcdReply(), "Set LCD Reply");

    report(t_MsgIcdSetLcd(), "Set LCD");
    report(t_MsgIcdSetLcdReply(), "Set LCD Reply");

    report(t_MsgIcdDebugTx(), "Debug TX");
    report(t_MsgIcdDebugTxReply(), "Debug TX Reply");

    report(t_MsgIcdDebugRx(), "Debug RX");
    report(t_MsgIcdDebugRxReply(), "Debug RX Reply");

    printf("\nTesting Interrupts Messages...\n");
    report(t_MsgIcdVswrInterrupt(), "VSWR Interrupt");
    report(t_MsgIcdTemperatureInterrupt(), "Temperature Interrupt");
    report(t_MsgIcdGenericFailureInterrupt(), "Generic Failure Interrupt");
    report(t_MsgIcdRssiInterrupt(), "RSSI Interrupt");
    report(t_MsgIcdVoltageInterrupt(), "Voltage Interrupt");

    printf("\nTesting Self-Test Messages...\n");
    report(t_MsgIcdSbit(), "Sbit");
    report(t_MsgIcdSbitReply(), "Sbit Reply");
    report(t_MsgIcdSbitHealthStatus(), "Sbit Health Status");

    report(t_MsgIcdIbit(), "Ibit");
    report(t_MsgIcdIbitReply(), "Ibit Reply");
    report(t_MsgIcdIbitHealthStatus(), "Ibit Health Status");

    report(t_MsgIcdObit(), "Obit");
    report(t_MsgIcdObitHealthStatus(), "Obit Reply");

    printf("\nTesting Transmission Messages...\n");

    report(t_MsgIcdShm(), "SHM");
    report(t_MsgIcdShmReply(), "SHM Reply");

    report(t_MsgIcdSha(), "SHA");
    report(t_MsgIcdShaReply(), "SHA Reply");

    report(t_MsgIcdCftBoth(), "CFT Both");
    report(t_MsgIcdCftBothReply(), "CFT Both Reply");

    report(t_MsgIcdCftUpper(), "CFT Upper");
    report(t_MsgIcdCftUpperReply(), "CFT Upper Reply");

    report(t_MsgIcdCftLower(), "CFT Lower");
    report(t_MsgIcdCftLowerReply(), "CFT Lower Reply");

    report(t_MsgIcdSapBoth(), "SAP Both");
    report(t_MsgIcdSapBothReply(), "SAP Both Reply");

    report(t_MsgIcdSapUpper(), "SAP Upper");
    report(t_MsgIcdSapUpperReply(), "SAP Upper Reply");

    report(t_MsgIcdSapLower(), "SAP Lower");
    report(t_MsgIcdSapLowerReply(), "SAP Lower Reply");

    report(t_MsgIcdPtsBoth(), "PTS Both");
    report(t_MsgIcdPtsBothReply(), "PTS Both Reply");

    report(t_MsgIcdPtsUpper(), "PTS Upper");
    report(t_MsgIcdPtsUpperReply(), "PTS Upper Reply");

    report(t_MsgIcdPtsLower(), "PTS Lower");
    report(t_MsgIcdPtsLowerReply(), "PTS Lower Reply");


    return 0;
}