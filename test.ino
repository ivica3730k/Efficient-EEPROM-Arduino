#include <AUnit.h>
#include "src/effiicentEEPROM.h"

test(eeprom_write_and_read)
{
    String a = "test here";
    char buffer[20];
    a.toCharArray(buffer, 20);
    Serial.println("Writing to mem");
    writeEEPROM(0, buffer, 20);
    char read_buffer[20];
    Serial.println("Reading from mem");
    readEEPROM(0, read_buffer, 20);
    String b(read_buffer);
    assertEqual(a, b);
}

void setup()
{
    delay(2000);
    Serial.begin(115200);
    while (!Serial)
    {
        /* code */
    }

    Serial.println("Starting tests!\n\n");
}

void loop()
{
    aunit::TestRunner::run();
}