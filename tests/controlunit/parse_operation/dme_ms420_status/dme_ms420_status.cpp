#include "dme_ms420_status.h"

namespace Test_ControlUnit {
    namespace ParseOperation {

        const char DME_MS420_Status::dme_status[] = {0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7d, 0x7c, 0x72, 0x6c, 0xb0, 0x00, 0x00, 0x1b, 0xfc, 0x90, 0x58, 0xa0, 0x78, 0x75, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0xb9};

        DME_MS420_Status::DME_MS420_Status()
        {
            using namespace DS2PlusPlus;
            packet = DS2PacketPtr(PACKET_FROM_CHARS(ControlUnit::addressForFamily("DME").first(), dme_status));
            ecu = ControlUnitPtr(new DS2PlusPlus::ControlUnit);
            ecu->loadByUuid("12000000-0001-0000-0000-000000000000");
            results = ecu->parseOperation("status", packet);
        }

        void DME_MS420_Status::oilTemp()
        {
            QString expectedValue = QString::number(42.755400);
            QString value = QString::number(results.value("temp.motor_oil").toDouble());
            QCOMPARE(value, expectedValue);
        }

        void DME_MS420_Status::coolantTemp()
        {
            QString expectedValue = QString::number(45.0);
            QString value = QString::number(results.value("temp.coolant").toDouble());
            QCOMPARE(value, expectedValue);
        }

        void DME_MS420_Status::intakeTemp()
        {
            QString expectedValue = QString::number(45.75);
            QString value = QString::number(results.value("temp.intake_air").toDouble());
            QCOMPARE(value, expectedValue);
        }

        void DME_MS420_Status::coolantOutletTemp()
        {
            QString expectedValue = QString::number(33.0);
            QString value = QString::number(results.value("temp.coolant_outlet").toDouble());
            QCOMPARE(value, expectedValue);
        }

        void DME_MS420_Status::ignitionAdvance()
        {
            QString expectedValue = QString::number(6.0);
            QString value = QString::number(results.value("ignition_deg_kw").toDouble());
            QCOMPARE(value, expectedValue);
        }

        void DME_MS420_Status::batteryVoltage()
        {
            QString expectedValue = QString::number(11.92932);
            QString value = QString::number(results.value("voltage.battery").toDouble());
            QCOMPARE(value, expectedValue);
        }

    }
}

int main(int argc, char** argv)
{
  Test_ControlUnit::ParseOperation::DME_MS420_Status tc;
  QTest::qExec(&tc, argc, argv);
  return 0;
}

