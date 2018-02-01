#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* block: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet);
/*  ==================================  */

/*  ==================================  */
  String loaderStatusDescription = _arkManager.loaderStatus().description();
    Serial.println("loaderStatusDescription: ");
    Serial.println(loaderStatusDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String loaderSyncDescription = _arkManager.loaderSync().description();
    Serial.println("loaderSyncDescription: ");
    Serial.println(loaderSyncDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String loaderAutoconfigureDescription = _arkManager.loaderAutoconfigure().description();
    Serial.println("loaderAutoconfigureDescription: ");
    Serial.println(loaderAutoconfigureDescription);
    Serial.println("\n=====\n");
    delay(50); 
/*  ==================================  */
}


/*  ==========================================================================  */
extern "C" {
#include "user_interface.h"
}
void reportFreeHeap() {
  Serial.print("\n\nsystem_get_free_heap_size: ");
  Serial.print(system_get_free_heap_size());
  Serial.println("\n\n");
};
/*  ==========================================================================  */


void check() {
  checkAPI();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}