#include "ihka46_ident.h"

namespace Test_ControlUnit {
    namespace ParseOperation {

        const char IHKA46_Ident::ihka_ident[] = {0xA0, 0x84, 0x10, 0x69, 0x30, 0x22, 0x03, 0x32, 0x0A, 0x26, 0x00, 0x03, 0x05};

        IHKA46_Ident::IHKA46_Ident()
        {
            using namespace DS2PlusPlus;
            packet = DS2PacketPtr(PACKET_FROM_CHARS(ControlUnit::addressForFamily("IHKA").first(), ihka_ident));
            json = ControlUnitPtr(new DS2PlusPlus::ControlUnit);
            json->loadByUuid("5B000000-0001-0000-0000-000000000000");
            results = json->parseOperation("identify", packet);
        }

        #if 0
        void IHKA46_Ident::initTestCase()
        {
        }

        void IHKA46_Ident::cleanupTestCase()
        {
        }
        #endif

        void IHKA46_Ident::partNumber()
        {
            QVariant expectedValue((quint64)4106930);
            QCOMPARE(results.value("part_number"), expectedValue);
        }

        void IHKA46_Ident::hardwareNumber()
        {
            QVariant expectedValue(QString("0x22"));
            QCOMPARE(results.value("hardware_number"), expectedValue);
        }

        void IHKA46_Ident::codingIndex()
        {
            QVariant expectedValue(QString("0x03"));
            QCOMPARE(results.value("coding_index"), expectedValue);
        }

        void IHKA46_Ident::diagIndex()
        {
            QVariant expectedValue(QString("0x32"));
            QCOMPARE(results.value("diag_index"), expectedValue);
        }

        void IHKA46_Ident::busIndex()
        {
            QVariant expectedValue(QString("0x00"));
            QCOMPARE(results.value("bus_index"), expectedValue);
        }

        void IHKA46_Ident::mfrWeek()
        {
            QVariant expectedValue((quint8)26);
            QCOMPARE(results.value("build_date.week"), expectedValue);
        }

        void IHKA46_Ident::mfrYear()
        {
            QVariant expectedValue((quint8)0);
            QCOMPARE(results.value("build_date.year"), expectedValue);
        }

        void IHKA46_Ident::supplier()
        {
            QVariant expectedValue(QString("Hella"));
            QCOMPARE(results.value("supplier"), expectedValue);
        }

        void IHKA46_Ident::softwareNumber()
        {
            QVariant expectedValue(QString("0x05"));
            QCOMPARE(results.value("software_number"), expectedValue);
        }
    }
}

int main(int argc, char** argv)
{
  Test_ControlUnit::ParseOperation::IHKA46_Ident tc;
  QTest::qExec(&tc, argc, argv);
  return 0;
}
